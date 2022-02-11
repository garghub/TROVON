static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_3 )
return V_3 ;
memcpy ( V_5 -> V_8 , V_7 -> V_9 , V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_11 * V_12 , const T_1 * V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 = F_5 ( V_12 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
unsigned int V_19 = F_7 () ;
int V_3 ;
V_3 = F_8 ( V_16 , V_13 , V_14 ) ;
if ( V_3 )
return V_3 ;
switch ( V_14 ) {
case V_20 * 2 :
memcpy ( V_18 -> V_21 . V_22 . V_13 , V_13 , V_14 ) ;
break;
case V_23 * 2 :
if ( V_19 > F_9 ( 3 , 0 ) )
memcpy ( V_18 -> V_21 . V_22 . V_13 , V_13 , V_14 ) ;
break;
}
V_18 -> V_21 . V_22 . V_14 = V_14 / 2 ;
F_10 ( & V_18 -> V_21 . V_22 . V_24 , V_18 -> V_21 . V_22 . V_13 , V_14 ) ;
return F_11 ( V_18 -> V_21 . V_22 . V_25 , V_13 , V_14 ) ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_26 )
{
struct V_17 * V_18 = F_6 ( V_5 -> V_27 . V_12 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned int V_19 = F_7 () ;
unsigned int V_28 = 0 ;
unsigned int V_29 ;
T_2 V_30 ;
int V_3 ;
if ( ! V_18 -> V_21 . V_22 . V_14 )
return - V_31 ;
if ( V_5 -> V_32 & ( V_10 - 1 ) )
return - V_31 ;
if ( ! V_5 -> V_8 )
return - V_31 ;
V_30 = V_33 ;
for ( V_29 = 0 ; V_29 < F_13 ( V_34 ) ; V_29 ++ ) {
if ( V_5 -> V_32 == V_34 [ V_29 ] . V_35 ) {
V_30 = V_29 ;
break;
}
}
if ( V_30 == V_33 )
V_28 = 1 ;
if ( ( V_19 < F_9 ( 5 , 0 ) ) &&
( V_18 -> V_21 . V_22 . V_14 != V_20 ) )
V_28 = 1 ;
if ( ( V_18 -> V_21 . V_22 . V_14 != V_20 ) &&
( V_18 -> V_21 . V_22 . V_14 != V_23 ) )
V_28 = 1 ;
if ( V_28 ) {
F_14 ( V_36 , V_18 -> V_21 . V_22 . V_25 ) ;
F_15 ( V_36 , V_18 -> V_21 . V_22 . V_25 ) ;
F_16 ( V_36 , V_5 -> V_27 . V_37 ,
NULL , NULL ) ;
F_17 ( V_36 , V_5 -> V_38 , V_5 -> V_39 ,
V_5 -> V_32 , V_5 -> V_8 ) ;
V_3 = V_26 ? F_18 ( V_36 ) :
F_19 ( V_36 ) ;
F_20 ( V_36 ) ;
return V_3 ;
}
memcpy ( V_7 -> V_9 , V_5 -> V_8 , V_10 ) ;
F_10 ( & V_7 -> V_40 , V_7 -> V_9 , V_10 ) ;
memset ( & V_7 -> V_41 , 0 , sizeof( V_7 -> V_41 ) ) ;
F_21 ( & V_7 -> V_41 . V_42 ) ;
V_7 -> V_41 . V_43 = V_44 ;
V_7 -> V_41 . V_21 . V_45 . type = V_46 ;
V_7 -> V_41 . V_21 . V_45 . V_47 = ( V_26 ) ? V_48
: V_49 ;
V_7 -> V_41 . V_21 . V_45 . V_30 = V_30 ;
V_7 -> V_41 . V_21 . V_45 . V_13 = & V_18 -> V_21 . V_22 . V_24 ;
V_7 -> V_41 . V_21 . V_45 . V_14 = V_18 -> V_21 . V_22 . V_14 ;
V_7 -> V_41 . V_21 . V_45 . V_9 = & V_7 -> V_40 ;
V_7 -> V_41 . V_21 . V_45 . V_50 = V_10 ;
V_7 -> V_41 . V_21 . V_45 . V_38 = V_5 -> V_38 ;
V_7 -> V_41 . V_21 . V_45 . V_51 = V_5 -> V_32 ;
V_7 -> V_41 . V_21 . V_45 . V_39 = V_5 -> V_39 ;
V_3 = F_22 ( & V_5 -> V_27 , & V_7 -> V_41 ) ;
return V_3 ;
}
static int F_23 ( struct V_4 * V_5 )
{
return F_12 ( V_5 , 1 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
return F_12 ( V_5 , 0 ) ;
}
static int F_25 ( struct V_15 * V_12 )
{
struct V_17 * V_18 = F_6 ( V_12 ) ;
struct V_52 * V_53 ;
V_18 -> V_54 = F_1 ;
V_18 -> V_21 . V_22 . V_14 = 0 ;
V_53 = F_26 ( L_1 , 0 ,
V_55 |
V_56 ) ;
if ( F_27 ( V_53 ) ) {
F_28 ( L_2 ) ;
return F_29 ( V_53 ) ;
}
V_18 -> V_21 . V_22 . V_25 = V_53 ;
V_12 -> V_57 . V_58 = sizeof( struct V_6 ) ;
return 0 ;
}
static void F_30 ( struct V_15 * V_12 )
{
struct V_17 * V_18 = F_6 ( V_12 ) ;
F_31 ( V_18 -> V_21 . V_22 . V_25 ) ;
}
static int F_32 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_3 ;
V_64 = F_33 ( sizeof( * V_64 ) , V_67 ) ;
if ( ! V_64 )
return - V_68 ;
F_21 ( & V_64 -> V_42 ) ;
V_66 = & V_64 -> V_66 ;
snprintf ( V_66 -> V_69 , V_70 , L_3 , V_62 -> V_71 ) ;
snprintf ( V_66 -> V_72 , V_70 , L_3 ,
V_62 -> V_73 ) ;
V_66 -> V_74 = V_75 | V_55 |
V_76 |
V_56 ;
V_66 -> V_77 = V_10 ;
V_66 -> V_78 = sizeof( struct V_17 ) ;
V_66 -> V_79 = V_80 ;
V_66 -> V_81 = & V_82 ;
V_66 -> V_83 . V_84 = F_4 ;
V_66 -> V_83 . V_26 = F_23 ;
V_66 -> V_83 . V_85 = F_24 ;
V_66 -> V_83 . V_86 = V_87 * 2 ;
V_66 -> V_83 . V_88 = V_89 * 2 ;
V_66 -> V_83 . V_90 = V_10 ;
V_66 -> V_91 = F_25 ;
V_66 -> V_92 = F_30 ;
V_66 -> V_93 = V_94 ;
V_3 = F_34 ( V_66 ) ;
if ( V_3 ) {
F_35 ( L_4 ,
V_66 -> V_69 , V_3 ) ;
F_36 ( V_64 ) ;
return V_3 ;
}
F_37 ( & V_64 -> V_42 , V_60 ) ;
return 0 ;
}
int F_38 ( struct V_59 * V_60 )
{
int V_95 , V_3 ;
for ( V_95 = 0 ; V_95 < F_13 ( V_96 ) ; V_95 ++ ) {
V_3 = F_32 ( V_60 , & V_96 [ V_95 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
