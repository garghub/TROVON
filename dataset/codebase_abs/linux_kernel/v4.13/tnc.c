static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_8 * * V_9 , * V_10 = NULL ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_11 ) ;
if ( F_3 ( ! V_6 ) )
return - V_12 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_9 = & V_2 -> V_6 . V_8 ;
while ( * V_9 ) {
V_10 = * V_9 ;
V_7 = F_4 ( V_10 , struct V_5 , V_13 ) ;
if ( V_3 < V_7 -> V_3 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_3 > V_7 -> V_3 )
V_9 = & ( * V_9 ) -> V_15 ;
else if ( V_4 < V_7 -> V_4 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_4 > V_7 -> V_4 )
V_9 = & ( * V_9 ) -> V_15 ;
else {
F_5 ( V_2 , L_1 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
}
F_7 ( & V_6 -> V_13 , V_10 , V_9 ) ;
F_8 ( & V_6 -> V_13 , & V_2 -> V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_10 ) {
struct V_18 * V_19 ;
V_19 = & V_17 -> V_10 -> V_20 [ V_17 -> V_21 ] ;
if ( V_19 -> V_22 )
return F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
} else
if ( V_2 -> V_23 . V_22 )
return F_1 ( V_2 , V_2 -> V_23 . V_3 ,
V_2 -> V_23 . V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_24 ;
if ( V_17 -> V_10 ) {
struct V_18 * V_19 ;
V_19 = & V_17 -> V_10 -> V_20 [ V_17 -> V_21 ] ;
if ( V_19 -> V_22 ) {
V_24 = F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
}
} else
if ( V_2 -> V_23 . V_22 ) {
V_24 = F_1 ( V_2 , V_2 -> V_23 . V_3 , V_2 -> V_23 . V_4 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_25 ;
F_12 (old_idx, n, &c->old_idx, rb)
F_6 ( V_6 ) ;
V_2 -> V_6 = V_26 ;
}
static struct V_16 * F_13 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_27 ;
V_27 = F_14 ( V_17 , V_2 -> V_28 , V_11 ) ;
if ( F_3 ( ! V_27 ) )
return F_15 ( - V_12 ) ;
V_27 -> V_29 = NULL ;
F_16 ( V_30 , & V_27 -> V_31 ) ;
F_17 ( V_32 , & V_27 -> V_31 ) ;
F_18 ( ! F_19 ( V_17 ) ) ;
F_16 ( V_33 , & V_17 -> V_31 ) ;
if ( V_17 -> V_34 != 0 ) {
int V_35 ;
const int V_25 = V_27 -> V_36 ;
for ( V_35 = 0 ; V_35 < V_25 ; V_35 ++ ) {
struct V_18 * V_19 = & V_27 -> V_20 [ V_35 ] ;
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_10 = V_27 ;
}
}
F_20 ( & V_2 -> V_37 ) ;
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 , int V_3 , int V_38 )
{
V_2 -> V_39 -= F_22 ( V_38 , 8 ) ;
return F_23 ( V_2 , V_3 , V_38 ) ;
}
static struct V_16 * F_24 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
struct V_16 * V_27 ;
int V_24 ;
if ( ! F_25 ( V_17 ) ) {
if ( ! F_26 ( V_30 , & V_17 -> V_31 ) ) {
F_20 ( & V_2 -> V_37 ) ;
F_27 ( & V_2 -> V_40 ) ;
F_27 ( & V_41 ) ;
V_24 = F_21 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( F_3 ( V_24 ) )
return F_15 ( V_24 ) ;
}
return V_17 ;
}
V_27 = F_13 ( V_2 , V_17 ) ;
if ( F_28 ( V_27 ) )
return V_27 ;
if ( V_19 -> V_22 ) {
V_24 = F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
if ( F_3 ( V_24 ) )
return F_15 ( V_24 ) ;
V_24 = F_21 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
} else
V_24 = 0 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
if ( F_3 ( V_24 ) )
return F_15 ( V_24 ) ;
return V_27 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const void * V_42 )
{
int V_24 ;
void * V_43 ;
const struct V_44 * V_45 = V_42 ;
F_18 ( ! V_19 -> V_46 ) ;
F_18 ( V_19 -> V_22 != 0 ) ;
F_18 ( F_30 ( V_2 , & V_19 -> V_47 ) ) ;
V_24 = F_31 ( V_2 , V_45 ) ;
if ( V_24 ) {
F_32 () ;
F_33 ( V_2 , V_45 ) ;
return V_24 ;
}
V_43 = F_14 ( V_42 , V_19 -> V_22 , V_11 ) ;
if ( ! V_43 )
return 0 ;
V_19 -> V_46 = V_43 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_42 )
{
int V_24 ;
F_18 ( ! V_19 -> V_46 ) ;
F_18 ( V_19 -> V_22 != 0 ) ;
V_24 = F_31 ( V_2 , V_42 ) ;
if ( V_24 ) {
F_32 () ;
F_33 ( V_2 , V_42 ) ;
return V_24 ;
}
V_19 -> V_46 = V_42 ;
return 0 ;
}
static void F_35 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_46 )
return;
F_6 ( V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_42 )
{
int V_24 ;
F_18 ( F_30 ( V_2 , & V_19 -> V_47 ) ) ;
if ( V_19 -> V_46 ) {
F_18 ( V_19 -> V_22 != 0 ) ;
memcpy ( V_42 , V_19 -> V_46 , V_19 -> V_22 ) ;
return 0 ;
}
if ( V_2 -> V_48 ) {
V_24 = F_37 ( V_2 , & V_19 -> V_47 , V_19 , V_42 ) ;
if ( V_24 == 0 )
V_24 = - V_49 ;
else if ( V_24 == 1 )
V_24 = 0 ;
} else {
V_24 = F_38 ( V_2 , V_19 , V_42 ) ;
}
if ( V_24 )
return V_24 ;
V_24 = F_29 ( V_2 , V_19 , V_42 ) ;
return V_24 ;
}
static int F_39 ( const struct V_1 * V_2 , void * V_50 , int type ,
int V_22 , int V_3 , int V_4 )
{
int V_24 , V_51 ;
struct V_52 * V_53 = V_50 ;
T_1 V_54 , V_55 ;
F_40 ( L_2 , V_3 , V_4 , F_41 ( type ) , V_22 ) ;
V_24 = F_42 ( V_2 , V_3 , V_50 , V_4 , V_22 , 1 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_3 ,
type , V_3 , V_4 , V_24 ) ;
return V_24 ;
}
if ( F_43 ( V_53 -> V_56 ) != V_57 )
return 0 ;
if ( V_53 -> V_58 != type )
return 0 ;
V_51 = F_43 ( V_53 -> V_22 ) ;
if ( V_51 != V_22 )
return 0 ;
if ( type == V_59 && V_2 -> V_60 && ! V_2 -> V_61 &&
! V_2 -> V_62 )
return 1 ;
V_54 = F_44 ( V_63 , V_50 + 8 , V_51 - 8 ) ;
V_55 = F_43 ( V_53 -> V_54 ) ;
if ( V_54 != V_55 )
return 0 ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_18 * V_19 , void * V_42 )
{
int V_65 ;
F_45 ( V_47 , L_4 , V_19 -> V_3 , V_19 -> V_4 ) ;
V_65 = F_39 ( V_2 , V_42 , F_46 ( V_2 , V_47 ) , V_19 -> V_22 , V_19 -> V_3 ,
V_19 -> V_4 ) ;
if ( V_65 == 1 ) {
union V_64 V_66 ;
struct V_44 * V_45 = V_42 ;
F_47 ( V_2 , & V_45 -> V_47 , & V_66 ) ;
if ( F_48 ( V_2 , V_47 , & V_66 ) != 0 )
V_65 = 0 ;
}
if ( V_65 == 0 && V_2 -> V_48 )
F_49 ( V_47 , L_5 ,
V_19 -> V_3 , V_19 -> V_4 , V_19 -> V_22 ) ;
return V_65 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_67 * V_68 )
{
struct V_44 * V_45 ;
int V_69 , V_24 ;
if ( ! V_19 -> V_46 ) {
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_45 )
return - V_12 ;
V_24 = F_38 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_70;
V_24 = F_34 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_70;
} else
V_45 = V_19 -> V_46 ;
V_69 = F_51 ( V_45 -> V_69 ) ;
V_24 = memcmp ( V_45 -> V_71 , F_52 ( V_68 ) , F_53 ( int , V_69 , F_54 ( V_68 ) ) ) ;
if ( V_24 == 0 ) {
if ( V_69 == F_54 ( V_68 ) )
return V_72 ;
else if ( V_69 < F_54 ( V_68 ) )
return V_73 ;
else
return V_74 ;
} else if ( V_24 < 0 )
return V_73 ;
else
return V_74 ;
V_70:
F_6 ( V_45 ) ;
return V_24 ;
}
static struct V_16 * F_55 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_25 )
{
struct V_18 * V_19 ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_19 -> V_17 )
V_17 = V_19 -> V_17 ;
else
V_17 = F_56 ( V_2 , V_19 , V_17 , V_25 ) ;
return V_17 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_25 )
{
struct V_16 * V_17 = * V_27 ;
int V_75 = * V_25 ;
V_75 += 1 ;
if ( V_75 < V_17 -> V_36 ) {
* V_25 = V_75 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_76 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
return - V_49 ;
V_75 = V_17 -> V_21 + 1 ;
V_17 = V_76 ;
if ( V_75 < V_17 -> V_36 ) {
V_17 = F_55 ( V_2 , V_17 , V_75 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_17 = F_55 ( V_2 , V_17 , 0 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
V_75 = 0 ;
break;
}
}
* V_27 = V_17 ;
* V_25 = V_75 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_25 )
{
struct V_16 * V_17 = * V_27 ;
int V_75 = * V_25 ;
if ( V_75 > 0 ) {
* V_25 = V_75 - 1 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_76 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
return - V_49 ;
V_75 = V_17 -> V_21 - 1 ;
V_17 = V_76 ;
if ( V_75 >= 0 ) {
V_17 = F_55 ( V_2 , V_17 , V_75 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_75 = V_17 -> V_36 - 1 ;
V_17 = F_55 ( V_2 , V_17 , V_75 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
V_75 = V_17 -> V_36 - 1 ;
break;
}
}
* V_27 = V_17 ;
* V_25 = V_75 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
const struct V_67 * V_68 )
{
int V_24 ;
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_68 ) ;
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_74 ) {
while ( 1 ) {
V_24 = F_59 ( V_2 , V_27 , V_25 ) ;
if ( V_24 == - V_49 ) {
F_18 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
return 0 ;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] . V_47 , V_47 ) ) {
if ( * V_25 == ( * V_27 ) -> V_36 - 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_25 ) ;
if ( V_24 ) {
F_18 ( 0 ) ;
if ( V_24 == - V_49 )
V_24 = - V_77 ;
return V_24 ;
}
F_18 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
}
return 0 ;
}
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_73 )
return 0 ;
if ( V_24 == V_72 )
return 1 ;
F_18 ( V_24 == V_74 ) ;
}
} else {
int V_75 = * V_25 ;
struct V_16 * V_17 = * V_27 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_49 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_47 , V_47 ) )
return 0 ;
V_24 = F_50 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_74 )
return 0 ;
* V_27 = V_17 ;
* V_25 = V_75 ;
if ( V_24 == V_72 )
return 1 ;
F_18 ( V_24 == V_73 ) ;
}
}
}
static int F_61 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const struct V_67 * V_68 )
{
struct V_44 * V_45 ;
int V_69 , V_24 ;
if ( ! V_19 -> V_46 ) {
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_45 )
return - V_12 ;
V_24 = F_37 ( V_2 , & V_19 -> V_47 , V_19 , V_45 ) ;
if ( V_24 < 0 )
goto V_70;
if ( V_24 == 0 ) {
V_24 = V_78 ;
goto V_70;
}
F_18 ( V_24 == 1 ) ;
V_24 = F_34 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_70;
} else
V_45 = V_19 -> V_46 ;
V_69 = F_51 ( V_45 -> V_69 ) ;
V_24 = memcmp ( V_45 -> V_71 , F_52 ( V_68 ) , F_53 ( int , V_69 , F_54 ( V_68 ) ) ) ;
if ( V_24 == 0 ) {
if ( V_69 == F_54 ( V_68 ) )
return V_72 ;
else if ( V_69 < F_54 ( V_68 ) )
return V_73 ;
else
return V_74 ;
} else if ( V_24 < 0 )
return V_73 ;
else
return V_74 ;
V_70:
F_6 ( V_45 ) ;
return V_24 ;
}
static int F_62 ( struct V_1 * V_2 ,
const union V_64 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
const struct V_67 * V_68 ,
int V_79 )
{
struct V_16 * V_80 = NULL , * V_17 = * V_27 ;
int V_81 ( V_82 ) , V_24 , V_83 , V_84 = 0 , V_75 = * V_25 ;
V_83 = F_61 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( F_3 ( V_83 < 0 ) )
return V_83 ;
if ( V_83 == V_72 )
return 1 ;
if ( V_83 == V_78 ) {
V_80 = V_17 ;
V_82 = V_75 ;
V_84 = 1 ;
} else if ( ! V_79 )
V_84 = 1 ;
if ( V_83 == V_74 || V_84 ) {
while ( 1 ) {
V_24 = F_59 ( V_2 , V_27 , V_25 ) ;
if ( V_24 == - V_49 ) {
F_18 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
break;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] . V_47 , V_47 ) ) {
if ( * V_25 == ( * V_27 ) -> V_36 - 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_25 ) ;
if ( V_24 ) {
F_18 ( 0 ) ;
if ( V_24 == - V_49 )
V_24 = - V_77 ;
return V_24 ;
}
F_18 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
}
break;
}
V_24 = F_61 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_78 ) {
V_80 = * V_27 ;
V_82 = * V_25 ;
continue;
}
if ( ! V_79 )
continue;
if ( V_24 == V_73 )
break;
else
V_84 = 0 ;
}
}
if ( V_83 == V_73 || V_84 ) {
* V_27 = V_17 ;
* V_25 = V_75 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_49 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_47 , V_47 ) )
break;
V_24 = F_61 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_74 )
break;
* V_27 = V_17 ;
* V_25 = V_75 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_78 ) {
V_80 = V_17 ;
V_82 = V_75 ;
}
}
}
if ( V_79 || ! V_80 )
return 0 ;
F_49 ( V_47 , L_6 ,
V_80 -> V_20 [ V_82 ] . V_3 , V_80 -> V_20 [ V_82 ] . V_4 ,
V_80 -> V_20 [ V_82 ] . V_22 ) ;
* V_27 = V_80 ;
* V_25 = V_82 ;
return 1 ;
}
static int F_63 ( struct V_18 * V_19 , int V_3 , int V_4 )
{
if ( V_19 -> V_3 == V_3 && V_19 -> V_4 == V_4 )
return 1 ;
else
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
const union V_64 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_75 , V_24 ;
V_17 = * V_27 ;
V_75 = * V_25 ;
if ( F_63 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) )
return 1 ;
while ( 1 ) {
V_24 = F_59 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_49 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_47 , V_47 ) )
break;
if ( F_63 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) ) {
* V_27 = V_17 ;
* V_25 = V_75 ;
return 1 ;
}
}
V_17 = * V_27 ;
V_75 = * V_25 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_49 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_47 , V_47 ) )
return 0 ;
* V_27 = V_17 ;
* V_25 = V_75 ;
if ( F_63 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) )
return 1 ;
}
}
static struct V_16 * F_65 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_76 ;
int * V_85 = V_2 -> V_86 , V_9 = 0 ;
F_18 ( V_2 -> V_23 . V_17 ) ;
F_18 ( V_17 ) ;
if ( V_2 -> V_23 . V_17 -> V_34 > V_87 ) {
F_6 ( V_2 -> V_86 ) ;
V_2 -> V_86 = F_2 ( V_2 -> V_23 . V_17 -> V_34 * sizeof( int ) ,
V_11 ) ;
if ( ! V_2 -> V_86 )
return F_15 ( - V_12 ) ;
V_85 = V_2 -> V_86 ;
}
if ( V_2 -> V_23 . V_17 -> V_34 ) {
while ( 1 ) {
int V_25 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
break;
V_25 = V_17 -> V_21 ;
F_18 ( V_9 < V_2 -> V_23 . V_17 -> V_34 ) ;
V_85 [ V_9 ++ ] = V_25 ;
if ( ! V_76 -> V_29 && F_66 ( V_17 ) )
break;
V_17 = V_76 ;
}
}
while ( 1 ) {
struct V_18 * V_19 ;
V_76 = V_17 -> V_10 ;
if ( V_76 ) {
F_18 ( V_85 [ V_9 - 1 ] >= 0 ) ;
F_18 ( V_85 [ V_9 - 1 ] < V_76 -> V_36 ) ;
V_19 = & V_76 -> V_20 [ V_85 [ -- V_9 ] ] ;
V_17 = F_24 ( V_2 , V_19 ) ;
} else {
F_18 ( V_17 == V_2 -> V_23 . V_17 ) ;
V_17 = F_24 ( V_2 , & V_2 -> V_23 ) ;
}
if ( F_28 ( V_17 ) || ! V_9 )
break;
F_18 ( V_85 [ V_9 - 1 ] >= 0 ) ;
F_18 ( V_85 [ V_9 - 1 ] < V_17 -> V_36 ) ;
V_17 = V_17 -> V_20 [ V_85 [ V_9 - 1 ] ] . V_17 ;
}
return V_17 ;
}
int F_67 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_16 * * V_27 , int * V_25 )
{
int V_24 , V_88 ;
struct V_16 * V_17 ;
unsigned long time = F_68 () ;
F_45 ( V_47 , L_7 ) ;
F_18 ( F_46 ( V_2 , V_47 ) < V_89 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_56 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_88 = F_69 ( V_2 , V_17 , V_47 , V_25 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_25 < 0 )
* V_25 = 0 ;
V_19 = & V_17 -> V_20 [ * V_25 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = V_19 -> V_17 ;
continue;
}
V_17 = F_56 ( V_2 , V_19 , V_17 , * V_25 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_88 || ! F_30 ( V_2 , V_47 ) || * V_25 != - 1 ) {
F_70 ( L_8 , V_88 , V_17 -> V_34 , * V_25 ) ;
return V_88 ;
}
V_24 = F_59 ( V_2 , & V_17 , V_25 ) ;
if ( V_24 == - V_49 ) {
F_70 ( L_9 , V_17 -> V_34 ) ;
* V_25 = - 1 ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ * V_25 ] . V_47 ) ) {
F_70 ( L_9 , V_17 -> V_34 ) ;
* V_25 = - 1 ;
return 0 ;
}
F_70 ( L_10 , V_17 -> V_34 , * V_25 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_16 * * V_27 , int * V_25 )
{
int V_24 , V_88 ;
struct V_16 * V_17 ;
unsigned long time = F_68 () ;
F_45 ( V_47 , L_11 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_56 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
V_17 = F_24 ( V_2 , & V_2 -> V_23 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_88 = F_69 ( V_2 , V_17 , V_47 , V_25 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_25 < 0 )
* V_25 = 0 ;
V_19 = & V_17 -> V_20 [ * V_25 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = F_24 ( V_2 , V_19 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
continue;
}
V_17 = F_56 ( V_2 , V_19 , V_17 , * V_25 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
V_17 = F_24 ( V_2 , V_19 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_88 || ! F_30 ( V_2 , V_47 ) || * V_25 != - 1 ) {
F_70 ( L_8 , V_88 , V_17 -> V_34 , * V_25 ) ;
return V_88 ;
}
V_24 = F_59 ( V_2 , & V_17 , V_25 ) ;
if ( V_24 == - V_49 ) {
* V_25 = - 1 ;
F_70 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ * V_25 ] . V_47 ) ) {
* V_25 = - 1 ;
F_70 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
}
F_70 ( L_10 , V_17 -> V_34 , * V_25 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_72 ( struct V_1 * V_2 , int V_3 , int V_90 )
{
int V_91 , V_92 ;
V_92 = V_2 -> V_92 ;
F_73 () ;
V_91 = V_2 -> V_93 ;
if ( V_90 == V_91 )
return 0 ;
if ( V_90 + 1 != V_91 )
return 1 ;
F_73 () ;
if ( V_92 != V_2 -> V_92 )
return 1 ;
if ( V_92 == V_3 )
return 1 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , const union V_64 * V_47 ,
void * V_42 , int * V_3 , int * V_4 )
{
int V_94 , V_25 , V_24 , V_95 = 0 , V_90 ;
struct V_16 * V_17 ;
struct V_18 V_19 , * V_96 ;
V_97:
F_75 ( & V_2 -> V_98 ) ;
V_94 = F_67 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
V_24 = - V_49 ;
goto V_99;
} else if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_99;
}
V_96 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 ) {
* V_3 = V_96 -> V_3 ;
* V_4 = V_96 -> V_4 ;
}
if ( F_30 ( V_2 , V_47 ) ) {
V_24 = F_36 ( V_2 , V_96 , V_42 ) ;
goto V_99;
}
if ( V_95 ) {
V_24 = F_38 ( V_2 , V_96 , V_42 ) ;
goto V_99;
}
V_19 = V_17 -> V_20 [ V_25 ] ;
V_90 = V_2 -> V_93 ;
F_76 ( & V_2 -> V_98 ) ;
if ( F_77 ( V_2 , V_19 . V_3 ) ) {
V_24 = F_38 ( V_2 , & V_19 , V_42 ) ;
return V_24 ;
}
V_24 = F_37 ( V_2 , V_47 , & V_19 , V_42 ) ;
if ( V_24 <= 0 || F_72 ( V_2 , V_19 . V_3 , V_90 ) ) {
V_95 = 1 ;
goto V_97;
}
return 0 ;
V_99:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_78 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
int V_25 , V_24 = 0 , V_3 = - 1 , V_81 ( V_4 ) ;
int V_81 ( V_22 ) ;
unsigned int V_102 = F_79 ( V_2 , & V_101 -> V_47 ) ;
struct V_16 * V_17 ;
V_101 -> V_103 = 0 ;
V_101 -> V_104 = 0 ;
V_101 -> V_105 = 0 ;
F_75 ( & V_2 -> V_98 ) ;
V_24 = F_67 ( V_2 , & V_101 -> V_47 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_99;
if ( V_24 ) {
V_22 = V_17 -> V_20 [ V_25 ] . V_22 ;
if ( V_22 > V_101 -> V_106 ) {
V_24 = - V_77 ;
goto V_99;
}
V_101 -> V_20 [ V_101 -> V_103 ++ ] = V_17 -> V_20 [ V_25 ] ;
V_101 -> V_104 += 1 ;
V_3 = V_17 -> V_20 [ V_25 ] . V_3 ;
V_4 = F_22 ( V_17 -> V_20 [ V_25 ] . V_4 + V_22 , 8 ) ;
}
while ( 1 ) {
struct V_18 * V_19 ;
union V_64 * V_47 ;
unsigned int V_107 ;
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 )
goto V_99;
V_19 = & V_17 -> V_20 [ V_25 ] ;
V_47 = & V_19 -> V_47 ;
if ( F_80 ( V_2 , V_47 ) != F_80 ( V_2 , & V_101 -> V_47 ) ||
F_46 ( V_2 , V_47 ) != V_108 ) {
V_24 = - V_49 ;
goto V_99;
}
if ( V_3 < 0 ) {
V_3 = V_19 -> V_3 ;
V_4 = F_22 ( V_19 -> V_4 + V_19 -> V_22 , 8 ) ;
V_22 = V_19 -> V_22 ;
if ( V_22 > V_101 -> V_106 ) {
V_24 = - V_77 ;
goto V_99;
}
} else {
if ( V_19 -> V_3 != V_3 || V_19 -> V_4 != V_4 )
goto V_99;
V_4 += F_22 ( V_19 -> V_22 , 8 ) ;
V_22 = F_22 ( V_22 , 8 ) + V_19 -> V_22 ;
if ( V_22 > V_101 -> V_106 )
goto V_99;
}
V_107 = F_79 ( V_2 , V_47 ) ;
V_101 -> V_104 += ( V_107 - V_102 - 1 ) ;
if ( V_101 -> V_104 >= V_109 )
goto V_99;
V_102 = V_107 ;
V_101 -> V_20 [ V_101 -> V_103 ++ ] = * V_19 ;
V_101 -> V_104 += 1 ;
if ( V_101 -> V_103 >= V_109 )
goto V_99;
if ( V_101 -> V_104 >= V_109 )
goto V_99;
}
V_99:
if ( V_24 == - V_49 ) {
V_101 -> V_105 = 1 ;
V_24 = 0 ;
}
V_101 -> V_93 = V_2 -> V_93 ;
F_76 ( & V_2 -> V_98 ) ;
if ( V_24 )
return V_24 ;
if ( V_101 -> V_104 > V_109 )
V_101 -> V_104 = V_109 ;
if ( V_110 == 1 ||
! ( V_101 -> V_104 & ( V_110 - 1 ) ) )
return 0 ;
if ( V_101 -> V_105 ) {
V_101 -> V_104 += V_110 - 1 ;
return 0 ;
}
V_102 = F_79 ( V_2 , & V_101 -> V_47 ) + V_101 -> V_104 ;
V_102 &= ~ ( V_110 - 1 ) ;
while ( V_101 -> V_103 ) {
if ( F_79 ( V_2 , & V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_47 ) < V_102 )
break;
V_101 -> V_103 -= 1 ;
}
return 0 ;
}
static int F_81 ( struct V_111 * V_112 , void * V_50 , int V_22 , int V_3 ,
int V_4 )
{
const struct V_1 * V_2 = V_112 -> V_2 ;
int V_113 , V_114 ;
F_40 ( L_12 , V_3 , V_4 , V_22 ) ;
F_18 ( V_112 && V_3 >= 0 && V_3 < V_2 -> V_115 && V_4 >= 0 ) ;
F_18 ( ! ( V_4 & 7 ) && V_4 < V_2 -> V_116 ) ;
F_18 ( V_4 + V_22 <= V_2 -> V_116 ) ;
F_82 ( & V_112 -> V_117 ) ;
V_114 = ( V_3 == V_112 -> V_3 && V_4 + V_22 > V_112 -> V_4 ) ;
if ( ! V_114 ) {
F_83 ( & V_112 -> V_117 ) ;
return F_42 ( V_2 , V_3 , V_50 , V_4 , V_22 , 0 ) ;
}
V_113 = V_112 -> V_4 - V_4 ;
if ( V_113 < 0 )
V_113 = 0 ;
memcpy ( V_50 + V_113 , V_112 -> V_50 + V_4 + V_113 - V_112 -> V_4 , V_22 - V_113 ) ;
F_83 ( & V_112 -> V_117 ) ;
if ( V_113 > 0 )
return F_42 ( V_2 , V_3 , V_50 , V_4 , V_113 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , void * V_50 ,
struct V_18 * V_19 )
{
union V_64 V_118 ;
struct V_52 * V_53 = V_50 ;
int V_24 , V_22 ;
if ( V_53 -> V_58 != V_59 ) {
F_5 ( V_2 , L_13 ,
V_53 -> V_58 , V_59 ) ;
goto V_119;
}
V_24 = F_85 ( V_2 , V_50 , V_19 -> V_3 , V_19 -> V_4 , 0 , 0 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_14 , V_59 ) ;
goto V_99;
}
V_22 = F_43 ( V_53 -> V_22 ) ;
if ( V_22 != V_19 -> V_22 ) {
F_5 ( V_2 , L_15 , V_22 , V_19 -> V_22 ) ;
goto V_119;
}
F_47 ( V_2 , V_50 + V_120 , & V_118 ) ;
if ( ! F_86 ( V_2 , & V_19 -> V_47 , & V_118 ) ) {
F_5 ( V_2 , L_16 ,
V_19 -> V_3 , V_19 -> V_4 ) ;
F_45 ( & V_19 -> V_47 , L_17 ) ;
F_45 ( & V_118 , L_18 ) ;
goto V_119;
}
return 0 ;
V_119:
V_24 = - V_77 ;
V_99:
F_5 ( V_2 , L_19 , V_19 -> V_3 , V_19 -> V_4 ) ;
F_33 ( V_2 , V_50 ) ;
F_32 () ;
return V_24 ;
}
int F_87 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
int V_3 = V_101 -> V_20 [ 0 ] . V_3 , V_4 = V_101 -> V_20 [ 0 ] . V_4 , V_22 , V_24 , V_35 ;
struct V_111 * V_112 ;
void * V_50 ;
V_22 = V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_4 ;
V_22 += V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_22 - V_4 ;
if ( V_22 > V_101 -> V_106 ) {
F_5 ( V_2 , L_20 , V_101 -> V_106 , V_22 ) ;
return - V_77 ;
}
V_112 = F_77 ( V_2 , V_3 ) ;
if ( V_112 )
V_24 = F_81 ( V_112 , V_101 -> V_50 , V_22 , V_3 , V_4 ) ;
else
V_24 = F_42 ( V_2 , V_3 , V_101 -> V_50 , V_4 , V_22 , 0 ) ;
if ( F_72 ( V_2 , V_3 , V_101 -> V_93 ) )
return - V_121 ;
if ( V_24 && V_24 != - V_122 ) {
F_5 ( V_2 , L_21 ,
V_3 , V_4 , V_24 ) ;
F_32 () ;
F_45 ( & V_101 -> V_47 , L_22 ) ;
return V_24 ;
}
V_50 = V_101 -> V_50 ;
for ( V_35 = 0 ; V_35 < V_101 -> V_103 ; V_35 ++ ) {
V_24 = F_84 ( V_2 , V_50 , & V_101 -> V_20 [ V_35 ] ) ;
if ( V_24 )
return V_24 ;
V_50 = V_50 + F_22 ( V_101 -> V_20 [ V_35 ] . V_22 , 8 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , const union V_64 * V_47 ,
void * V_42 , const struct V_67 * V_68 )
{
int V_94 , V_25 , V_24 ;
struct V_16 * V_17 ;
F_45 ( V_47 , L_22 ) ;
F_75 ( & V_2 -> V_98 ) ;
V_94 = F_67 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
V_24 = - V_49 ;
goto V_123;
} else if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
F_18 ( V_25 >= 0 ) ;
V_24 = F_60 ( V_2 , V_47 , & V_17 , & V_25 , V_68 ) ;
F_70 ( L_23 , V_24 , V_17 , V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
if ( V_24 == 0 ) {
V_24 = - V_49 ;
goto V_123;
}
V_24 = F_36 ( V_2 , & V_17 -> V_20 [ V_25 ] , V_42 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_89 ( struct V_1 * V_2 , const union V_64 * V_47 ,
void * V_42 , const struct V_67 * V_68 )
{
int V_24 , V_22 ;
const struct V_44 * V_45 = V_42 ;
V_24 = F_90 ( V_2 , V_47 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_22 = F_51 ( V_45 -> V_69 ) ;
if ( F_54 ( V_68 ) == V_22 && ! memcmp ( V_45 -> V_71 , F_52 ( V_68 ) , V_22 ) )
return 0 ;
return F_88 ( V_2 , V_47 , V_42 , V_68 ) ;
}
static int F_91 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_44 * V_45 , T_1 V_124 ,
struct V_16 * * V_27 , int * V_25 )
{
int V_24 ;
struct V_16 * V_17 = * V_27 ;
struct V_18 * V_19 ;
union V_64 * V_125 ;
for (; ; ) {
if ( ! V_24 ) {
V_24 = F_57 ( V_2 , & V_17 , V_25 ) ;
if ( V_24 )
goto V_99;
}
V_19 = & V_17 -> V_20 [ * V_25 ] ;
V_125 = & V_19 -> V_47 ;
if ( F_80 ( V_2 , V_125 ) != F_80 ( V_2 , V_47 ) ||
F_46 ( V_2 , V_125 ) != F_46 ( V_2 , V_47 ) ) {
V_24 = - V_49 ;
goto V_99;
}
V_24 = F_36 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_99;
if ( F_92 ( V_2 , V_47 ) == F_92 ( V_2 , V_125 ) &&
F_43 ( V_45 -> V_124 ) == V_124 ) {
* V_27 = V_17 ;
goto V_99;
}
}
V_99:
return V_24 ;
}
static int F_93 ( struct V_1 * V_2 , const union V_64 * V_47 ,
struct V_44 * V_45 , T_1 V_124 )
{
int V_25 , V_24 ;
struct V_16 * V_17 ;
union V_64 V_126 ;
F_18 ( F_30 ( V_2 , V_47 ) ) ;
F_94 ( V_2 , & V_126 , F_80 ( V_2 , V_47 ) ) ;
F_75 ( & V_2 -> V_98 ) ;
V_24 = F_67 ( V_2 , & V_126 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
V_24 = F_91 ( V_2 , V_47 , V_45 , V_124 , & V_17 , & V_25 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_95 ( struct V_1 * V_2 , const union V_64 * V_47 ,
void * V_42 , T_1 V_124 )
{
int V_24 ;
const struct V_44 * V_45 = V_42 ;
if ( ! V_2 -> V_127 )
return - V_128 ;
V_24 = F_90 ( V_2 , V_47 , V_42 ) ;
if ( V_24 )
return V_24 ;
if ( F_43 ( V_45 -> V_124 ) == V_124 )
return 0 ;
return F_93 ( V_2 , V_47 , V_42 , V_124 ) ;
}
static void F_96 ( const struct V_1 * V_2 ,
struct V_16 * V_17 )
{
union V_64 * V_47 , * V_118 ;
F_18 ( V_17 -> V_10 ) ;
F_18 ( V_17 -> V_21 == 0 ) ;
V_47 = & V_17 -> V_20 [ 0 ] . V_47 ;
V_118 = & V_17 -> V_10 -> V_20 [ 0 ] . V_47 ;
while ( F_48 ( V_2 , V_47 , V_118 ) < 0 ) {
F_97 ( V_2 , V_47 , V_118 ) ;
V_17 = V_17 -> V_10 ;
V_17 -> V_129 = 1 ;
if ( ! V_17 -> V_10 || V_17 -> V_21 )
break;
V_118 = & V_17 -> V_10 -> V_20 [ 0 ] . V_47 ;
}
}
static void F_98 ( struct V_16 * V_17 ,
const struct V_18 * V_19 , int V_25 )
{
int V_35 ;
F_18 ( F_66 ( V_17 ) ) ;
if ( V_17 -> V_34 ) {
for ( V_35 = V_17 -> V_36 ; V_35 > V_25 ; V_35 -- ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_21 = V_25 ;
} else
for ( V_35 = V_17 -> V_36 ; V_35 > V_25 ; V_35 -- )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
V_17 -> V_20 [ V_25 ] = * V_19 ;
V_17 -> V_36 += 1 ;
if ( V_25 == 0 )
V_17 -> V_129 = 1 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 , int V_25 )
{
struct V_16 * V_27 , * V_130 , * V_76 ;
int V_35 , V_131 , V_132 , V_133 = 0 ;
union V_64 * V_47 = & V_19 -> V_47 , * V_118 ;
F_18 ( V_25 >= 0 && V_25 <= V_2 -> V_134 ) ;
V_97:
V_76 = V_17 -> V_10 ;
if ( V_17 -> V_36 < V_2 -> V_134 ) {
F_18 ( V_25 != V_2 -> V_134 ) ;
F_45 ( V_47 , L_24 , V_25 , V_17 -> V_34 ) ;
F_98 ( V_17 , V_19 , V_25 ) ;
if ( V_25 == 0 && V_76 && V_17 -> V_21 == 0 )
F_96 ( V_2 , V_17 ) ;
return 0 ;
}
F_45 ( V_47 , L_25 , V_17 -> V_34 ) ;
if ( V_17 -> V_129 )
F_10 ( V_2 , V_17 ) ;
V_27 = F_100 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_76 ;
V_27 -> V_34 = V_17 -> V_34 ;
if ( V_17 -> V_34 == 0 && F_46 ( V_2 , V_47 ) == V_108 ) {
if ( V_25 == V_2 -> V_134 ) {
V_118 = & V_17 -> V_20 [ V_25 - 1 ] . V_47 ;
if ( F_80 ( V_2 , V_118 ) == F_80 ( V_2 , V_47 ) &&
F_46 ( V_2 , V_118 ) == V_108 )
V_133 = 1 ;
} else
goto V_135;
} else if ( V_133 && V_25 != V_2 -> V_134 ) {
V_133 = 0 ;
V_135:
if ( V_25 >= ( V_2 -> V_134 + 1 ) / 2 ) {
V_118 = & V_17 -> V_20 [ 0 ] . V_47 ;
if ( F_80 ( V_2 , V_118 ) == F_80 ( V_2 , V_47 ) &&
F_46 ( V_2 , V_118 ) == V_108 ) {
V_118 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( F_80 ( V_2 , V_118 ) != F_80 ( V_2 , V_47 ) ||
F_46 ( V_2 , V_118 ) != V_108 ) {
V_131 = V_25 ;
V_132 = V_2 -> V_134 - V_131 ;
V_130 = V_17 ;
goto V_136;
}
}
}
}
if ( V_133 ) {
V_131 = V_2 -> V_134 ;
V_132 = 0 ;
} else {
V_131 = ( V_2 -> V_134 + 1 ) / 2 ;
V_132 = V_2 -> V_134 - V_131 ;
}
if ( V_25 < V_131 ) {
V_130 = V_17 ;
V_132 += 1 ;
V_131 -= 1 ;
} else {
V_130 = V_27 ;
V_25 -= V_131 ;
if ( V_27 -> V_34 != 0 )
V_19 -> V_17 -> V_10 = V_27 ;
}
V_136:
F_16 ( V_30 , & V_27 -> V_31 ) ;
F_20 ( & V_2 -> V_37 ) ;
V_27 -> V_36 = V_132 ;
V_17 -> V_36 = V_131 ;
F_70 ( L_26 , V_132 , V_131 ) ;
for ( V_35 = 0 ; V_35 < V_132 ; V_35 ++ ) {
V_27 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_131 + V_35 ] ;
if ( V_27 -> V_34 != 0 )
if ( V_27 -> V_20 [ V_35 ] . V_17 ) {
V_27 -> V_20 [ V_35 ] . V_17 -> V_10 = V_27 ;
V_27 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
}
F_45 ( V_47 , L_27 , V_25 , V_27 -> V_34 ) ;
F_98 ( V_130 , V_19 , V_25 ) ;
if ( V_76 ) {
if ( V_25 == 0 && V_130 == V_17 && V_17 -> V_21 == 0 )
F_96 ( V_2 , V_17 ) ;
V_25 = V_17 -> V_21 + 1 ;
V_19 -> V_47 = V_27 -> V_20 [ 0 ] . V_47 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
V_17 = V_76 ;
goto V_97;
}
F_70 ( L_28 , V_17 -> V_34 + 1 ) ;
V_130 = F_100 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_130 )
return - V_12 ;
V_130 -> V_36 = 2 ;
V_130 -> V_34 = V_17 -> V_34 + 1 ;
F_16 ( V_30 , & V_130 -> V_31 ) ;
F_20 ( & V_2 -> V_37 ) ;
V_130 -> V_20 [ 0 ] . V_47 = V_17 -> V_20 [ 0 ] . V_47 ;
V_130 -> V_20 [ 0 ] . V_17 = V_17 ;
V_130 -> V_20 [ 0 ] . V_3 = V_2 -> V_23 . V_3 ;
V_130 -> V_20 [ 0 ] . V_4 = V_2 -> V_23 . V_4 ;
V_130 -> V_20 [ 0 ] . V_22 = V_2 -> V_23 . V_22 ;
V_130 -> V_20 [ 1 ] . V_47 = V_27 -> V_20 [ 0 ] . V_47 ;
V_130 -> V_20 [ 1 ] . V_17 = V_27 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
V_2 -> V_23 . V_17 = V_130 ;
V_27 -> V_10 = V_130 ;
V_27 -> V_21 = 1 ;
V_17 -> V_10 = V_130 ;
V_17 -> V_21 = 0 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , const union V_64 * V_47 , int V_3 ,
int V_4 , int V_22 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_75 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_29 , V_3 , V_4 , V_22 ) ;
V_94 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_97 ( V_2 , V_47 , & V_19 . V_47 ) ;
V_24 = F_99 ( V_2 , V_17 , & V_19 , V_25 + 1 ) ;
} else if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_23 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
} else
V_24 = V_94 ;
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_103 ( struct V_1 * V_2 , const union V_64 * V_47 ,
int V_137 , int V_138 , int V_3 , int V_4 , int V_22 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_75 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_30 , V_137 ,
V_138 , V_3 , V_4 , V_22 ) ;
V_94 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
V_94 = 0 ;
if ( V_19 -> V_3 == V_137 && V_19 -> V_4 == V_138 ) {
F_35 ( V_19 ) ;
V_24 = F_23 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 )
goto V_123;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
V_94 = 1 ;
} else if ( F_30 ( V_2 , V_47 ) ) {
V_94 = F_64 ( V_2 , V_47 , & V_17 , & V_25 ,
V_137 , V_138 ) ;
F_70 ( L_31 ,
V_94 , V_17 , V_25 , V_137 , V_138 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 ) {
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
}
V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_23 ( V_2 , V_19 -> V_3 ,
V_19 -> V_22 ) ;
if ( V_24 )
goto V_123;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
}
}
}
if ( ! V_94 )
V_24 = F_23 ( V_2 , V_3 , V_22 ) ;
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_104 ( struct V_1 * V_2 , const union V_64 * V_47 ,
int V_3 , int V_4 , int V_22 ,
const struct V_67 * V_68 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_75 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_4 , V_3 , V_4 ) ;
V_94 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 ) {
if ( V_2 -> V_48 )
V_94 = F_62 ( V_2 , V_47 , & V_17 , & V_25 ,
V_68 , 1 ) ;
else
V_94 = F_60 ( V_2 , V_47 , & V_17 , & V_25 , V_68 ) ;
F_70 ( L_23 , V_94 , V_17 , V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
}
if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_23 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
goto V_123;
}
}
if ( ! V_94 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_97 ( V_2 , V_47 , & V_19 . V_47 ) ;
V_24 = F_99 ( V_2 , V_17 , & V_19 , V_25 + 1 ) ;
if ( V_24 )
goto V_123;
if ( V_2 -> V_48 ) {
struct V_67 V_139 = { . V_140 = { . V_71 = L_32 , . V_22 = 1 } } ;
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
if ( V_24 )
return V_24 ;
return F_105 ( V_2 , V_47 , & V_139 ) ;
}
}
V_123:
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_25 )
{
struct V_18 * V_19 ;
struct V_16 * V_76 ;
int V_35 , V_24 ;
F_18 ( V_17 -> V_34 == 0 ) ;
F_18 ( V_25 >= 0 && V_25 < V_2 -> V_134 ) ;
F_45 ( & V_17 -> V_20 [ V_25 ] . V_47 , L_33 ) ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_23 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 ) {
F_107 ( V_2 , V_17 ) ;
return V_24 ;
}
for ( V_35 = V_25 ; V_35 < V_17 -> V_36 - 1 ; V_35 ++ )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
V_17 -> V_36 -= 1 ;
if ( V_17 -> V_36 > 0 )
return 0 ;
do {
F_18 ( ! F_19 ( V_17 ) ) ;
F_18 ( F_66 ( V_17 ) ) ;
V_76 = V_17 -> V_10 ;
V_25 = V_17 -> V_21 ;
F_27 ( & V_2 -> V_37 ) ;
V_24 = F_9 ( V_2 , V_17 ) ;
if ( V_24 )
return V_24 ;
if ( V_17 -> V_29 ) {
F_16 ( V_33 , & V_17 -> V_31 ) ;
F_20 ( & V_2 -> V_40 ) ;
F_20 ( & V_41 ) ;
} else
F_6 ( V_17 ) ;
V_17 = V_76 ;
} while ( V_17 -> V_36 == 1 );
V_17 -> V_36 -= 1 ;
F_18 ( V_17 -> V_34 != 0 ) ;
for ( V_35 = V_25 ; V_35 < V_17 -> V_36 ; V_35 ++ ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( ! V_17 -> V_10 ) {
while ( V_17 -> V_36 == 1 && V_17 -> V_34 != 0 ) {
V_76 = V_17 ;
V_19 = & V_17 -> V_20 [ 0 ] ;
V_17 = F_55 ( V_2 , V_17 , 0 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
V_17 = F_24 ( V_2 , V_19 ) ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
V_17 -> V_10 = NULL ;
V_17 -> V_21 = 0 ;
if ( V_2 -> V_23 . V_22 ) {
V_24 = F_1 ( V_2 , V_2 -> V_23 . V_3 ,
V_2 -> V_23 . V_4 ) ;
if ( V_24 )
return V_24 ;
}
V_2 -> V_23 . V_3 = V_19 -> V_3 ;
V_2 -> V_23 . V_4 = V_19 -> V_4 ;
V_2 -> V_23 . V_22 = V_19 -> V_22 ;
V_2 -> V_23 . V_17 = V_17 ;
F_18 ( ! F_19 ( V_76 ) ) ;
F_18 ( F_66 ( V_76 ) ) ;
F_27 ( & V_2 -> V_37 ) ;
if ( V_76 -> V_29 ) {
F_16 ( V_33 , & V_76 -> V_31 ) ;
F_20 ( & V_2 -> V_40 ) ;
F_20 ( & V_41 ) ;
} else
F_6 ( V_76 ) ;
}
}
return 0 ;
}
int F_108 ( struct V_1 * V_2 , const union V_64 * V_47 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_75 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_22 ) ;
V_94 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 )
V_24 = F_106 ( V_2 , V_17 , V_25 ) ;
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_105 ( struct V_1 * V_2 , const union V_64 * V_47 ,
const struct V_67 * V_68 )
{
int V_25 , V_24 ;
struct V_16 * V_17 ;
F_75 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_22 ) ;
V_24 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
if ( V_2 -> V_48 )
V_24 = F_62 ( V_2 , V_47 , & V_17 , & V_25 ,
V_68 , 0 ) ;
else
V_24 = F_60 ( V_2 , V_47 , & V_17 , & V_25 , V_68 ) ;
F_70 ( L_23 , V_24 , V_17 , V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
}
V_24 = F_106 ( V_2 , V_17 , V_25 ) ;
}
}
V_123:
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_109 ( struct V_1 * V_2 , const union V_64 * V_47 ,
T_1 V_124 )
{
int V_25 , V_24 ;
struct V_16 * V_17 ;
struct V_44 * V_45 ;
struct V_18 * V_19 ;
if ( ! V_2 -> V_127 )
return - V_128 ;
F_75 ( & V_2 -> V_98 ) ;
V_24 = F_71 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_24 <= 0 )
goto V_123;
V_19 = & V_17 -> V_20 [ V_25 ] ;
V_45 = F_2 ( V_141 , V_11 ) ;
if ( ! V_45 ) {
V_24 = - V_12 ;
goto V_123;
}
V_24 = F_36 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_70;
if ( F_43 ( V_45 -> V_124 ) != V_124 ) {
union V_64 V_126 ;
F_94 ( V_2 , & V_126 , F_80 ( V_2 , V_47 ) ) ;
V_24 = F_67 ( V_2 , & V_126 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_70;
V_24 = F_91 ( V_2 , V_47 , V_45 , V_124 , & V_17 , & V_25 ) ;
if ( V_24 )
goto V_70;
}
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_70;
}
}
V_24 = F_106 ( V_2 , V_17 , V_25 ) ;
V_70:
F_6 ( V_45 ) ;
V_123:
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static int F_110 ( struct V_1 * V_2 , union V_64 * V_47 ,
union V_64 * V_142 , union V_64 * V_143 )
{
if ( F_48 ( V_2 , V_47 , V_142 ) < 0 )
return 0 ;
if ( F_48 ( V_2 , V_47 , V_143 ) > 0 )
return 0 ;
return 1 ;
}
int F_111 ( struct V_1 * V_2 , union V_64 * V_142 ,
union V_64 * V_143 )
{
int V_35 , V_25 , V_144 , V_24 = 0 ;
struct V_16 * V_17 ;
union V_64 * V_47 ;
F_75 ( & V_2 -> V_98 ) ;
while ( 1 ) {
V_24 = F_67 ( V_2 , V_142 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 )
V_47 = V_142 ;
else {
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_49 ) {
V_24 = 0 ;
goto V_123;
}
if ( V_24 < 0 )
goto V_123;
V_47 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( ! F_110 ( V_2 , V_47 , V_142 , V_143 ) ) {
V_24 = 0 ;
goto V_123;
}
}
if ( V_17 -> V_29 || ! F_66 ( V_17 ) ) {
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
}
for ( V_35 = V_25 + 1 , V_144 = 0 ; V_35 < V_17 -> V_36 ; V_35 ++ , V_144 ++ ) {
V_47 = & V_17 -> V_20 [ V_35 ] . V_47 ;
if ( ! F_110 ( V_2 , V_47 , V_142 , V_143 ) )
break;
F_35 ( & V_17 -> V_20 [ V_35 ] ) ;
V_24 = F_23 ( V_2 , V_17 -> V_20 [ V_35 ] . V_3 ,
V_17 -> V_20 [ V_35 ] . V_22 ) ;
if ( V_24 ) {
F_107 ( V_2 , V_17 ) ;
goto V_123;
}
F_45 ( V_47 , L_34 ) ;
}
if ( V_144 ) {
for ( V_35 = V_25 + 1 + V_144 ; V_35 < V_17 -> V_36 ; V_35 ++ )
V_17 -> V_20 [ V_35 - V_144 ] = V_17 -> V_20 [ V_35 ] ;
V_17 -> V_36 -= V_144 ;
}
V_24 = F_106 ( V_2 , V_17 , V_25 ) ;
if ( V_24 )
goto V_123;
}
V_123:
if ( ! V_24 )
V_24 = F_102 ( V_2 , 0 ) ;
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_112 ( struct V_1 * V_2 , T_2 V_145 )
{
union V_64 V_118 , V_146 ;
struct V_44 * V_147 , * V_148 = NULL ;
struct V_67 V_68 = { 0 } ;
F_70 ( L_35 , ( unsigned long ) V_145 ) ;
F_113 ( V_2 , & V_118 , V_145 ) ;
while ( 1 ) {
T_2 V_149 ;
int V_24 ;
V_147 = F_114 ( V_2 , & V_118 , & V_68 ) ;
if ( F_28 ( V_147 ) ) {
V_24 = F_58 ( V_147 ) ;
if ( V_24 == - V_49 )
break;
return V_24 ;
}
V_149 = F_115 ( V_147 -> V_145 ) ;
F_70 ( L_36 , V_147 -> V_71 ,
( unsigned long ) V_149 ) ;
F_116 ( V_2 , V_149 ) ;
F_52 ( & V_68 ) = V_147 -> V_71 ;
F_54 ( & V_68 ) = F_51 ( V_147 -> V_69 ) ;
V_24 = F_105 ( V_2 , & V_118 , & V_68 ) ;
if ( V_24 ) {
F_6 ( V_147 ) ;
return V_24 ;
}
F_117 ( V_2 , & V_118 , V_149 ) ;
F_118 ( V_2 , & V_146 , V_149 ) ;
V_24 = F_111 ( V_2 , & V_118 , & V_146 ) ;
if ( V_24 ) {
F_6 ( V_147 ) ;
return V_24 ;
}
F_6 ( V_148 ) ;
V_148 = V_147 ;
F_47 ( V_2 , & V_147 -> V_47 , & V_118 ) ;
}
F_6 ( V_148 ) ;
F_117 ( V_2 , & V_118 , V_145 ) ;
F_118 ( V_2 , & V_146 , V_145 ) ;
return F_111 ( V_2 , & V_118 , & V_146 ) ;
}
struct V_44 * F_114 ( struct V_1 * V_2 ,
union V_64 * V_47 ,
const struct V_67 * V_68 )
{
int V_25 , V_24 , type = F_46 ( V_2 , V_47 ) ;
struct V_16 * V_17 ;
struct V_44 * V_45 ;
struct V_18 * V_19 ;
union V_64 * V_125 ;
F_45 ( V_47 , L_22 ) ;
F_18 ( F_30 ( V_2 , V_47 ) ) ;
F_75 ( & V_2 -> V_98 ) ;
V_24 = F_67 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
if ( F_54 ( V_68 ) > 0 ) {
if ( V_24 ) {
if ( V_2 -> V_48 )
V_24 = F_62 ( V_2 , V_47 , & V_17 , & V_25 ,
V_68 , 0 ) ;
else
V_24 = F_60 ( V_2 , V_47 , & V_17 , & V_25 , V_68 ) ;
F_70 ( L_23 ,
V_24 , V_17 , V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
}
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 ) )
goto V_123;
} else {
if ( ! V_24 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 )
goto V_123;
}
}
V_19 = & V_17 -> V_20 [ V_25 ] ;
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( F_3 ( ! V_45 ) ) {
V_24 = - V_12 ;
goto V_123;
}
V_125 = & V_19 -> V_47 ;
if ( F_80 ( V_2 , V_125 ) != F_80 ( V_2 , V_47 ) ||
F_46 ( V_2 , V_125 ) != type ) {
V_24 = - V_49 ;
goto V_70;
}
V_24 = F_36 ( V_2 , V_19 , V_45 ) ;
if ( F_3 ( V_24 ) )
goto V_70;
F_76 ( & V_2 -> V_98 ) ;
return V_45 ;
V_70:
F_6 ( V_45 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return F_15 ( V_24 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_16 * V_29 ;
if ( ! V_2 -> V_29 )
return;
F_18 ( V_2 -> V_150 == V_151 ) ;
V_29 = V_2 -> V_29 ;
do {
struct V_16 * V_17 = V_29 ;
V_29 = V_29 -> V_29 ;
if ( F_19 ( V_17 ) )
F_6 ( V_17 ) ;
} while ( V_29 && V_29 != V_2 -> V_29 );
}
void F_120 ( struct V_1 * V_2 )
{
F_119 ( V_2 ) ;
if ( V_2 -> V_23 . V_17 ) {
long V_25 , V_152 ;
V_25 = F_121 ( & V_2 -> V_40 ) ;
V_152 = F_122 ( V_2 -> V_23 . V_17 ) ;
F_18 ( V_152 == V_25 ) ;
F_123 ( V_25 , & V_41 ) ;
}
F_6 ( V_2 -> V_153 ) ;
F_6 ( V_2 -> V_154 ) ;
F_11 ( V_2 ) ;
}
static struct V_16 * F_124 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_25 = V_17 -> V_21 - 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_25 >= 0 ) {
V_17 = F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_25 = V_17 -> V_36 - 1 ;
V_17 = F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_125 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_25 = V_17 -> V_21 + 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_25 < V_17 -> V_36 ) {
V_17 = F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_17 = F_55 ( V_2 , V_17 , 0 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_126 ( struct V_1 * V_2 ,
union V_64 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 , * V_27 ;
int V_25 , V_75 ;
F_18 ( F_46 ( V_2 , V_47 ) < V_89 ) ;
if ( V_34 < 0 )
return F_15 ( - V_77 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( ! V_17 ) {
V_17 = F_56 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
}
if ( V_2 -> V_23 . V_3 == V_3 && V_2 -> V_23 . V_4 == V_4 )
return V_17 ;
if ( V_34 >= V_17 -> V_34 )
return NULL ;
while ( 1 ) {
F_69 ( V_2 , V_17 , V_47 , & V_25 ) ;
if ( V_25 < 0 ) {
V_17 = F_124 ( V_2 , V_17 ) ;
if ( ! V_17 )
return NULL ;
if ( F_28 ( V_17 ) )
return V_17 ;
F_69 ( V_2 , V_17 , V_47 , & V_25 ) ;
F_18 ( V_25 >= 0 ) ;
}
if ( V_17 -> V_34 == V_34 + 1 )
break;
V_17 = F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_28 ( V_17 ) )
return V_17 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 && V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_55 ( V_2 , V_17 , V_25 ) ;
if ( ! F_30 ( V_2 , V_47 ) )
return NULL ;
V_27 = V_17 ;
V_75 = V_25 ;
while ( 1 ) {
if ( V_25 )
V_25 -= 1 ;
else {
V_17 = F_124 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_28 ( V_17 ) )
return V_17 ;
V_25 = V_17 -> V_36 - 1 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_25 ] . V_47 , V_47 ) < 0 )
break;
}
V_17 = V_27 ;
V_25 = V_75 ;
while ( 1 ) {
if ( ++ V_25 >= V_17 -> V_36 ) {
V_17 = F_125 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_28 ( V_17 ) )
return V_17 ;
V_25 = 0 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_55 ( V_2 , V_17 , V_25 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_25 ] . V_47 , V_47 ) > 0 )
break;
}
return NULL ;
}
int F_127 ( struct V_1 * V_2 , union V_64 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
V_17 = F_126 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
return 0 ;
if ( F_28 ( V_17 ) )
return F_58 ( V_17 ) ;
return F_66 ( V_17 ) ? 1 : 2 ;
}
static int F_128 ( struct V_1 * V_2 , union V_64 * V_47 ,
int V_3 , int V_4 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 , * V_27 ;
int V_25 , V_94 , V_24 , V_75 ;
const int V_155 = ! F_30 ( V_2 , V_47 ) ;
V_94 = F_67 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! V_94 )
return 0 ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
if ( V_155 )
return 0 ;
V_27 = V_17 ;
V_75 = V_25 ;
while ( 1 ) {
V_24 = F_59 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_49 )
break;
if ( V_24 )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ V_25 ] . V_47 ) )
break;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
V_17 = V_27 ;
V_25 = V_75 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 ) {
if ( V_24 == - V_49 )
return 0 ;
return V_24 ;
}
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ V_25 ] . V_47 ) )
break;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , union V_64 * V_47 , int V_34 ,
int V_3 , int V_4 , int V_156 )
{
int V_24 ;
F_75 ( & V_2 -> V_98 ) ;
if ( V_156 ) {
V_24 = F_127 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 == 1 )
V_24 = 0 ;
else if ( V_24 == 2 )
V_24 = 1 ;
else
F_130 ( V_24 != 0 ) ;
} else
V_24 = F_128 ( V_2 , V_47 , V_3 , V_4 ) ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_131 ( struct V_1 * V_2 , union V_64 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_24 = 0 ;
F_75 ( & V_2 -> V_98 ) ;
V_17 = F_126 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
goto V_123;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
V_17 = F_65 ( V_2 , V_17 ) ;
if ( F_28 ( V_17 ) ) {
V_24 = F_58 ( V_17 ) ;
goto V_123;
}
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_132 ( struct V_1 * V_2 , const struct V_157 * V_157 ,
T_3 V_158 )
{
int V_24 , V_25 ;
union V_64 V_142 , V_143 , * V_47 ;
struct V_16 * V_17 ;
unsigned int V_102 ;
if ( ! F_133 ( V_157 -> V_159 ) )
return 0 ;
if ( ! F_134 ( V_2 ) )
return 0 ;
V_102 = ( V_158 + V_160 - 1 ) >> V_161 ;
F_135 ( V_2 , & V_142 , V_157 -> V_162 , V_102 ) ;
F_136 ( V_2 , & V_143 , V_157 -> V_162 ) ;
F_75 ( & V_2 -> V_98 ) ;
V_24 = F_67 ( V_2 , & V_142 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
V_47 = & V_142 ;
goto V_163;
}
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_49 ) {
V_24 = 0 ;
goto V_123;
}
if ( V_24 < 0 )
goto V_123;
F_18 ( V_24 == 0 ) ;
V_47 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( ! F_110 ( V_2 , V_47 , & V_142 , & V_143 ) )
goto V_123;
V_163:
V_102 = F_79 ( V_2 , V_47 ) ;
F_5 ( V_2 , L_37 ,
( unsigned long ) V_157 -> V_162 , V_158 ,
( ( T_3 ) V_102 ) << V_161 ) ;
F_76 ( & V_2 -> V_98 ) ;
F_137 ( V_2 , V_157 ) ;
F_32 () ;
return - V_77 ;
V_123:
F_76 ( & V_2 -> V_98 ) ;
return V_24 ;
}
