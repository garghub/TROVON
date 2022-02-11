static T_1 *
F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_1 = F_2 ( V_1 , V_3 -> V_4 . V_5 ,
sizeof( V_3 -> V_4 . V_5 ) ) ;
V_1 = F_3 ( V_1 , & V_3 -> V_6 ) ;
V_1 = F_3 ( V_1 , & V_3 -> V_7 ) ;
return V_1 ;
}
static int
F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
T_1 * V_1 = F_5 ( V_11 , 1 ) ;
if ( ! V_1 )
return - V_12 ;
V_9 -> V_13 = F_6 ( * V_1 ++ ) ;
V_1 = F_5 ( V_11 , V_9 -> V_13 ) ;
if ( ! V_1 )
return - V_12 ;
V_9 -> V_14 = V_1 ;
return 0 ;
}
static int
F_7 ( struct V_15 * V_16 ,
struct V_10 * V_11 )
{
T_1 * V_1 = F_5 ( V_11 , 32 + 4 + 4 ) ;
int V_17 ;
if ( ! V_1 )
return - V_18 ;
V_1 = F_1 ( V_1 , & V_16 -> V_19 ) ;
V_16 -> V_20 = F_8 ( V_1 ++ ) ;
V_16 -> V_21 = F_8 ( V_1 ) ;
V_17 = F_4 ( & V_16 -> V_22 , V_11 ) ;
if ( F_9 ( V_17 ) )
return V_17 ;
V_17 = F_4 ( & V_16 -> V_23 , V_11 ) ;
return V_17 ;
}
static inline int
F_10 ( void )
{
return 4 + 8 + 4 + 4 + 4 + 4 ;
}
static T_1 *
F_11 ( T_1 * V_1 , struct V_24 * V_25 )
{
V_25 -> V_26 = F_8 ( V_1 ++ ) ;
V_1 = F_3 ( V_1 , & V_25 -> V_27 ) ;
V_25 -> V_28 = F_8 ( V_1 ++ ) ;
V_25 -> V_29 = F_8 ( V_1 ++ ) ;
V_25 -> V_30 = F_8 ( V_1 ++ ) ;
V_25 -> V_31 = F_8 ( V_1 ++ ) ;
F_12 ( L_1
L_2 ,
V_32 ,
V_25 -> V_26 ,
( unsigned long long ) V_25 -> V_27 ,
V_25 -> V_28 ,
V_25 -> V_29 ,
V_25 -> V_30 ,
V_25 -> V_31 ) ;
return V_1 ;
}
int F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_10 * V_11 )
{
T_1 * V_1 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_1 = F_5 ( V_11 , F_10 () + 4 + 4 ) ;
if ( F_9 ( ! V_1 ) )
return - V_12 ;
V_1 = F_11 ( V_1 , & V_34 -> V_37 ) ;
V_34 -> V_38 = F_8 ( V_1 ++ ) ;
V_34 -> V_39 = F_8 ( V_1 ++ ) ;
F_12 ( L_3 , V_32 ,
V_34 -> V_38 , V_34 -> V_39 ) ;
V_36 -> V_40 = V_34 -> V_39 ;
return 0 ;
}
bool F_14 ( struct V_15 * V_16 ,
struct V_35 * V_36 , struct V_10 * V_11 ,
int * V_41 )
{
F_15 ( V_36 -> V_42 > V_36 -> V_40 ) ;
if ( V_36 -> V_42 == V_36 -> V_40 )
return false ;
* V_41 = F_7 ( V_16 , V_11 ) ;
if ( F_9 ( * V_41 ) ) {
F_12 ( L_4
L_5 , V_32 , * V_41 ,
V_36 -> V_42 , V_36 -> V_40 ) ;
return false ;
}
F_12 ( L_6
L_7 ,
V_32 ,
F_16 ( & V_16 -> V_19 . V_4 ) ,
F_17 ( & V_16 -> V_19 . V_4 ) ,
V_16 -> V_19 . V_6 ,
V_16 -> V_19 . V_7 ,
V_16 -> V_22 . V_13 , V_16 -> V_23 . V_13 ) ;
V_36 -> V_42 ++ ;
return true ;
}
static T_1 *
F_18 ( T_1 * V_1 , struct V_43 * V_44 )
{
V_44 -> V_45 = F_8 ( V_1 ++ ) ;
V_44 -> V_5 = ( char * ) V_1 ;
V_1 += F_19 ( V_44 -> V_45 ) ;
return V_1 ;
}
static T_1 *
F_20 ( T_1 * V_1 , struct V_46 * V_47 )
{
T_2 V_48 ;
V_48 = F_8 ( V_1 ++ ) ;
V_47 -> V_48 = V_48 ;
switch ( V_48 ) {
case V_49 :
case V_50 :
V_1 = F_18 ( V_1 , & V_47 -> V_51 ) ;
}
return V_1 ;
}
static T_1 *
F_21 ( T_1 * V_1 , struct V_52 * V_53 )
{
V_1 = F_18 ( V_1 , & V_53 -> V_54 ) ;
V_1 = F_18 ( V_1 , & V_53 -> V_55 ) ;
return V_1 ;
}
static T_1 *
F_22 ( T_1 * V_1 , struct V_56 * V_57 )
{
T_2 V_58 ;
V_58 = F_8 ( V_1 ++ ) ;
V_57 -> V_58 = V_58 ;
if ( V_58 )
V_1 = F_21 ( V_1 , & V_57 -> V_59 ) ;
return V_1 ;
}
static T_1 *
F_23 ( T_1 * V_1 ,
struct V_8 * V_9 )
{
V_9 -> V_13 = F_6 ( * V_1 ++ ) ;
V_9 -> V_14 = V_1 ;
return V_1 + F_19 ( V_9 -> V_13 ) ;
}
static T_1 *
F_24 ( T_1 * V_1 , struct V_15 * V_16 )
{
V_1 = F_1 ( V_1 , & V_16 -> V_19 ) ;
V_16 -> V_20 = F_8 ( V_1 ++ ) ;
V_16 -> V_21 = F_8 ( V_1 ++ ) ;
V_1 = F_23 ( V_1 , & V_16 -> V_22 ) ;
V_1 = F_23 ( V_1 , & V_16 -> V_23 ) ;
return V_1 ;
}
void F_25 (
struct V_60 * V_61 , T_1 * V_1 )
{
V_1 = F_20 ( V_1 , & V_61 -> V_62 ) ;
V_1 = F_22 ( V_1 , & V_61 -> V_63 ) ;
V_1 = F_2 ( V_1 , V_61 -> V_64 ,
sizeof( V_61 -> V_64 ) ) ;
V_1 = F_18 ( V_1 , & V_61 -> V_65 ) ;
V_1 = F_24 ( V_1 , & V_61 -> V_66 ) ;
V_1 = F_18 ( V_1 , & V_61 -> V_67 ) ;
V_61 -> V_67 . V_5 [ V_61 -> V_67 . V_45 ] = 0 ;
}
int
F_26 ( struct V_10 * V_11 ,
struct V_68 * V_69 )
{
T_1 * V_1 = F_27 ( V_11 , 4 + 8 + 4 ) ;
if ( ! V_1 )
return - V_70 ;
* V_1 ++ = F_28 ( V_69 -> V_71 ) ;
if ( V_69 -> V_71 )
V_1 = F_29 ( V_1 , V_69 -> V_72 ) ;
* V_1 ++ = F_28 ( V_69 -> V_73 ) ;
return 0 ;
}
static inline T_1 *
F_30 ( T_1 * V_1 , struct V_2 * V_74 )
{
V_1 = F_31 ( V_1 , & V_74 -> V_4 . V_5 ,
sizeof( V_74 -> V_4 . V_5 ) ) ;
V_1 = F_29 ( V_1 , V_74 -> V_6 ) ;
V_1 = F_29 ( V_1 , V_74 -> V_7 ) ;
return V_1 ;
}
void F_32 ( T_1 * V_1 , struct V_75 * V_76 )
{
V_1 = F_30 ( V_1 , & V_76 -> V_77 ) ;
V_1 = F_29 ( V_1 , V_76 -> V_78 ) ;
V_1 = F_29 ( V_1 , V_76 -> V_79 ) ;
* V_1 ++ = F_28 ( V_76 -> V_80 ) ;
* V_1 = F_28 ( V_76 -> V_81 ) ;
}
T_1 * F_33 ( struct V_10 * V_11 )
{
T_1 * V_1 ;
V_1 = F_27 ( V_11 , 32 + 24 ) ;
if ( F_9 ( ! V_1 ) )
F_12 ( L_8 , V_32 ) ;
return V_1 ;
}
