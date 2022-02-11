unsigned long long F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = V_2 -> V_5 ++ ;
F_3 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_4 ( const struct V_1 * V_2 , int V_6 )
{
if ( V_6 == V_7 )
return V_8 ;
return 0 ;
}
void F_5 ( struct V_9 * V_10 , int V_11 ,
struct V_12 * V_13 )
{
V_13 -> V_11 = V_11 ;
V_13 -> V_14 = V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ;
}
struct V_17 * F_6 ( struct V_9 * V_10 ,
int V_18 )
{
struct V_17 * V_19 ;
int V_20 = - V_21 ;
int V_22 ;
V_19 = F_7 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return F_8 ( - V_21 ) ;
V_19 -> V_16 = F_9 ( V_18 , sizeof( * V_19 -> V_16 ) ,
V_23 ) ;
if ( ! V_19 -> V_16 )
goto V_20;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ )
V_19 -> V_16 [ V_22 ] . V_14 = V_24 ;
return V_19 ;
V_20:
F_10 ( V_19 -> V_16 ) ;
F_10 ( V_19 ) ;
return F_8 ( V_20 ) ;
}
void F_11 ( struct V_17 * V_19 )
{
if ( ! V_19 )
return;
F_10 ( V_19 -> V_16 ) ;
F_10 ( V_19 ) ;
}
void F_12 ( struct V_9 * V_10 , struct V_17 * V_25 ,
int V_18 )
{
struct V_17 * V_26 ;
int V_22 ;
F_13 ( V_25 && V_10 && V_10 -> V_15 ) ;
V_26 = V_10 -> V_15 ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ )
V_25 -> V_16 [ V_22 ] . V_14 = V_26 -> V_16 [ V_22 ] . V_14 ;
}
void F_14 ( struct V_9 * V_10 , struct V_17 * V_19 )
{
F_11 ( V_10 -> V_15 ) ;
V_10 -> V_15 = V_19 ;
}
static struct V_27 * F_15 ( struct V_1 * V_2 , int V_6 ,
int V_11 )
{
struct V_28 * V_29 ;
V_29 = V_2 -> V_30 . V_28 ;
while ( V_29 ) {
struct V_27 * V_31 ;
V_31 = F_16 ( V_29 , struct V_27 , V_32 ) ;
if ( V_6 < V_31 -> V_6 )
V_29 = V_29 -> V_33 ;
else if ( V_6 > V_31 -> V_6 )
V_29 = V_29 -> V_34 ;
else {
if ( V_11 < V_31 -> V_11 )
V_29 = V_29 -> V_33 ;
else if ( V_11 > V_31 -> V_11 )
V_29 = V_29 -> V_34 ;
else
return V_31 ;
}
}
return NULL ;
}
static struct V_27 * F_17 ( struct V_1 * V_2 ,
int V_6 , int V_11 )
{
struct V_27 * V_31 , * V_35 , * V_36 ;
V_31 = F_18 ( sizeof( struct V_27 ) , V_37 ) ;
if ( ! V_31 )
return F_8 ( - V_21 ) ;
V_31 -> V_38 = 0 ;
F_19 ( & V_31 -> V_39 ) ;
V_31 -> V_6 = V_6 ;
V_31 -> V_11 = V_11 ;
F_2 ( & V_2 -> V_4 ) ;
V_35 = F_15 ( V_2 , V_6 , V_11 ) ;
if ( V_35 ) {
V_36 = V_31 ;
V_31 = V_35 ;
} else {
struct V_28 * * V_29 , * V_40 = NULL ;
V_36 = NULL ;
V_29 = & V_2 -> V_30 . V_28 ;
while ( * V_29 ) {
V_40 = * V_29 ;
V_35 = F_16 ( V_40 , struct V_27 , V_32 ) ;
if ( V_6 < V_35 -> V_6 )
V_29 = & ( * V_29 ) -> V_33 ;
else if ( V_6 > V_35 -> V_6 )
V_29 = & ( * V_29 ) -> V_34 ;
else {
F_13 ( V_11 != V_35 -> V_11 ) ;
if ( V_11 < V_35 -> V_11 )
V_29 = & ( * V_29 ) -> V_33 ;
else
V_29 = & ( * V_29 ) -> V_34 ;
}
}
F_20 ( & V_31 -> V_32 , V_40 , V_29 ) ;
F_21 ( & V_31 -> V_32 , & V_2 -> V_30 ) ;
}
V_31 -> V_38 += 1 ;
F_3 ( & V_2 -> V_4 ) ;
F_10 ( V_36 ) ;
return V_31 ;
}
static int F_22 ( struct V_1 * V_2 , int V_6 , int V_11 )
{
struct V_27 * V_31 ;
V_31 = F_17 ( V_2 , V_6 , V_11 ) ;
if ( F_23 ( V_31 ) )
return F_24 ( V_31 ) ;
F_25 ( & V_31 -> V_39 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , int V_6 , int V_11 )
{
struct V_27 * V_31 ;
F_2 ( & V_2 -> V_4 ) ;
V_31 = F_15 ( V_2 , V_6 , V_11 ) ;
V_31 -> V_38 -= 1 ;
F_13 ( V_31 -> V_38 >= 0 ) ;
F_27 ( & V_31 -> V_39 ) ;
if ( V_31 -> V_38 == 0 ) {
F_28 ( & V_31 -> V_32 , & V_2 -> V_30 ) ;
F_10 ( V_31 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_6 , int V_11 )
{
struct V_27 * V_31 ;
V_31 = F_17 ( V_2 , V_6 , V_11 ) ;
if ( F_23 ( V_31 ) )
return F_24 ( V_31 ) ;
F_30 ( & V_31 -> V_39 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_6 , int V_11 )
{
struct V_27 * V_31 ;
V_31 = F_17 ( V_2 , V_6 , V_11 ) ;
if ( F_23 ( V_31 ) )
return F_24 ( V_31 ) ;
if ( F_32 ( & V_31 -> V_39 ) )
return 0 ;
F_2 ( & V_2 -> V_4 ) ;
V_31 -> V_38 -= 1 ;
F_13 ( V_31 -> V_38 >= 0 ) ;
if ( V_31 -> V_38 == 0 ) {
F_28 ( & V_31 -> V_32 , & V_2 -> V_30 ) ;
F_10 ( V_31 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
return 1 ;
}
static void F_33 ( struct V_1 * V_2 , int V_6 , int V_11 )
{
struct V_27 * V_31 ;
F_2 ( & V_2 -> V_4 ) ;
V_31 = F_15 ( V_2 , V_6 , V_11 ) ;
V_31 -> V_38 -= 1 ;
F_13 ( V_31 -> V_38 >= 0 ) ;
F_34 ( & V_31 -> V_39 ) ;
if ( V_31 -> V_38 == 0 ) {
F_28 ( & V_31 -> V_32 , & V_2 -> V_30 ) ;
F_10 ( V_31 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
}
bool F_35 ( struct V_9 * V_10 , int V_11 )
{
return V_10 -> V_15 -> V_16 [ V_11 ] . V_14 >= 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 )
{
int V_20 , V_14 , V_6 = V_10 -> V_6 ;
if ( V_2 -> V_41 )
return - V_42 ;
V_20 = F_29 ( V_2 , V_6 , V_11 ) ;
if ( V_20 )
return V_20 ;
V_14 = V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ;
if ( V_14 < 0 )
goto V_43;
F_37 ( L_1 , V_6 , V_11 , V_14 ) ;
F_25 ( & V_2 -> V_44 ) ;
V_10 -> V_15 -> V_16 [ V_11 ] . V_14 = V_24 ;
F_27 ( & V_2 -> V_44 ) ;
V_20 = F_38 ( V_2 , V_6 , V_11 , V_14 , 0 ) ;
V_43:
F_33 ( V_2 , V_6 , V_11 ) ;
return V_20 ;
}
int F_39 ( struct V_1 * V_2 , struct V_9 * V_10 , int V_11 ,
void * V_45 , int V_46 , int V_47 , int V_48 )
{
int V_20 , V_14 , V_49 = 0 , V_6 = V_10 -> V_6 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_1 V_54 ( V_55 ) ;
V_20 = F_22 ( V_2 , V_6 , V_11 ) ;
if ( V_20 )
return V_20 ;
V_14 = V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ;
if ( V_14 < 0 ) {
F_37 ( L_2 ,
V_47 , V_46 , V_6 , V_11 ) ;
F_26 ( V_2 , V_6 , V_11 ) ;
F_13 ( V_10 -> V_56 != V_57 ) ;
memset ( V_45 , 0xFF , V_47 ) ;
return 0 ;
}
F_37 ( L_3 ,
V_47 , V_46 , V_6 , V_11 , V_14 ) ;
if ( V_10 -> V_56 == V_58 )
V_48 = 0 ;
V_59:
if ( V_48 ) {
V_51 = F_40 ( V_2 , V_37 ) ;
if ( ! V_51 ) {
V_20 = - V_21 ;
goto V_43;
}
V_53 = F_41 ( V_51 ) ;
V_20 = F_42 ( V_2 , V_14 , V_51 , 1 ) ;
if ( V_20 && V_20 != V_60 ) {
if ( V_20 > 0 ) {
if ( V_20 == V_61 ||
V_20 == V_62 ) {
F_43 ( V_2 , L_4 ,
V_14 , V_6 , V_11 ) ;
V_20 = - V_63 ;
} else {
if ( V_2 -> V_64 ) {
V_20 = - V_63 ;
} else {
V_20 = - V_65 ;
F_44 ( V_2 ) ;
}
}
}
goto V_66;
} else if ( V_20 == V_60 )
V_49 = 1 ;
F_13 ( V_11 < F_45 ( V_53 -> V_67 ) ) ;
F_13 ( V_47 == F_45 ( V_53 -> V_68 ) ) ;
V_55 = F_45 ( V_53 -> V_69 ) ;
F_46 ( V_51 ) ;
}
V_20 = F_47 ( V_2 , V_45 , V_14 , V_46 , V_47 ) ;
if ( V_20 ) {
if ( V_20 == V_60 )
V_49 = 1 ;
else if ( F_48 ( V_20 ) ) {
if ( V_10 -> V_56 == V_58 )
goto V_43;
V_49 = 1 ;
if ( ! V_48 ) {
F_49 ( V_2 , L_5 ) ;
V_48 = 1 ;
goto V_59;
}
} else
goto V_43;
}
if ( V_48 ) {
T_1 V_70 = F_50 ( V_71 , V_45 , V_47 ) ;
if ( V_70 != V_55 ) {
F_43 ( V_2 , L_6 ,
V_70 , V_55 ) ;
V_20 = - V_63 ;
goto V_43;
}
}
if ( V_49 )
V_20 = F_51 ( V_2 , V_14 ) ;
F_26 ( V_2 , V_6 , V_11 ) ;
return V_20 ;
V_66:
F_46 ( V_51 ) ;
V_43:
F_26 ( V_2 , V_6 , V_11 ) ;
return V_20 ;
}
int F_52 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_72 * V_73 , int V_11 , int V_46 , int V_47 ,
int V_48 )
{
int V_74 ;
int V_75 ;
struct V_76 * V_77 ;
for (; ; ) {
F_13 ( V_73 -> V_78 < V_79 ) ;
V_77 = & V_73 -> V_77 [ V_73 -> V_78 ] ;
if ( V_47 < V_77 -> V_80 - V_73 -> V_81 )
V_74 = V_47 ;
else
V_74 = V_77 -> V_80 - V_73 -> V_81 ;
V_75 = F_39 ( V_2 , V_10 , V_11 ,
F_53 ( V_77 ) + V_73 -> V_81 , V_46 ,
V_74 , V_48 ) ;
if ( V_75 < 0 )
return V_75 ;
V_46 += V_74 ;
V_47 -= V_74 ;
if ( ! V_47 ) {
V_73 -> V_81 += V_74 ;
if ( V_73 -> V_81 == V_77 -> V_80 ) {
V_73 -> V_78 ++ ;
V_73 -> V_81 = 0 ;
}
break;
}
V_73 -> V_78 ++ ;
V_73 -> V_81 = 0 ;
}
return V_75 ;
}
static int F_54 ( struct V_9 * V_10 , int V_14 , int V_11 ,
const void * V_45 , int V_46 , int V_47 ,
struct V_50 * V_51 , bool * V_59 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_52 * V_53 ;
int V_82 , V_20 , V_6 = V_10 -> V_6 , V_68 ;
T_1 V_55 ;
* V_59 = false ;
V_82 = F_55 ( V_2 ) ;
if ( V_82 < 0 ) {
V_20 = V_82 ;
goto V_83;
}
F_49 ( V_2 , L_7 ,
V_14 , V_82 ) ;
V_20 = F_42 ( V_2 , V_14 , V_51 , 1 ) ;
if ( V_20 && V_20 != V_60 ) {
if ( V_20 > 0 )
V_20 = - V_84 ;
goto V_83;
}
V_53 = F_41 ( V_51 ) ;
F_13 ( V_53 -> V_56 == V_85 ) ;
F_56 ( & V_2 -> V_86 ) ;
memset ( V_2 -> V_87 + V_46 , 0xFF , V_47 ) ;
if ( V_46 > 0 ) {
V_20 = F_47 ( V_2 , V_2 -> V_87 , V_14 , 0 , V_46 ) ;
if ( V_20 && V_20 != V_60 )
goto V_43;
}
* V_59 = true ;
memcpy ( V_2 -> V_87 + V_46 , V_45 , V_47 ) ;
V_68 = V_46 + V_47 ;
V_55 = F_50 ( V_71 , V_2 -> V_87 , V_68 ) ;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
V_53 -> V_88 = 1 ;
V_53 -> V_68 = F_58 ( V_68 ) ;
V_53 -> V_69 = F_58 ( V_55 ) ;
V_20 = F_59 ( V_2 , V_82 , V_51 ) ;
if ( V_20 )
goto V_43;
V_20 = F_60 ( V_2 , V_2 -> V_87 , V_82 , 0 , V_68 ) ;
V_43:
F_61 ( & V_2 -> V_86 ) ;
if ( ! V_20 )
V_10 -> V_15 -> V_16 [ V_11 ] . V_14 = V_82 ;
V_83:
F_27 ( & V_2 -> V_44 ) ;
if ( ! V_20 ) {
F_38 ( V_2 , V_6 , V_11 , V_14 , 1 ) ;
F_49 ( V_2 , L_8 ) ;
} else if ( V_82 >= 0 ) {
F_38 ( V_2 , V_6 , V_11 , V_82 , 1 ) ;
F_43 ( V_2 , L_9 , V_82 ) ;
}
return V_20 ;
}
static int F_62 ( struct V_1 * V_2 , int V_14 , int V_6 , int V_11 ,
const void * V_45 , int V_46 , int V_47 )
{
int V_20 , V_89 = F_63 ( V_2 , V_6 ) , V_90 ;
struct V_9 * V_10 = V_2 -> V_91 [ V_89 ] ;
struct V_50 * V_51 ;
V_51 = F_40 ( V_2 , V_37 ) ;
if ( ! V_51 )
return - V_21 ;
for ( V_90 = 0 ; V_90 <= V_92 ; V_90 ++ ) {
bool V_59 ;
V_20 = F_54 ( V_10 , V_14 , V_11 , V_45 , V_46 , V_47 , V_51 ,
& V_59 ) ;
if ( ! V_20 || ! V_59 )
break;
F_49 ( V_2 , L_10 ) ;
}
F_46 ( V_51 ) ;
return V_20 ;
}
static int F_64 ( struct V_9 * V_10 , int V_11 ,
struct V_50 * V_51 , const void * V_45 ,
int V_46 , int V_47 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 , V_93 , V_20 , V_6 = V_10 -> V_6 ;
V_14 = F_55 ( V_2 ) ;
if ( V_14 < 0 ) {
V_20 = V_14 ;
goto V_83;
}
V_93 = V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ;
F_37 ( L_11 ,
V_47 , V_46 , V_6 , V_11 , V_14 ) ;
V_20 = F_59 ( V_2 , V_14 , V_51 ) ;
if ( V_20 ) {
F_43 ( V_2 , L_12 ,
V_6 , V_11 , V_14 ) ;
goto V_83;
}
if ( V_47 ) {
V_20 = F_60 ( V_2 , V_45 , V_14 , V_46 , V_47 ) ;
if ( V_20 ) {
F_43 ( V_2 ,
L_13 ,
V_47 , V_46 , V_6 , V_11 , V_14 ) ;
goto V_83;
}
}
V_10 -> V_15 -> V_16 [ V_11 ] . V_14 = V_14 ;
V_83:
F_27 ( & V_2 -> V_44 ) ;
if ( V_20 && V_14 >= 0 )
V_20 = F_38 ( V_2 , V_6 , V_11 , V_14 , 1 ) ;
else if ( ! V_20 && V_93 >= 0 )
V_20 = F_38 ( V_2 , V_6 , V_11 , V_93 , 0 ) ;
return V_20 ;
}
int F_65 ( struct V_1 * V_2 , struct V_9 * V_10 , int V_11 ,
const void * V_45 , int V_46 , int V_47 )
{
int V_20 , V_14 , V_90 , V_6 = V_10 -> V_6 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
if ( V_2 -> V_41 )
return - V_42 ;
V_20 = F_29 ( V_2 , V_6 , V_11 ) ;
if ( V_20 )
return V_20 ;
V_14 = V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ;
if ( V_14 >= 0 ) {
F_37 ( L_14 ,
V_47 , V_46 , V_6 , V_11 , V_14 ) ;
V_20 = F_60 ( V_2 , V_45 , V_14 , V_46 , V_47 ) ;
if ( V_20 ) {
F_43 ( V_2 , L_15 , V_14 ) ;
if ( V_20 == - V_84 && V_2 -> V_94 )
V_20 = F_62 ( V_2 , V_14 , V_6 , V_11 , V_45 ,
V_46 , V_47 ) ;
}
goto V_95;
}
V_51 = F_40 ( V_2 , V_37 ) ;
if ( ! V_51 ) {
F_33 ( V_2 , V_6 , V_11 ) ;
return - V_21 ;
}
V_53 = F_41 ( V_51 ) ;
V_53 -> V_56 = V_85 ;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
V_53 -> V_6 = F_58 ( V_6 ) ;
V_53 -> V_11 = F_58 ( V_11 ) ;
V_53 -> V_96 = F_4 ( V_2 , V_6 ) ;
V_53 -> V_97 = F_58 ( V_10 -> V_97 ) ;
for ( V_90 = 0 ; V_90 <= V_92 ; V_90 ++ ) {
V_20 = F_64 ( V_10 , V_11 , V_51 , V_45 , V_46 , V_47 ) ;
if ( V_20 != - V_84 || ! V_2 -> V_94 )
break;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
F_49 ( V_2 , L_16 ) ;
}
F_46 ( V_51 ) ;
V_95:
if ( V_20 )
F_44 ( V_2 ) ;
F_33 ( V_2 , V_6 , V_11 ) ;
return V_20 ;
}
int F_66 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , const void * V_45 , int V_47 , int V_67 )
{
int V_20 , V_90 , V_68 = V_47 , V_6 = V_10 -> V_6 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_1 V_55 ;
if ( V_2 -> V_41 )
return - V_42 ;
if ( V_11 == V_67 - 1 )
V_47 = F_67 ( V_68 , V_2 -> V_98 ) ;
else
F_13 ( ! ( V_47 & ( V_2 -> V_98 - 1 ) ) ) ;
V_51 = F_40 ( V_2 , V_37 ) ;
if ( ! V_51 )
return - V_21 ;
V_53 = F_41 ( V_51 ) ;
V_20 = F_29 ( V_2 , V_6 , V_11 ) ;
if ( V_20 )
goto V_95;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
V_53 -> V_6 = F_58 ( V_6 ) ;
V_53 -> V_11 = F_58 ( V_11 ) ;
V_53 -> V_96 = F_4 ( V_2 , V_6 ) ;
V_53 -> V_97 = F_58 ( V_10 -> V_97 ) ;
V_55 = F_50 ( V_71 , V_45 , V_68 ) ;
V_53 -> V_56 = V_99 ;
V_53 -> V_68 = F_58 ( V_68 ) ;
V_53 -> V_67 = F_58 ( V_67 ) ;
V_53 -> V_69 = F_58 ( V_55 ) ;
F_13 ( V_10 -> V_15 -> V_16 [ V_11 ] . V_14 < 0 ) ;
for ( V_90 = 0 ; V_90 <= V_92 ; V_90 ++ ) {
V_20 = F_64 ( V_10 , V_11 , V_51 , V_45 , 0 , V_47 ) ;
if ( V_20 != - V_84 || ! V_2 -> V_94 )
break;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
F_49 ( V_2 , L_16 ) ;
}
if ( V_20 )
F_44 ( V_2 ) ;
F_33 ( V_2 , V_6 , V_11 ) ;
V_95:
F_46 ( V_51 ) ;
return V_20 ;
}
int F_68 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , const void * V_45 , int V_47 )
{
int V_20 , V_90 , V_6 = V_10 -> V_6 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_1 V_55 ;
if ( V_2 -> V_41 )
return - V_42 ;
if ( V_47 == 0 ) {
V_20 = F_36 ( V_2 , V_10 , V_11 ) ;
if ( V_20 )
return V_20 ;
return F_65 ( V_2 , V_10 , V_11 , NULL , 0 , 0 ) ;
}
V_51 = F_40 ( V_2 , V_37 ) ;
if ( ! V_51 )
return - V_21 ;
V_53 = F_41 ( V_51 ) ;
F_56 ( & V_2 -> V_100 ) ;
V_20 = F_29 ( V_2 , V_6 , V_11 ) ;
if ( V_20 )
goto V_101;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
V_53 -> V_6 = F_58 ( V_6 ) ;
V_53 -> V_11 = F_58 ( V_11 ) ;
V_53 -> V_96 = F_4 ( V_2 , V_6 ) ;
V_53 -> V_97 = F_58 ( V_10 -> V_97 ) ;
V_55 = F_50 ( V_71 , V_45 , V_47 ) ;
V_53 -> V_56 = V_85 ;
V_53 -> V_68 = F_58 ( V_47 ) ;
V_53 -> V_88 = 1 ;
V_53 -> V_69 = F_58 ( V_55 ) ;
F_37 ( L_17 , V_6 , V_11 ) ;
for ( V_90 = 0 ; V_90 <= V_92 ; V_90 ++ ) {
V_20 = F_64 ( V_10 , V_11 , V_51 , V_45 , 0 , V_47 ) ;
if ( V_20 != - V_84 || ! V_2 -> V_94 )
break;
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
F_49 ( V_2 , L_16 ) ;
}
if ( V_20 )
F_44 ( V_2 ) ;
F_33 ( V_2 , V_6 , V_11 ) ;
V_101:
F_61 ( & V_2 -> V_100 ) ;
F_46 ( V_51 ) ;
return V_20 ;
}
static int F_69 ( int V_20 )
{
if ( V_20 == - V_84 || V_20 == - V_21 || V_20 == V_62 ||
V_20 == V_61 || V_20 == - V_102 )
return 0 ;
return 1 ;
}
int F_70 ( struct V_1 * V_2 , int V_103 , int V_104 ,
struct V_50 * V_51 )
{
int V_20 , V_6 , V_11 , V_68 , V_105 , V_89 ;
struct V_52 * V_53 = F_41 ( V_51 ) ;
struct V_9 * V_10 ;
T_1 V_55 ;
F_13 ( F_71 ( & V_2 -> V_44 ) ) ;
V_6 = F_45 ( V_53 -> V_6 ) ;
V_11 = F_45 ( V_53 -> V_11 ) ;
F_72 ( L_18 , V_6 , V_11 , V_103 , V_104 ) ;
if ( V_53 -> V_56 == V_99 ) {
V_68 = F_45 ( V_53 -> V_68 ) ;
V_105 = F_67 ( V_68 , V_2 -> V_98 ) ;
} else
V_68 = V_105 =
V_2 -> V_106 - F_45 ( V_53 -> V_97 ) ;
V_89 = F_63 ( V_2 , V_6 ) ;
F_2 ( & V_2 -> V_107 ) ;
V_10 = V_2 -> V_91 [ V_89 ] ;
F_3 ( & V_2 -> V_107 ) ;
if ( ! V_10 ) {
F_72 ( L_19 , V_6 ) ;
return V_108 ;
}
V_20 = F_31 ( V_2 , V_6 , V_11 ) ;
if ( V_20 ) {
F_72 ( L_20 , V_6 , V_11 ) ;
return V_109 ;
}
if ( V_10 -> V_15 -> V_16 [ V_11 ] . V_14 != V_103 ) {
F_72 ( L_21 ,
V_6 , V_11 , V_103 , V_10 -> V_15 -> V_16 [ V_11 ] . V_14 ) ;
V_20 = V_108 ;
goto V_110;
}
F_56 ( & V_2 -> V_86 ) ;
F_72 ( L_22 , V_105 ) ;
V_20 = F_47 ( V_2 , V_2 -> V_87 , V_103 , 0 , V_105 ) ;
if ( V_20 && V_20 != V_60 ) {
F_43 ( V_2 , L_23 ,
V_20 , V_103 ) ;
V_20 = V_111 ;
goto V_112;
}
if ( V_53 -> V_56 == V_85 )
V_105 = V_68 =
F_73 ( V_2 , V_2 -> V_87 , V_68 ) ;
F_74 () ;
V_55 = F_50 ( V_71 , V_2 -> V_87 , V_68 ) ;
F_74 () ;
if ( V_68 > 0 ) {
V_53 -> V_88 = 1 ;
V_53 -> V_68 = F_58 ( V_68 ) ;
V_53 -> V_69 = F_58 ( V_55 ) ;
}
V_53 -> V_3 = F_57 ( F_1 ( V_2 ) ) ;
V_20 = F_59 ( V_2 , V_104 , V_51 ) ;
if ( V_20 ) {
if ( V_20 == - V_84 )
V_20 = V_113 ;
goto V_112;
}
F_74 () ;
V_20 = F_42 ( V_2 , V_104 , V_51 , 1 ) ;
if ( V_20 ) {
if ( V_20 != V_60 ) {
F_43 ( V_2 , L_24 ,
V_20 , V_104 ) ;
if ( F_69 ( V_20 ) )
V_20 = V_114 ;
} else
V_20 = V_115 ;
goto V_112;
}
if ( V_68 > 0 ) {
V_20 = F_60 ( V_2 , V_2 -> V_87 , V_104 , 0 , V_105 ) ;
if ( V_20 ) {
if ( V_20 == - V_84 )
V_20 = V_113 ;
goto V_112;
}
F_74 () ;
}
F_13 ( V_10 -> V_15 -> V_16 [ V_11 ] . V_14 == V_103 ) ;
V_10 -> V_15 -> V_16 [ V_11 ] . V_14 = V_104 ;
V_112:
F_61 ( & V_2 -> V_86 ) ;
V_110:
F_33 ( V_2 , V_6 , V_11 ) ;
return V_20 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_118 > ( 1 << 18 ) ) {
int V_119 = V_2 -> V_120 / 10 ;
if ( ! V_119 )
V_119 = 1 ;
if ( V_2 -> V_121 > V_119 )
return;
}
F_43 ( V_2 , L_25 ,
V_2 -> V_121 , V_2 -> V_120 ) ;
if ( V_2 -> V_122 )
F_43 ( V_2 , L_26 ,
V_2 -> V_122 ) ;
}
int F_76 ( struct V_1 * V_2 , struct V_116 * V_123 ,
struct V_116 * V_124 )
{
int V_22 , V_125 , V_126 , V_75 = 0 ;
int * * V_127 , * * V_128 ;
struct V_129 * V_130 ;
struct V_9 * V_10 ;
struct V_131 * V_132 ;
struct V_28 * V_32 ;
V_126 = V_2 -> V_133 + V_134 ;
V_127 = F_18 ( sizeof( * V_127 ) * V_126 , V_23 ) ;
if ( ! V_127 )
return - V_21 ;
V_128 = F_18 ( sizeof( * V_128 ) * V_126 , V_23 ) ;
if ( ! V_128 ) {
F_10 ( V_127 ) ;
return - V_21 ;
}
for ( V_22 = 0 ; V_22 < V_126 ; V_22 ++ ) {
V_10 = V_2 -> V_91 [ V_22 ] ;
if ( ! V_10 )
continue;
V_127 [ V_22 ] = F_18 ( V_10 -> V_135 * sizeof( * * V_127 ) ,
V_23 ) ;
if ( ! V_127 [ V_22 ] ) {
V_75 = - V_21 ;
goto V_66;
}
V_128 [ V_22 ] = F_18 ( V_10 -> V_135 * sizeof( * * V_128 ) ,
V_23 ) ;
if ( ! V_128 [ V_22 ] ) {
V_75 = - V_21 ;
goto V_66;
}
for ( V_125 = 0 ; V_125 < V_10 -> V_135 ; V_125 ++ )
V_127 [ V_22 ] [ V_125 ] = V_128 [ V_22 ] [ V_125 ] = V_24 ;
V_130 = F_77 ( V_124 , F_78 ( V_2 , V_22 ) ) ;
if ( ! V_130 )
continue;
F_79 (rb, aeb, &av->root, u.rb)
V_127 [ V_22 ] [ V_132 -> V_11 ] = V_132 -> V_14 ;
V_130 = F_77 ( V_123 , F_78 ( V_2 , V_22 ) ) ;
if ( ! V_130 )
continue;
F_79 (rb, aeb, &av->root, u.rb)
V_128 [ V_22 ] [ V_132 -> V_11 ] = V_132 -> V_14 ;
for ( V_125 = 0 ; V_125 < V_10 -> V_135 ; V_125 ++ ) {
if ( V_127 [ V_22 ] [ V_125 ] != V_128 [ V_22 ] [ V_125 ] ) {
if ( V_127 [ V_22 ] [ V_125 ] == V_24 ||
V_128 [ V_22 ] [ V_125 ] == V_24 )
continue;
F_80 ( V_2 , L_27 ,
V_10 -> V_6 , V_125 , V_128 [ V_22 ] [ V_125 ] ,
V_127 [ V_22 ] [ V_125 ] ) ;
F_13 ( 0 ) ;
}
}
}
V_66:
for ( V_22 = 0 ; V_22 < V_126 ; V_22 ++ ) {
if ( ! V_2 -> V_91 [ V_22 ] )
continue;
F_10 ( V_127 [ V_22 ] ) ;
F_10 ( V_128 [ V_22 ] ) ;
}
F_10 ( V_127 ) ;
F_10 ( V_128 ) ;
return V_75 ;
}
int F_81 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
int V_22 , V_20 , V_126 ;
struct V_129 * V_130 ;
struct V_9 * V_10 ;
struct V_131 * V_132 ;
struct V_28 * V_32 ;
F_37 ( L_28 ) ;
F_82 ( & V_2 -> V_4 ) ;
F_83 ( & V_2 -> V_100 ) ;
V_2 -> V_30 = V_136 ;
V_2 -> V_5 = V_117 -> V_118 + 1 ;
V_126 = V_2 -> V_133 + V_134 ;
for ( V_22 = 0 ; V_22 < V_126 ; V_22 ++ ) {
struct V_17 * V_19 ;
V_10 = V_2 -> V_91 [ V_22 ] ;
if ( ! V_10 )
continue;
F_74 () ;
V_19 = F_6 ( V_10 , V_10 -> V_135 ) ;
if ( F_23 ( V_19 ) ) {
V_20 = F_24 ( V_19 ) ;
goto V_66;
}
F_14 ( V_10 , V_19 ) ;
V_130 = F_77 ( V_117 , F_78 ( V_2 , V_22 ) ) ;
if ( ! V_130 )
continue;
F_79 (rb, aeb, &av->root, u.rb) {
if ( V_132 -> V_11 >= V_10 -> V_135 ) {
F_84 ( V_130 , V_132 , & V_117 -> V_137 ) ;
} else {
struct V_138 * V_139 ;
V_139 = & V_10 -> V_15 -> V_16 [ V_132 -> V_11 ] ;
V_139 -> V_14 = V_132 -> V_14 ;
}
}
}
if ( V_2 -> V_140 < V_141 ) {
F_80 ( V_2 , L_29 ,
V_2 -> V_140 , V_141 ) ;
if ( V_2 -> V_122 )
F_80 ( V_2 , L_26 ,
V_2 -> V_122 ) ;
V_20 = - V_142 ;
goto V_66;
}
V_2 -> V_140 -= V_141 ;
V_2 -> V_143 += V_141 ;
if ( V_2 -> V_94 ) {
F_85 ( V_2 ) ;
if ( V_2 -> V_140 < V_2 -> V_120 ) {
V_2 -> V_121 = V_2 -> V_140 ;
F_75 ( V_2 , V_117 ) ;
} else
V_2 -> V_121 = V_2 -> V_120 ;
V_2 -> V_140 -= V_2 -> V_121 ;
V_2 -> V_143 += V_2 -> V_121 ;
}
F_37 ( L_30 ) ;
return 0 ;
V_66:
for ( V_22 = 0 ; V_22 < V_126 ; V_22 ++ ) {
if ( ! V_2 -> V_91 [ V_22 ] )
continue;
F_14 ( V_2 -> V_91 [ V_22 ] , NULL ) ;
}
return V_20 ;
}
