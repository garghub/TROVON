static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL , * V_16 ;
int V_17 = 0 ;
if ( ! V_9 [ V_18 ] )
return - V_19 ;
if ( ! ( V_7 -> V_20 & V_21 ) )
return - V_19 ;
V_13 = F_2 ( V_9 [ V_18 ] ) ;
V_15 = F_3 ( sizeof( struct V_14 ) , V_22 ) ;
if ( ! V_15 )
return - V_23 ;
memcpy ( & V_15 -> V_24 , V_13 , sizeof( struct V_12 ) ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_16 -> V_24 , V_13 , sizeof( struct V_12 ) ) )
continue;
F_5 ( V_15 ) ;
V_15 = NULL ;
if ( V_7 -> V_20 & V_25 )
V_17 = - V_26 ;
break;
}
if ( V_15 )
F_6 ( & V_15 -> V_27 , & V_28 [ ! ! V_13 -> V_29 ] ) ;
return V_17 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_16 ;
int V_17 = - V_30 ;
if ( ! V_9 [ V_18 ] )
return - V_19 ;
V_13 = F_2 ( V_9 [ V_18 ] ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_16 -> V_24 , V_13 , sizeof( struct V_12 ) ) )
continue;
F_8 ( & V_16 -> V_27 ) ;
F_9 ( V_16 , V_31 ) ;
V_17 = 0 ;
break;
}
return V_17 ;
}
static inline int F_10 ( const struct V_4 * V_5 , const struct V_32 * V_33 ,
unsigned char V_34 )
{
const struct V_35 * V_36 = F_11 ( V_5 ) ;
if ( V_33 -> V_37 & V_38 ) {
if ( V_33 -> V_39 == V_40 )
return V_36 -> V_39 == V_34 ;
if ( V_33 -> V_39 == V_41 )
return 1 ;
else if ( V_36 -> V_39 <= V_34 )
return 1 ;
else {
struct V_42 * V_43 = F_12 ( V_5 -> V_44 ) ;
int V_45 = 0 ;
F_13 (in_dev) {
if ( F_14 ( V_36 -> V_46 , V_47 ) ) {
V_45 = ( V_36 -> V_39 == V_34 ) ;
break;
}
}
F_15 ( V_43 ) ;
return V_45 ;
}
}
return V_36 -> V_39 == V_34 ;
}
static bool
F_16 ( const struct V_4 * V_5 , struct V_48 * V_49 )
{
const struct V_32 * V_33 = V_49 -> V_50 ;
const struct V_35 * V_36 = F_11 ( V_5 ) ;
const struct V_51 * V_52 ;
struct V_51 V_53 ;
int V_54 = V_55 , V_56 = 0 ;
unsigned int V_57 = 0 , V_58 = 0 ;
T_1 V_59 , V_60 , V_61 = 0 ;
bool V_29 ;
const unsigned char * V_62 = NULL , * V_63 = NULL ;
unsigned char V_64 [ V_65 ] ;
const struct V_14 * V_15 ;
const struct V_12 * V_13 ;
struct V_1 * V_1 = F_17 ( V_49 ) ;
if ( ! V_33 )
return false ;
V_52 = F_18 ( V_5 , F_19 ( V_5 ) , sizeof( struct V_51 ) , & V_53 ) ;
if ( ! V_52 )
return false ;
if ( ! V_52 -> V_66 )
return false ;
V_60 = F_20 ( V_36 -> V_67 ) ;
V_29 = F_20 ( V_36 -> V_68 ) & V_69 ;
V_59 = F_20 ( V_52 -> V_59 ) ;
if ( V_52 -> V_70 * 4 > sizeof( struct V_51 ) ) {
V_57 = V_52 -> V_70 * 4 - sizeof( struct V_51 ) ;
V_63 = V_62 = F_18 ( V_5 , F_19 ( V_5 ) +
sizeof( struct V_51 ) , V_57 , V_64 ) ;
}
F_21 () ;
F_22 (kf, &xt_osf_fingers[df], finger_entry) {
int V_71 , V_72 ;
V_13 = & V_15 -> V_24 ;
if ( ! ( V_33 -> V_37 & V_73 ) && strcmp ( V_33 -> V_74 , V_13 -> V_74 ) )
continue;
V_62 = V_63 ;
V_54 = V_55 ;
if ( V_60 != V_13 -> V_75 || ! F_10 ( V_5 , V_33 , V_13 -> V_39 ) )
continue;
if ( V_13 -> V_76 . V_77 >= V_78 )
continue;
V_71 = 0 ;
for ( V_72 = 0 ; V_72 < V_13 -> V_79 ; ++ V_72 )
V_71 += V_13 -> V_80 [ V_72 ] . V_81 ;
if ( V_71 > V_65 ||
V_57 > V_65 ||
V_57 != V_71 )
continue;
V_58 = V_13 -> V_76 . V_77 ;
for ( V_72 = 0 ; V_72 < V_13 -> V_79 ; ++ V_72 ) {
if ( V_13 -> V_80 [ V_72 ] . V_82 == ( * V_62 ) ) {
T_2 V_83 = V_13 -> V_80 [ V_72 ] . V_81 ;
const T_3 * V_84 = V_62 + V_83 ;
V_54 = V_85 ;
switch ( * V_62 ) {
case V_86 :
V_61 = V_62 [ 3 ] ;
V_61 <<= 8 ;
V_61 |= V_62 [ 2 ] ;
V_61 = F_20 ( ( V_87 V_88 ) V_61 ) ;
break;
case V_89 :
break;
}
V_62 = V_84 ;
} else
V_54 = V_90 ;
if ( V_54 != V_85 )
break;
}
if ( V_54 != V_90 ) {
V_54 = V_55 ;
switch ( V_58 ) {
case V_91 :
if ( V_13 -> V_76 . V_92 == 0 || V_59 == V_13 -> V_76 . V_92 )
V_54 = V_85 ;
break;
case V_93 :
#define F_23 1460
#define F_24 1448
if ( V_59 == V_13 -> V_76 . V_92 * V_61 ||
V_59 == V_13 -> V_76 . V_92 * F_23 ||
V_59 == V_13 -> V_76 . V_92 * F_24 )
V_54 = V_85 ;
break;
case V_94 :
if ( V_59 == V_13 -> V_76 . V_92 * ( V_61 + 40 ) ||
V_59 == V_13 -> V_76 . V_92 * ( F_23 + 40 ) ||
V_59 == V_13 -> V_76 . V_92 * ( F_24 + 40 ) )
V_54 = V_85 ;
break;
case V_95 :
if ( ( V_59 % V_13 -> V_76 . V_92 ) == 0 )
V_54 = V_85 ;
break;
}
}
if ( V_54 != V_85 )
continue;
V_56 ++ ;
if ( V_33 -> V_37 & V_73 )
F_25 ( V_1 , F_26 ( V_49 ) , F_27 ( V_49 ) , V_5 ,
F_28 ( V_49 ) , F_29 ( V_49 ) , NULL ,
L_1 ,
V_13 -> V_74 , V_13 -> V_96 , V_13 -> V_97 ,
& V_36 -> V_46 , F_20 ( V_52 -> V_98 ) ,
& V_36 -> V_99 , F_20 ( V_52 -> V_100 ) ,
V_13 -> V_39 - V_36 -> V_39 ) ;
if ( ( V_33 -> V_37 & V_73 ) &&
V_33 -> V_101 == V_102 )
break;
}
F_30 () ;
if ( ! V_56 && ( V_33 -> V_37 & V_73 ) )
F_25 ( V_1 , F_26 ( V_49 ) , F_27 ( V_49 ) , V_5 , F_28 ( V_49 ) ,
F_29 ( V_49 ) , NULL ,
L_2 ,
& V_36 -> V_46 , F_20 ( V_52 -> V_98 ) ,
& V_36 -> V_99 , F_20 ( V_52 -> V_100 ) ) ;
if ( V_56 )
V_54 = V_85 ;
return V_54 == V_85 ;
}
static int T_4 F_31 ( void )
{
int V_17 = - V_19 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < F_32 ( V_28 ) ; ++ V_103 )
F_33 ( & V_28 [ V_103 ] ) ;
V_17 = F_34 ( & V_104 ) ;
if ( V_17 < 0 ) {
F_35 ( L_3 , V_17 ) ;
goto V_105;
}
V_17 = F_36 ( & V_106 ) ;
if ( V_17 ) {
F_35 ( L_4
L_5 , V_17 ) ;
goto V_107;
}
return 0 ;
V_107:
F_37 ( & V_104 ) ;
V_105:
return V_17 ;
}
static void T_5 F_38 ( void )
{
struct V_14 * V_13 ;
int V_103 ;
F_37 ( & V_104 ) ;
F_39 ( & V_106 ) ;
F_21 () ;
for ( V_103 = 0 ; V_103 < F_32 ( V_28 ) ; ++ V_103 ) {
F_22 (f, &xt_osf_fingers[i], finger_entry) {
F_8 ( & V_13 -> V_27 ) ;
F_9 ( V_13 , V_31 ) ;
}
}
F_30 () ;
F_40 () ;
}
