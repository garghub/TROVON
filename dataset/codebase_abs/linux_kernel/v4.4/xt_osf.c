static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * const V_8 [] )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = NULL , * V_13 ;
int V_14 = 0 ;
if ( ! V_8 [ V_15 ] )
return - V_16 ;
if ( ! ( V_6 -> V_17 & V_18 ) )
return - V_16 ;
V_10 = F_2 ( V_8 [ V_15 ] ) ;
V_12 = F_3 ( sizeof( struct V_11 ) , V_19 ) ;
if ( ! V_12 )
return - V_20 ;
memcpy ( & V_12 -> V_21 , V_10 , sizeof( struct V_9 ) ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_13 -> V_21 , V_10 , sizeof( struct V_9 ) ) )
continue;
F_5 ( V_12 ) ;
V_12 = NULL ;
if ( V_6 -> V_17 & V_22 )
V_14 = - V_23 ;
break;
}
if ( V_12 )
F_6 ( & V_12 -> V_24 , & V_25 [ ! ! V_10 -> V_26 ] ) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * const V_8 [] )
{
struct V_9 * V_10 ;
struct V_11 * V_13 ;
int V_14 = - V_27 ;
if ( ! V_8 [ V_15 ] )
return - V_16 ;
V_10 = F_2 ( V_8 [ V_15 ] ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_13 -> V_21 , V_10 , sizeof( struct V_9 ) ) )
continue;
F_8 ( & V_13 -> V_24 ) ;
F_9 ( V_13 , V_28 ) ;
V_14 = 0 ;
break;
}
return V_14 ;
}
static inline int F_10 ( const struct V_3 * V_4 , const struct V_29 * V_30 ,
unsigned char V_31 )
{
const struct V_32 * V_33 = F_11 ( V_4 ) ;
if ( V_30 -> V_34 & V_35 ) {
if ( V_30 -> V_36 == V_37 )
return V_33 -> V_36 == V_31 ;
if ( V_30 -> V_36 == V_38 )
return 1 ;
else if ( V_33 -> V_36 <= V_31 )
return 1 ;
else {
struct V_39 * V_40 = F_12 ( V_4 -> V_41 ) ;
int V_42 = 0 ;
F_13 (in_dev) {
if ( F_14 ( V_33 -> V_43 , V_44 ) ) {
V_42 = ( V_33 -> V_36 == V_31 ) ;
break;
}
}
F_15 ( V_40 ) ;
return V_42 ;
}
}
return V_33 -> V_36 == V_31 ;
}
static bool
F_16 ( const struct V_3 * V_4 , struct V_45 * V_46 )
{
const struct V_29 * V_30 = V_46 -> V_47 ;
const struct V_32 * V_33 = F_11 ( V_4 ) ;
const struct V_48 * V_49 ;
struct V_48 V_50 ;
int V_51 = V_52 , V_53 = 0 ;
unsigned int V_54 = 0 , V_55 = 0 ;
T_1 V_56 , V_57 , V_58 = 0 ;
bool V_26 ;
const unsigned char * V_59 = NULL , * V_60 = NULL ;
unsigned char V_61 [ V_62 ] ;
const struct V_11 * V_12 ;
const struct V_9 * V_10 ;
struct V_63 * V_63 = V_46 -> V_63 ;
if ( ! V_30 )
return false ;
V_49 = F_17 ( V_4 , F_18 ( V_4 ) , sizeof( struct V_48 ) , & V_50 ) ;
if ( ! V_49 )
return false ;
if ( ! V_49 -> V_64 )
return false ;
V_57 = F_19 ( V_33 -> V_65 ) ;
V_26 = F_19 ( V_33 -> V_66 ) & V_67 ;
V_56 = F_19 ( V_49 -> V_56 ) ;
if ( V_49 -> V_68 * 4 > sizeof( struct V_48 ) ) {
V_54 = V_49 -> V_68 * 4 - sizeof( struct V_48 ) ;
V_60 = V_59 = F_17 ( V_4 , F_18 ( V_4 ) +
sizeof( struct V_48 ) , V_54 , V_61 ) ;
}
F_20 () ;
F_21 (kf, &xt_osf_fingers[df], finger_entry) {
int V_69 , V_70 ;
V_10 = & V_12 -> V_21 ;
if ( ! ( V_30 -> V_34 & V_71 ) && strcmp ( V_30 -> V_72 , V_10 -> V_72 ) )
continue;
V_59 = V_60 ;
V_51 = V_52 ;
if ( V_57 != V_10 -> V_73 || ! F_10 ( V_4 , V_30 , V_10 -> V_36 ) )
continue;
if ( V_10 -> V_74 . V_75 >= V_76 )
continue;
V_69 = 0 ;
for ( V_70 = 0 ; V_70 < V_10 -> V_77 ; ++ V_70 )
V_69 += V_10 -> V_78 [ V_70 ] . V_79 ;
if ( V_69 > V_62 ||
V_54 > V_62 ||
V_54 != V_69 )
continue;
V_55 = V_10 -> V_74 . V_75 ;
for ( V_70 = 0 ; V_70 < V_10 -> V_77 ; ++ V_70 ) {
if ( V_10 -> V_78 [ V_70 ] . V_80 == ( * V_59 ) ) {
T_2 V_81 = V_10 -> V_78 [ V_70 ] . V_79 ;
const T_3 * V_82 = V_59 + V_81 ;
int V_83 = 0 ;
V_51 = V_84 ;
switch ( * V_59 ) {
case V_85 :
V_58 = V_59 [ 3 ] ;
V_58 <<= 8 ;
V_58 |= V_59 [ 2 ] ;
V_58 = F_19 ( ( V_86 V_87 ) V_58 ) ;
break;
case V_88 :
V_83 = 1 ;
break;
}
V_59 = V_82 ;
} else
V_51 = V_89 ;
if ( V_51 != V_84 )
break;
}
if ( V_51 != V_89 ) {
V_51 = V_52 ;
switch ( V_55 ) {
case V_90 :
if ( V_10 -> V_74 . V_91 == 0 || V_56 == V_10 -> V_74 . V_91 )
V_51 = V_84 ;
break;
case V_92 :
#define F_22 1460
#define F_23 1448
if ( V_56 == V_10 -> V_74 . V_91 * V_58 ||
V_56 == V_10 -> V_74 . V_91 * F_22 ||
V_56 == V_10 -> V_74 . V_91 * F_23 )
V_51 = V_84 ;
break;
case V_93 :
if ( V_56 == V_10 -> V_74 . V_91 * ( V_58 + 40 ) ||
V_56 == V_10 -> V_74 . V_91 * ( F_22 + 40 ) ||
V_56 == V_10 -> V_74 . V_91 * ( F_23 + 40 ) )
V_51 = V_84 ;
break;
case V_94 :
if ( ( V_56 % V_10 -> V_74 . V_91 ) == 0 )
V_51 = V_84 ;
break;
}
}
if ( V_51 != V_84 )
continue;
V_53 ++ ;
if ( V_30 -> V_34 & V_71 )
F_24 ( V_63 , V_46 -> V_95 , V_46 -> V_96 , V_4 ,
V_46 -> V_97 , V_46 -> V_98 , NULL ,
L_1 ,
V_10 -> V_72 , V_10 -> V_99 , V_10 -> V_100 ,
& V_33 -> V_43 , F_19 ( V_49 -> V_101 ) ,
& V_33 -> V_102 , F_19 ( V_49 -> V_103 ) ,
V_10 -> V_36 - V_33 -> V_36 ) ;
if ( ( V_30 -> V_34 & V_71 ) &&
V_30 -> V_104 == V_105 )
break;
}
F_25 () ;
if ( ! V_53 && ( V_30 -> V_34 & V_71 ) )
F_24 ( V_63 , V_46 -> V_95 , V_46 -> V_96 , V_4 , V_46 -> V_97 ,
V_46 -> V_98 , NULL ,
L_2 ,
& V_33 -> V_43 , F_19 ( V_49 -> V_101 ) ,
& V_33 -> V_102 , F_19 ( V_49 -> V_103 ) ) ;
if ( V_53 )
V_51 = V_84 ;
return V_51 == V_84 ;
}
static int T_4 F_26 ( void )
{
int V_14 = - V_16 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < F_27 ( V_25 ) ; ++ V_106 )
F_28 ( & V_25 [ V_106 ] ) ;
V_14 = F_29 ( & V_107 ) ;
if ( V_14 < 0 ) {
F_30 ( L_3 , V_14 ) ;
goto V_108;
}
V_14 = F_31 ( & V_109 ) ;
if ( V_14 ) {
F_30 ( L_4
L_5 , V_14 ) ;
goto V_110;
}
return 0 ;
V_110:
F_32 ( & V_107 ) ;
V_108:
return V_14 ;
}
static void T_5 F_33 ( void )
{
struct V_11 * V_10 ;
int V_106 ;
F_32 ( & V_107 ) ;
F_34 ( & V_109 ) ;
F_20 () ;
for ( V_106 = 0 ; V_106 < F_27 ( V_25 ) ; ++ V_106 ) {
F_21 (f, &xt_osf_fingers[i], finger_entry) {
F_8 ( & V_10 -> V_24 ) ;
F_9 ( V_10 , V_28 ) ;
}
}
F_25 () ;
F_35 () ;
}
