static int F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_5 , const struct V_6 * V_7 )
{
if ( F_2 ( V_2 -> V_8 ) != V_5 )
return - 1 ;
if ( F_3 ( V_2 , V_4 ) == 0 )
return - 1 ;
if ( V_2 -> V_9 != V_10 )
return - 1 ;
if ( V_4 -> V_11 || V_4 -> V_12 || V_4 -> V_13 || ! V_4 -> V_14 ||
V_4 -> V_15 || V_4 -> V_16 || V_4 -> V_17 )
return - 1 ;
if ( F_4 ( F_5 ( V_2 ) ) )
return - 1 ;
if ( V_4 -> V_18 != V_19 &&
V_4 -> V_18 != V_20 )
return - 1 ;
if ( V_4 -> V_18 == V_20 ) {
T_1 * V_21 = ( T_1 * ) ( V_4 + 1 ) ;
if ( * V_21 != F_6 ( ( V_22 << 24 ) | ( V_22 << 16 )
| ( V_23 << 8 )
| V_24 ) )
return - 1 ;
V_21 ++ ;
if ( V_7 && F_7 ( F_8 ( V_7 -> V_25 ) ,
F_8 ( * V_21 ) ) )
return - 1 ;
V_21 ++ ;
if ( * V_21 == 0 )
return - 1 ;
}
return 0 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = V_7 -> V_4 ;
T_1 * V_26 ;
T_2 V_27 ;
V_4 -> V_28 = V_7 -> V_29 ;
V_4 -> V_30 = V_7 -> V_31 ;
if ( V_7 -> V_32 ) {
V_26 = ( T_1 * ) ( V_4 + 1 ) ;
* ( V_26 + 2 ) = V_7 -> V_33 ;
}
F_10 ( & V_2 -> V_34 , V_2 -> V_8 , F_11 ( V_7 -> V_35 ) ) ;
V_2 -> V_8 = F_11 ( V_7 -> V_35 ) ;
V_4 -> V_34 = 0 ;
V_27 = F_12 ( V_4 , F_13 ( V_4 ) , 0 ) ;
V_7 -> V_36 = F_14 ( V_7 -> V_36 , V_27 ) ;
V_4 -> V_34 = F_15 ( V_2 -> V_37 , V_2 -> V_38 ,
V_7 -> V_35 -
F_16 ( V_2 ) , V_39 ,
V_7 -> V_36 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
T_2 V_40 ;
T_2 V_27 ;
T_2 V_41 ;
V_40 = ~ F_18 ( V_4 -> V_34 ) ;
V_27 = F_12 ( V_4 , F_13 ( V_4 ) , V_40 ) ;
V_41 = F_19 ( V_2 -> V_37 , V_2 -> V_38 ,
V_5 + F_13 ( V_4 ) ,
V_39 , 0 ) ;
return F_20 ( F_20 ( V_40 , V_27 ) ,
V_41 ) ;
}
static void F_21 ( struct V_6 * V_7 , struct V_42 * V_43 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_44 ;
T_1 * V_45 ;
T_3 V_46 = F_3 ( V_2 , V_4 ) ;
V_44 = F_22 ( V_43 ) -> V_44 ;
V_7 -> V_47 = V_43 ;
V_7 -> V_48 = & ( F_22 ( V_43 ) -> V_49 [ V_44 ] ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_50 = F_8 ( V_4 -> V_51 ) + V_46 ;
V_7 -> V_29 = V_4 -> V_28 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_52 = 1 ;
V_7 -> V_35 = F_2 ( V_2 -> V_8 ) ;
if ( V_4 -> V_18 == 8 ) {
V_45 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_32 = 1 ;
V_7 -> V_25 = * ( V_45 + 1 ) ;
V_7 -> V_33 = * ( V_45 + 2 ) ;
}
V_7 -> V_53 = V_46 ;
V_7 -> V_54 = 1 ;
V_7 -> V_36 = F_17 ( V_2 , V_4 ,
V_46 ) ;
}
static inline void F_23 ( struct V_6 * V_7 )
{
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
}
static void F_24 ( struct V_6 * V_7 , struct V_1 * V_2 ,
struct V_3 * V_4 , int V_46 )
{
struct V_42 * V_47 = V_7 -> V_47 ;
T_1 * V_21 ;
V_7 -> V_52 ++ ;
V_7 -> V_35 += V_46 ;
V_7 -> V_50 += V_46 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_29 = V_4 -> V_28 ;
if ( V_7 -> V_32 ) {
V_21 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_33 = * ( V_21 + 2 ) ;
}
V_7 -> V_36 = F_25 ( V_7 -> V_36 ,
F_17 ( V_2 , V_4 ,
V_46 ) ,
V_47 -> V_5 ) ;
V_47 -> V_5 += V_46 ;
V_47 -> V_55 += V_46 ;
if ( V_46 > V_7 -> V_53 )
V_7 -> V_53 = V_46 ;
}
static void F_26 ( struct V_6 * V_7 , struct V_42 * V_43 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_47 = V_7 -> V_47 ;
int V_46 = F_3 ( V_2 , V_4 ) ;
F_24 ( V_7 , V_2 , V_4 , V_46 ) ;
F_27 ( V_43 , ( V_43 -> V_5 - V_46 ) ) ;
V_47 -> V_56 += V_43 -> V_56 ;
if ( V_7 -> V_57 )
V_7 -> V_57 -> V_58 = V_43 ;
else
F_22 ( V_47 ) -> V_59 = V_43 ;
V_7 -> V_57 = V_43 ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ( V_7 -> V_2 -> V_37 != V_2 -> V_37 ) ||
( V_7 -> V_2 -> V_38 != V_2 -> V_38 ) ||
( V_7 -> V_4 -> V_60 != V_4 -> V_60 ) ||
( V_7 -> V_4 -> V_61 != V_4 -> V_61 ) )
return - 1 ;
return 0 ;
}
static struct V_6 * F_29 ( struct V_62 * V_63 ,
struct V_6 * V_64 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = NULL ;
struct V_6 * V_65 ;
int V_66 = V_63 -> V_66 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_65 = & V_64 [ V_67 ] ;
if ( V_65 -> V_54 )
if ( ! F_28 ( V_65 , V_2 , V_4 ) ) {
V_7 = V_65 ;
goto V_68;
}
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( ! V_64 [ V_67 ] . V_54 ) {
V_7 = & V_64 [ V_67 ] ;
goto V_68;
}
}
F_30 ( V_63 , V_69 ) ;
V_68:
return V_7 ;
}
static void F_31 ( struct V_62 * V_63 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_52 > 1 )
F_9 ( V_7 ) ;
F_22 ( V_7 -> V_47 ) -> V_70 = V_7 -> V_53 ;
if ( V_63 -> V_71 & V_72 )
F_32 ( V_7 -> V_47 ) ;
else
F_33 ( V_7 -> V_47 ) ;
F_30 ( V_63 , V_73 ) ;
F_23 ( V_7 ) ;
}
static int F_34 ( struct V_62 * V_63 , struct V_42 * V_43 ,
void * V_74 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_75 ;
int V_76 = 0 ;
if ( ! V_63 -> V_77 ||
V_63 -> V_77 ( V_43 , ( void * ) & V_2 , ( void * ) & V_4 ,
& V_75 , V_74 ) )
goto V_68;
if ( ! ( V_75 & V_78 ) || ! ( V_75 & V_79 ) )
goto V_68;
V_7 = F_29 ( V_63 , V_63 -> V_64 , V_2 , V_4 ) ;
if ( ! V_7 )
goto V_68;
if ( ( V_43 -> V_80 == F_11 ( V_81 ) ) &&
! ( V_63 -> V_71 & V_82 ) )
V_76 = V_83 ;
if ( ! V_7 -> V_54 ) {
if ( F_1 ( V_2 , V_4 , V_43 -> V_5 - V_76 , NULL ) )
goto V_68;
V_43 -> V_84 = V_63 -> V_85 ;
F_21 ( V_7 , V_43 , V_2 , V_4 ) ;
F_30 ( V_63 , V_86 ) ;
return 0 ;
}
if ( V_7 -> V_50 != F_8 ( V_4 -> V_51 ) )
goto V_87;
if ( F_1 ( V_2 , V_4 , V_43 -> V_5 , V_7 ) )
goto V_87;
F_26 ( V_7 , V_43 , V_2 , V_4 ) ;
F_30 ( V_63 , V_86 ) ;
if ( ( V_7 -> V_52 >= V_63 -> V_88 ) ||
V_7 -> V_47 -> V_5 > ( 0xFFFF - V_63 -> V_89 -> V_90 ) )
F_31 ( V_63 , V_7 ) ;
return 0 ;
V_87:
F_31 ( V_63 , V_7 ) ;
V_68:
return 1 ;
}
void F_35 ( struct V_62 * V_63 ,
struct V_42 * V_43 ,
void * V_74 )
{
if ( F_34 ( V_63 , V_43 , V_74 ) ) {
if ( V_63 -> V_71 & V_72 )
F_32 ( V_43 ) ;
else
F_33 ( V_43 ) ;
}
}
void F_36 ( struct V_62 * V_63 )
{
int V_67 ;
struct V_6 * V_7 = V_63 -> V_64 ;
for ( V_67 = 0 ; V_67 < V_63 -> V_66 ; V_67 ++ ) {
if ( V_7 [ V_67 ] . V_54 )
F_31 ( V_63 , & V_7 [ V_67 ] ) ;
}
}
