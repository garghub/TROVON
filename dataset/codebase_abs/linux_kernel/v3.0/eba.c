static unsigned long long F_1 ( struct V_1 * V_2 )
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
static struct V_9 * F_5 ( struct V_1 * V_2 , int V_6 ,
int V_10 )
{
struct V_11 * V_12 ;
V_12 = V_2 -> V_13 . V_11 ;
while ( V_12 ) {
struct V_9 * V_14 ;
V_14 = F_6 ( V_12 , struct V_9 , V_15 ) ;
if ( V_6 < V_14 -> V_6 )
V_12 = V_12 -> V_16 ;
else if ( V_6 > V_14 -> V_6 )
V_12 = V_12 -> V_17 ;
else {
if ( V_10 < V_14 -> V_10 )
V_12 = V_12 -> V_16 ;
else if ( V_10 > V_14 -> V_10 )
V_12 = V_12 -> V_17 ;
else
return V_14 ;
}
}
return NULL ;
}
static struct V_9 * F_7 ( struct V_1 * V_2 ,
int V_6 , int V_10 )
{
struct V_9 * V_14 , * V_18 , * V_19 ;
V_14 = F_8 ( sizeof( struct V_9 ) , V_20 ) ;
if ( ! V_14 )
return F_9 ( - V_21 ) ;
V_14 -> V_22 = 0 ;
F_10 ( & V_14 -> V_23 ) ;
V_14 -> V_6 = V_6 ;
V_14 -> V_10 = V_10 ;
F_2 ( & V_2 -> V_4 ) ;
V_18 = F_5 ( V_2 , V_6 , V_10 ) ;
if ( V_18 ) {
V_19 = V_14 ;
V_14 = V_18 ;
} else {
struct V_11 * * V_12 , * V_24 = NULL ;
V_19 = NULL ;
V_12 = & V_2 -> V_13 . V_11 ;
while ( * V_12 ) {
V_24 = * V_12 ;
V_18 = F_6 ( V_24 , struct V_9 , V_15 ) ;
if ( V_6 < V_18 -> V_6 )
V_12 = & ( * V_12 ) -> V_16 ;
else if ( V_6 > V_18 -> V_6 )
V_12 = & ( * V_12 ) -> V_17 ;
else {
F_11 ( V_10 != V_18 -> V_10 ) ;
if ( V_10 < V_18 -> V_10 )
V_12 = & ( * V_12 ) -> V_16 ;
else
V_12 = & ( * V_12 ) -> V_17 ;
}
}
F_12 ( & V_14 -> V_15 , V_24 , V_12 ) ;
F_13 ( & V_14 -> V_15 , & V_2 -> V_13 ) ;
}
V_14 -> V_22 += 1 ;
F_3 ( & V_2 -> V_4 ) ;
F_14 ( V_19 ) ;
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
struct V_9 * V_14 ;
V_14 = F_7 ( V_2 , V_6 , V_10 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_18 ( & V_14 -> V_23 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
struct V_9 * V_14 ;
F_2 ( & V_2 -> V_4 ) ;
V_14 = F_5 ( V_2 , V_6 , V_10 ) ;
V_14 -> V_22 -= 1 ;
F_11 ( V_14 -> V_22 >= 0 ) ;
F_20 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == 0 ) {
F_21 ( & V_14 -> V_15 , & V_2 -> V_13 ) ;
F_14 ( V_14 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
struct V_9 * V_14 ;
V_14 = F_7 ( V_2 , V_6 , V_10 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
F_23 ( & V_14 -> V_23 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
struct V_9 * V_14 ;
V_14 = F_7 ( V_2 , V_6 , V_10 ) ;
if ( F_16 ( V_14 ) )
return F_17 ( V_14 ) ;
if ( F_25 ( & V_14 -> V_23 ) )
return 0 ;
F_2 ( & V_2 -> V_4 ) ;
V_14 -> V_22 -= 1 ;
F_11 ( V_14 -> V_22 >= 0 ) ;
if ( V_14 -> V_22 == 0 ) {
F_21 ( & V_14 -> V_15 , & V_2 -> V_13 ) ;
F_14 ( V_14 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
return 1 ;
}
static void F_26 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
struct V_9 * V_14 ;
F_2 ( & V_2 -> V_4 ) ;
V_14 = F_5 ( V_2 , V_6 , V_10 ) ;
V_14 -> V_22 -= 1 ;
F_11 ( V_14 -> V_22 >= 0 ) ;
F_27 ( & V_14 -> V_23 ) ;
if ( V_14 -> V_22 == 0 ) {
F_21 ( & V_14 -> V_15 , & V_2 -> V_13 ) ;
F_14 ( V_14 ) ;
}
F_3 ( & V_2 -> V_4 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_10 )
{
int V_27 , V_28 , V_6 = V_26 -> V_6 ;
if ( V_2 -> V_29 )
return - V_30 ;
V_27 = F_22 ( V_2 , V_6 , V_10 ) ;
if ( V_27 )
return V_27 ;
V_28 = V_26 -> V_31 [ V_10 ] ;
if ( V_28 < 0 )
goto V_32;
F_29 ( L_1 , V_6 , V_10 , V_28 ) ;
V_26 -> V_31 [ V_10 ] = V_33 ;
V_27 = F_30 ( V_2 , V_28 , 0 ) ;
V_32:
F_26 ( V_2 , V_6 , V_10 ) ;
return V_27 ;
}
int F_31 ( struct V_1 * V_2 , struct V_25 * V_26 , int V_10 ,
void * V_34 , int V_35 , int V_36 , int V_37 )
{
int V_27 , V_28 , V_38 = 0 , V_6 = V_26 -> V_6 ;
struct V_39 * V_40 ;
T_1 V_41 ( V_42 ) ;
V_27 = F_15 ( V_2 , V_6 , V_10 ) ;
if ( V_27 )
return V_27 ;
V_28 = V_26 -> V_31 [ V_10 ] ;
if ( V_28 < 0 ) {
F_29 ( L_2 ,
V_36 , V_35 , V_6 , V_10 ) ;
F_19 ( V_2 , V_6 , V_10 ) ;
F_11 ( V_26 -> V_43 != V_44 ) ;
memset ( V_34 , 0xFF , V_36 ) ;
return 0 ;
}
F_29 ( L_3 ,
V_36 , V_35 , V_6 , V_10 , V_28 ) ;
if ( V_26 -> V_43 == V_45 )
V_37 = 0 ;
V_46:
if ( V_37 ) {
V_40 = F_32 ( V_2 , V_20 ) ;
if ( ! V_40 ) {
V_27 = - V_21 ;
goto V_32;
}
V_27 = F_33 ( V_2 , V_28 , V_40 , 1 ) ;
if ( V_27 && V_27 != V_47 ) {
if ( V_27 > 0 ) {
if ( V_27 == V_48 ||
V_27 == V_49 ) {
F_34 ( L_4
L_5 , V_28 , V_6 ,
V_10 ) ;
V_27 = - V_50 ;
} else
F_35 ( V_2 ) ;
}
goto V_51;
} else if ( V_27 == V_47 )
V_38 = 1 ;
F_11 ( V_10 < F_36 ( V_40 -> V_52 ) ) ;
F_11 ( V_36 == F_36 ( V_40 -> V_53 ) ) ;
V_42 = F_36 ( V_40 -> V_54 ) ;
F_37 ( V_2 , V_40 ) ;
}
V_27 = F_38 ( V_2 , V_34 , V_28 , V_35 , V_36 ) ;
if ( V_27 ) {
if ( V_27 == V_47 ) {
V_38 = 1 ;
V_27 = 0 ;
} else if ( V_27 == - V_50 ) {
if ( V_26 -> V_43 == V_45 )
goto V_32;
V_38 = 1 ;
if ( ! V_37 ) {
F_39 ( L_6 ) ;
V_37 = 1 ;
goto V_46;
}
} else
goto V_32;
}
if ( V_37 ) {
T_1 V_55 = F_40 ( V_56 , V_34 , V_36 ) ;
if ( V_55 != V_42 ) {
F_34 ( L_7 ,
V_55 , V_42 ) ;
V_27 = - V_50 ;
goto V_32;
}
}
if ( V_38 )
V_27 = F_41 ( V_2 , V_28 ) ;
F_19 ( V_2 , V_6 , V_10 ) ;
return V_27 ;
V_51:
F_37 ( V_2 , V_40 ) ;
V_32:
F_19 ( V_2 , V_6 , V_10 ) ;
return V_27 ;
}
static int F_42 ( struct V_1 * V_2 , int V_28 , int V_6 , int V_10 ,
const void * V_34 , int V_35 , int V_36 )
{
int V_27 , V_57 = F_43 ( V_2 , V_6 ) , V_58 , V_53 , V_59 = 0 ;
struct V_25 * V_26 = V_2 -> V_60 [ V_57 ] ;
struct V_39 * V_40 ;
V_40 = F_32 ( V_2 , V_20 ) ;
if ( ! V_40 )
return - V_21 ;
V_46:
V_58 = F_44 ( V_2 , V_61 ) ;
if ( V_58 < 0 ) {
F_37 ( V_2 , V_40 ) ;
return V_58 ;
}
F_39 ( L_8 , V_28 , V_58 ) ;
V_27 = F_33 ( V_2 , V_28 , V_40 , 1 ) ;
if ( V_27 && V_27 != V_47 ) {
if ( V_27 > 0 )
V_27 = - V_62 ;
goto V_63;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
V_27 = F_46 ( V_2 , V_58 , V_40 ) ;
if ( V_27 )
goto V_64;
V_53 = V_35 + V_36 ;
F_47 ( & V_2 -> V_65 ) ;
memset ( V_2 -> V_66 + V_35 , 0xFF , V_36 ) ;
if ( V_35 > 0 ) {
V_27 = F_38 ( V_2 , V_2 -> V_66 , V_28 , 0 , V_35 ) ;
if ( V_27 && V_27 != V_47 )
goto V_32;
}
memcpy ( V_2 -> V_66 + V_35 , V_34 , V_36 ) ;
V_27 = F_48 ( V_2 , V_2 -> V_66 , V_58 , 0 , V_53 ) ;
if ( V_27 ) {
F_49 ( & V_2 -> V_65 ) ;
goto V_64;
}
F_49 ( & V_2 -> V_65 ) ;
F_37 ( V_2 , V_40 ) ;
V_26 -> V_31 [ V_10 ] = V_58 ;
F_30 ( V_2 , V_28 , 1 ) ;
F_39 ( L_9 ) ;
return 0 ;
V_32:
F_49 ( & V_2 -> V_65 ) ;
V_63:
F_30 ( V_2 , V_58 , 1 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
V_64:
F_34 ( L_10 , V_58 ) ;
F_30 ( V_2 , V_58 , 1 ) ;
if ( ++ V_59 > V_67 ) {
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
F_39 ( L_11 ) ;
goto V_46;
}
int F_50 ( struct V_1 * V_2 , struct V_25 * V_26 , int V_10 ,
const void * V_34 , int V_35 , int V_36 , int V_68 )
{
int V_27 , V_28 , V_59 = 0 , V_6 = V_26 -> V_6 ;
struct V_39 * V_40 ;
if ( V_2 -> V_29 )
return - V_30 ;
V_27 = F_22 ( V_2 , V_6 , V_10 ) ;
if ( V_27 )
return V_27 ;
V_28 = V_26 -> V_31 [ V_10 ] ;
if ( V_28 >= 0 ) {
F_29 ( L_12 ,
V_36 , V_35 , V_6 , V_10 , V_28 ) ;
V_27 = F_48 ( V_2 , V_34 , V_28 , V_35 , V_36 ) ;
if ( V_27 ) {
F_34 ( L_13 , V_28 ) ;
if ( V_27 == - V_62 && V_2 -> V_69 )
V_27 = F_42 ( V_2 , V_28 , V_6 , V_10 , V_34 ,
V_35 , V_36 ) ;
if ( V_27 )
F_35 ( V_2 ) ;
}
F_26 ( V_2 , V_6 , V_10 ) ;
return V_27 ;
}
V_40 = F_32 ( V_2 , V_20 ) ;
if ( ! V_40 ) {
F_26 ( V_2 , V_6 , V_10 ) ;
return - V_21 ;
}
V_40 -> V_43 = V_70 ;
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
V_40 -> V_6 = F_51 ( V_6 ) ;
V_40 -> V_10 = F_51 ( V_10 ) ;
V_40 -> V_71 = F_4 ( V_2 , V_6 ) ;
V_40 -> V_72 = F_51 ( V_26 -> V_72 ) ;
V_46:
V_28 = F_44 ( V_2 , V_68 ) ;
if ( V_28 < 0 ) {
F_37 ( V_2 , V_40 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
return V_28 ;
}
F_29 ( L_14 ,
V_36 , V_35 , V_6 , V_10 , V_28 ) ;
V_27 = F_46 ( V_2 , V_28 , V_40 ) ;
if ( V_27 ) {
F_34 ( L_15 ,
V_6 , V_10 , V_28 ) ;
goto V_64;
}
if ( V_36 ) {
V_27 = F_48 ( V_2 , V_34 , V_28 , V_35 , V_36 ) ;
if ( V_27 ) {
F_34 ( L_16
L_17 , V_36 , V_35 , V_6 ,
V_10 , V_28 ) ;
goto V_64;
}
}
V_26 -> V_31 [ V_10 ] = V_28 ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return 0 ;
V_64:
if ( V_27 != - V_62 || ! V_2 -> V_69 ) {
F_35 ( V_2 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
V_27 = F_30 ( V_2 , V_28 , 1 ) ;
if ( V_27 || ++ V_59 > V_67 ) {
F_35 ( V_2 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
F_39 ( L_18 ) ;
goto V_46;
}
int F_52 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_10 , const void * V_34 , int V_36 , int V_68 ,
int V_52 )
{
int V_27 , V_28 , V_59 = 0 , V_53 = V_36 , V_6 = V_26 -> V_6 ;
struct V_39 * V_40 ;
T_1 V_42 ;
if ( V_2 -> V_29 )
return - V_30 ;
if ( V_10 == V_52 - 1 )
V_36 = F_53 ( V_53 , V_2 -> V_73 ) ;
else
F_11 ( ! ( V_36 & ( V_2 -> V_73 - 1 ) ) ) ;
V_40 = F_32 ( V_2 , V_20 ) ;
if ( ! V_40 )
return - V_21 ;
V_27 = F_22 ( V_2 , V_6 , V_10 ) ;
if ( V_27 ) {
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
V_40 -> V_6 = F_51 ( V_6 ) ;
V_40 -> V_10 = F_51 ( V_10 ) ;
V_40 -> V_71 = F_4 ( V_2 , V_6 ) ;
V_40 -> V_72 = F_51 ( V_26 -> V_72 ) ;
V_42 = F_40 ( V_56 , V_34 , V_53 ) ;
V_40 -> V_43 = V_74 ;
V_40 -> V_53 = F_51 ( V_53 ) ;
V_40 -> V_52 = F_51 ( V_52 ) ;
V_40 -> V_54 = F_51 ( V_42 ) ;
V_46:
V_28 = F_44 ( V_2 , V_68 ) ;
if ( V_28 < 0 ) {
F_37 ( V_2 , V_40 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
return V_28 ;
}
F_29 ( L_19 ,
V_36 , V_6 , V_10 , V_28 , V_52 ) ;
V_27 = F_46 ( V_2 , V_28 , V_40 ) ;
if ( V_27 ) {
F_34 ( L_15 ,
V_6 , V_10 , V_28 ) ;
goto V_64;
}
V_27 = F_48 ( V_2 , V_34 , V_28 , 0 , V_36 ) ;
if ( V_27 ) {
F_34 ( L_20 ,
V_36 , V_28 ) ;
goto V_64;
}
F_11 ( V_26 -> V_31 [ V_10 ] < 0 ) ;
V_26 -> V_31 [ V_10 ] = V_28 ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return 0 ;
V_64:
if ( V_27 != - V_62 || ! V_2 -> V_69 ) {
F_35 ( V_2 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
V_27 = F_30 ( V_2 , V_28 , 1 ) ;
if ( V_27 || ++ V_59 > V_67 ) {
F_35 ( V_2 ) ;
F_26 ( V_2 , V_6 , V_10 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
F_39 ( L_18 ) ;
goto V_46;
}
int F_54 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_10 , const void * V_34 , int V_36 , int V_68 )
{
int V_27 , V_28 , V_59 = 0 , V_6 = V_26 -> V_6 ;
struct V_39 * V_40 ;
T_1 V_42 ;
if ( V_2 -> V_29 )
return - V_30 ;
if ( V_36 == 0 ) {
V_27 = F_28 ( V_2 , V_26 , V_10 ) ;
if ( V_27 )
return V_27 ;
return F_50 ( V_2 , V_26 , V_10 , NULL , 0 , 0 , V_68 ) ;
}
V_40 = F_32 ( V_2 , V_20 ) ;
if ( ! V_40 )
return - V_21 ;
F_47 ( & V_2 -> V_75 ) ;
V_27 = F_22 ( V_2 , V_6 , V_10 ) ;
if ( V_27 )
goto V_76;
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
V_40 -> V_6 = F_51 ( V_6 ) ;
V_40 -> V_10 = F_51 ( V_10 ) ;
V_40 -> V_71 = F_4 ( V_2 , V_6 ) ;
V_40 -> V_72 = F_51 ( V_26 -> V_72 ) ;
V_42 = F_40 ( V_56 , V_34 , V_36 ) ;
V_40 -> V_43 = V_70 ;
V_40 -> V_53 = F_51 ( V_36 ) ;
V_40 -> V_77 = 1 ;
V_40 -> V_54 = F_51 ( V_42 ) ;
V_46:
V_28 = F_44 ( V_2 , V_68 ) ;
if ( V_28 < 0 ) {
V_27 = V_28 ;
goto V_78;
}
F_29 ( L_21 ,
V_6 , V_10 , V_26 -> V_31 [ V_10 ] , V_28 ) ;
V_27 = F_46 ( V_2 , V_28 , V_40 ) ;
if ( V_27 ) {
F_34 ( L_15 ,
V_6 , V_10 , V_28 ) ;
goto V_64;
}
V_27 = F_48 ( V_2 , V_34 , V_28 , 0 , V_36 ) ;
if ( V_27 ) {
F_34 ( L_20 ,
V_36 , V_28 ) ;
goto V_64;
}
if ( V_26 -> V_31 [ V_10 ] >= 0 ) {
V_27 = F_30 ( V_2 , V_26 -> V_31 [ V_10 ] , 0 ) ;
if ( V_27 )
goto V_78;
}
V_26 -> V_31 [ V_10 ] = V_28 ;
V_78:
F_26 ( V_2 , V_6 , V_10 ) ;
V_76:
F_49 ( & V_2 -> V_75 ) ;
F_37 ( V_2 , V_40 ) ;
return V_27 ;
V_64:
if ( V_27 != - V_62 || ! V_2 -> V_69 ) {
F_35 ( V_2 ) ;
goto V_78;
}
V_27 = F_30 ( V_2 , V_28 , 1 ) ;
if ( V_27 || ++ V_59 > V_67 ) {
F_35 ( V_2 ) ;
goto V_78;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
F_39 ( L_18 ) ;
goto V_46;
}
static int F_55 ( int V_27 )
{
if ( V_27 == - V_62 || V_27 == - V_21 || V_27 == V_49 ||
V_27 == V_48 || V_27 == - V_79 )
return 0 ;
return 1 ;
}
int F_56 ( struct V_1 * V_2 , int V_80 , int V_81 ,
struct V_39 * V_40 )
{
int V_27 , V_6 , V_10 , V_53 , V_82 , V_57 ;
struct V_25 * V_26 ;
T_1 V_42 ;
V_6 = F_36 ( V_40 -> V_6 ) ;
V_10 = F_36 ( V_40 -> V_10 ) ;
F_57 ( L_22 , V_6 , V_10 , V_80 , V_81 ) ;
if ( V_40 -> V_43 == V_74 ) {
V_53 = F_36 ( V_40 -> V_53 ) ;
V_82 = F_53 ( V_53 , V_2 -> V_73 ) ;
} else
V_53 = V_82 =
V_2 -> V_83 - F_36 ( V_40 -> V_72 ) ;
V_57 = F_43 ( V_2 , V_6 ) ;
F_2 ( & V_2 -> V_84 ) ;
V_26 = V_2 -> V_60 [ V_57 ] ;
F_3 ( & V_2 -> V_84 ) ;
if ( ! V_26 ) {
F_57 ( L_23 , V_6 ) ;
return V_85 ;
}
V_27 = F_24 ( V_2 , V_6 , V_10 ) ;
if ( V_27 ) {
F_57 ( L_24 , V_6 , V_10 ) ;
return V_85 ;
}
if ( V_26 -> V_31 [ V_10 ] != V_80 ) {
F_57 ( L_25
L_26 , V_6 , V_10 , V_80 ,
V_26 -> V_31 [ V_10 ] ) ;
V_27 = V_85 ;
goto V_86;
}
F_47 ( & V_2 -> V_65 ) ;
F_57 ( L_27 , V_82 ) ;
V_27 = F_38 ( V_2 , V_2 -> V_66 , V_80 , 0 , V_82 ) ;
if ( V_27 && V_27 != V_47 ) {
F_34 ( L_28 ,
V_27 , V_80 ) ;
V_27 = V_87 ;
goto V_88;
}
if ( V_40 -> V_43 == V_70 )
V_82 = V_53 =
F_58 ( V_2 , V_2 -> V_66 , V_53 ) ;
F_59 () ;
V_42 = F_40 ( V_56 , V_2 -> V_66 , V_53 ) ;
F_59 () ;
if ( V_53 > 0 ) {
V_40 -> V_77 = 1 ;
V_40 -> V_53 = F_51 ( V_53 ) ;
V_40 -> V_54 = F_51 ( V_42 ) ;
}
V_40 -> V_3 = F_45 ( F_1 ( V_2 ) ) ;
V_27 = F_46 ( V_2 , V_81 , V_40 ) ;
if ( V_27 ) {
if ( V_27 == - V_62 )
V_27 = V_89 ;
goto V_88;
}
F_59 () ;
V_27 = F_33 ( V_2 , V_81 , V_40 , 1 ) ;
if ( V_27 ) {
if ( V_27 != V_47 ) {
F_34 ( L_29
L_30 , V_27 , V_81 ) ;
if ( F_55 ( V_27 ) )
V_27 = V_90 ;
} else
V_27 = V_91 ;
goto V_88;
}
if ( V_53 > 0 ) {
V_27 = F_48 ( V_2 , V_2 -> V_66 , V_81 , 0 , V_82 ) ;
if ( V_27 ) {
if ( V_27 == - V_62 )
V_27 = V_89 ;
goto V_88;
}
F_59 () ;
V_27 = F_38 ( V_2 , V_2 -> V_92 , V_81 , 0 , V_82 ) ;
if ( V_27 ) {
if ( V_27 != V_47 ) {
F_34 ( L_31
L_32 , V_27 , V_81 ) ;
if ( F_55 ( V_27 ) )
V_27 = V_90 ;
} else
V_27 = V_91 ;
goto V_88;
}
F_59 () ;
if ( memcmp ( V_2 -> V_66 , V_2 -> V_92 , V_82 ) ) {
F_34 ( L_33
L_34 , V_81 ) ;
V_27 = - V_93 ;
goto V_88;
}
}
F_11 ( V_26 -> V_31 [ V_10 ] == V_80 ) ;
V_26 -> V_31 [ V_10 ] = V_81 ;
V_88:
F_49 ( & V_2 -> V_65 ) ;
V_86:
F_26 ( V_2 , V_6 , V_10 ) ;
return V_27 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 > ( 1 << 18 ) ) {
int V_97 = V_2 -> V_98 / 10 ;
if ( ! V_97 )
V_97 = 1 ;
if ( V_2 -> V_99 > V_97 )
return;
}
F_34 ( L_35
L_36 , V_2 -> V_99 , V_2 -> V_98 ) ;
if ( V_2 -> V_100 )
F_34 ( L_37 ,
V_2 -> V_100 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
int V_101 , V_102 , V_27 , V_103 ;
struct V_104 * V_105 ;
struct V_25 * V_26 ;
struct V_106 * V_107 ;
struct V_11 * V_15 ;
F_29 ( L_38 ) ;
F_62 ( & V_2 -> V_4 ) ;
F_63 ( & V_2 -> V_75 ) ;
V_2 -> V_13 = V_108 ;
V_2 -> V_5 = V_95 -> V_96 + 1 ;
V_103 = V_2 -> V_109 + V_110 ;
for ( V_101 = 0 ; V_101 < V_103 ; V_101 ++ ) {
V_26 = V_2 -> V_60 [ V_101 ] ;
if ( ! V_26 )
continue;
F_59 () ;
V_26 -> V_31 = F_8 ( V_26 -> V_111 * sizeof( int ) ,
V_112 ) ;
if ( ! V_26 -> V_31 ) {
V_27 = - V_21 ;
goto V_51;
}
for ( V_102 = 0 ; V_102 < V_26 -> V_111 ; V_102 ++ )
V_26 -> V_31 [ V_102 ] = V_33 ;
V_105 = F_64 ( V_95 , F_65 ( V_2 , V_101 ) ) ;
if ( ! V_105 )
continue;
F_66 (rb, seb, &sv->root, u.rb) {
if ( V_107 -> V_10 >= V_26 -> V_111 )
F_67 ( V_105 , V_107 , & V_95 -> V_113 ) ;
V_26 -> V_31 [ V_107 -> V_10 ] = V_107 -> V_28 ;
}
}
if ( V_2 -> V_114 < V_115 ) {
F_68 ( L_39 ,
V_2 -> V_114 , V_115 ) ;
if ( V_2 -> V_100 )
F_68 ( L_37 ,
V_2 -> V_100 ) ;
V_27 = - V_116 ;
goto V_51;
}
V_2 -> V_114 -= V_115 ;
V_2 -> V_117 += V_115 ;
if ( V_2 -> V_69 ) {
F_69 ( V_2 ) ;
if ( V_2 -> V_114 < V_2 -> V_98 ) {
V_2 -> V_99 = V_2 -> V_114 ;
F_60 ( V_2 , V_95 ) ;
} else
V_2 -> V_99 = V_2 -> V_98 ;
V_2 -> V_114 -= V_2 -> V_99 ;
V_2 -> V_117 += V_2 -> V_99 ;
}
F_29 ( L_40 ) ;
return 0 ;
V_51:
for ( V_101 = 0 ; V_101 < V_103 ; V_101 ++ ) {
if ( ! V_2 -> V_60 [ V_101 ] )
continue;
F_14 ( V_2 -> V_60 [ V_101 ] -> V_31 ) ;
V_2 -> V_60 [ V_101 ] -> V_31 = NULL ;
}
return V_27 ;
}
