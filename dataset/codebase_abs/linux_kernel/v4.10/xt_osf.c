static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_14 ;
int V_15 = 0 ;
if ( ! V_9 [ V_16 ] )
return - V_17 ;
if ( ! ( V_7 -> V_18 & V_19 ) )
return - V_17 ;
V_11 = F_2 ( V_9 [ V_16 ] ) ;
V_13 = F_3 ( sizeof( struct V_12 ) , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
memcpy ( & V_13 -> V_22 , V_11 , sizeof( struct V_10 ) ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_14 -> V_22 , V_11 , sizeof( struct V_10 ) ) )
continue;
F_5 ( V_13 ) ;
V_13 = NULL ;
if ( V_7 -> V_18 & V_23 )
V_15 = - V_24 ;
break;
}
if ( V_13 )
F_6 ( & V_13 -> V_25 , & V_26 [ ! ! V_11 -> V_27 ] ) ;
return V_15 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * const V_9 [] )
{
struct V_10 * V_11 ;
struct V_12 * V_14 ;
int V_15 = - V_28 ;
if ( ! V_9 [ V_16 ] )
return - V_17 ;
V_11 = F_2 ( V_9 [ V_16 ] ) ;
F_4 (sf, &xt_osf_fingers[!!f->df], finger_entry) {
if ( memcmp ( & V_14 -> V_22 , V_11 , sizeof( struct V_10 ) ) )
continue;
F_8 ( & V_14 -> V_25 ) ;
F_9 ( V_14 , V_29 ) ;
V_15 = 0 ;
break;
}
return V_15 ;
}
static inline int F_10 ( const struct V_4 * V_5 , const struct V_30 * V_31 ,
unsigned char V_32 )
{
const struct V_33 * V_34 = F_11 ( V_5 ) ;
if ( V_31 -> V_35 & V_36 ) {
if ( V_31 -> V_37 == V_38 )
return V_34 -> V_37 == V_32 ;
if ( V_31 -> V_37 == V_39 )
return 1 ;
else if ( V_34 -> V_37 <= V_32 )
return 1 ;
else {
struct V_40 * V_41 = F_12 ( V_5 -> V_42 ) ;
int V_43 = 0 ;
F_13 (in_dev) {
if ( F_14 ( V_34 -> V_44 , V_45 ) ) {
V_43 = ( V_34 -> V_37 == V_32 ) ;
break;
}
}
F_15 ( V_41 ) ;
return V_43 ;
}
}
return V_34 -> V_37 == V_32 ;
}
static bool
F_16 ( const struct V_4 * V_5 , struct V_46 * V_47 )
{
const struct V_30 * V_31 = V_47 -> V_48 ;
const struct V_33 * V_34 = F_11 ( V_5 ) ;
const struct V_49 * V_50 ;
struct V_49 V_51 ;
int V_52 = V_53 , V_54 = 0 ;
unsigned int V_55 = 0 , V_56 = 0 ;
T_1 V_57 , V_58 , V_59 = 0 ;
bool V_27 ;
const unsigned char * V_60 = NULL , * V_61 = NULL ;
unsigned char V_62 [ V_63 ] ;
const struct V_12 * V_13 ;
const struct V_10 * V_11 ;
struct V_1 * V_1 = F_17 ( V_47 ) ;
if ( ! V_31 )
return false ;
V_50 = F_18 ( V_5 , F_19 ( V_5 ) , sizeof( struct V_49 ) , & V_51 ) ;
if ( ! V_50 )
return false ;
if ( ! V_50 -> V_64 )
return false ;
V_58 = F_20 ( V_34 -> V_65 ) ;
V_27 = F_20 ( V_34 -> V_66 ) & V_67 ;
V_57 = F_20 ( V_50 -> V_57 ) ;
if ( V_50 -> V_68 * 4 > sizeof( struct V_49 ) ) {
V_55 = V_50 -> V_68 * 4 - sizeof( struct V_49 ) ;
V_61 = V_60 = F_18 ( V_5 , F_19 ( V_5 ) +
sizeof( struct V_49 ) , V_55 , V_62 ) ;
}
F_21 () ;
F_22 (kf, &xt_osf_fingers[df], finger_entry) {
int V_69 , V_70 ;
V_11 = & V_13 -> V_22 ;
if ( ! ( V_31 -> V_35 & V_71 ) && strcmp ( V_31 -> V_72 , V_11 -> V_72 ) )
continue;
V_60 = V_61 ;
V_52 = V_53 ;
if ( V_58 != V_11 -> V_73 || ! F_10 ( V_5 , V_31 , V_11 -> V_37 ) )
continue;
if ( V_11 -> V_74 . V_75 >= V_76 )
continue;
V_69 = 0 ;
for ( V_70 = 0 ; V_70 < V_11 -> V_77 ; ++ V_70 )
V_69 += V_11 -> V_78 [ V_70 ] . V_79 ;
if ( V_69 > V_63 ||
V_55 > V_63 ||
V_55 != V_69 )
continue;
V_56 = V_11 -> V_74 . V_75 ;
for ( V_70 = 0 ; V_70 < V_11 -> V_77 ; ++ V_70 ) {
if ( V_11 -> V_78 [ V_70 ] . V_80 == ( * V_60 ) ) {
T_2 V_81 = V_11 -> V_78 [ V_70 ] . V_79 ;
const T_3 * V_82 = V_60 + V_81 ;
V_52 = V_83 ;
switch ( * V_60 ) {
case V_84 :
V_59 = V_60 [ 3 ] ;
V_59 <<= 8 ;
V_59 |= V_60 [ 2 ] ;
V_59 = F_20 ( ( V_85 V_86 ) V_59 ) ;
break;
case V_87 :
break;
}
V_60 = V_82 ;
} else
V_52 = V_88 ;
if ( V_52 != V_83 )
break;
}
if ( V_52 != V_88 ) {
V_52 = V_53 ;
switch ( V_56 ) {
case V_89 :
if ( V_11 -> V_74 . V_90 == 0 || V_57 == V_11 -> V_74 . V_90 )
V_52 = V_83 ;
break;
case V_91 :
#define F_23 1460
#define F_24 1448
if ( V_57 == V_11 -> V_74 . V_90 * V_59 ||
V_57 == V_11 -> V_74 . V_90 * F_23 ||
V_57 == V_11 -> V_74 . V_90 * F_24 )
V_52 = V_83 ;
break;
case V_92 :
if ( V_57 == V_11 -> V_74 . V_90 * ( V_59 + 40 ) ||
V_57 == V_11 -> V_74 . V_90 * ( F_23 + 40 ) ||
V_57 == V_11 -> V_74 . V_90 * ( F_24 + 40 ) )
V_52 = V_83 ;
break;
case V_93 :
if ( ( V_57 % V_11 -> V_74 . V_90 ) == 0 )
V_52 = V_83 ;
break;
}
}
if ( V_52 != V_83 )
continue;
V_54 ++ ;
if ( V_31 -> V_35 & V_71 )
F_25 ( V_1 , F_26 ( V_47 ) , F_27 ( V_47 ) , V_5 ,
F_28 ( V_47 ) , F_29 ( V_47 ) , NULL ,
L_1 ,
V_11 -> V_72 , V_11 -> V_94 , V_11 -> V_95 ,
& V_34 -> V_44 , F_20 ( V_50 -> V_96 ) ,
& V_34 -> V_97 , F_20 ( V_50 -> V_98 ) ,
V_11 -> V_37 - V_34 -> V_37 ) ;
if ( ( V_31 -> V_35 & V_71 ) &&
V_31 -> V_99 == V_100 )
break;
}
F_30 () ;
if ( ! V_54 && ( V_31 -> V_35 & V_71 ) )
F_25 ( V_1 , F_26 ( V_47 ) , F_27 ( V_47 ) , V_5 , F_28 ( V_47 ) ,
F_29 ( V_47 ) , NULL ,
L_2 ,
& V_34 -> V_44 , F_20 ( V_50 -> V_96 ) ,
& V_34 -> V_97 , F_20 ( V_50 -> V_98 ) ) ;
if ( V_54 )
V_52 = V_83 ;
return V_52 == V_83 ;
}
static int T_4 F_31 ( void )
{
int V_15 = - V_17 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < F_32 ( V_26 ) ; ++ V_101 )
F_33 ( & V_26 [ V_101 ] ) ;
V_15 = F_34 ( & V_102 ) ;
if ( V_15 < 0 ) {
F_35 ( L_3 , V_15 ) ;
goto V_103;
}
V_15 = F_36 ( & V_104 ) ;
if ( V_15 ) {
F_35 ( L_4
L_5 , V_15 ) ;
goto V_105;
}
return 0 ;
V_105:
F_37 ( & V_102 ) ;
V_103:
return V_15 ;
}
static void T_5 F_38 ( void )
{
struct V_12 * V_11 ;
int V_101 ;
F_37 ( & V_102 ) ;
F_39 ( & V_104 ) ;
F_21 () ;
for ( V_101 = 0 ; V_101 < F_32 ( V_26 ) ; ++ V_101 ) {
F_22 (f, &xt_osf_fingers[i], finger_entry) {
F_8 ( & V_11 -> V_25 ) ;
F_9 ( V_11 , V_29 ) ;
}
}
F_30 () ;
F_40 () ;
}
