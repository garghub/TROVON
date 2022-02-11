static inline int F_1 ( int V_1 )
{
int V_2 [] = { 2 , 6 , 6 , 6 } ;
F_2 ( F_3 ( V_2 ) != V_3 ) ;
if ( V_1 < V_4 || V_1 >= V_3 )
return - V_5 ;
return V_2 [ V_1 ] ;
}
int F_4 ( struct V_6 * V_7 , int V_1 , void * V_8 )
{
struct V_9 * V_10 ;
void * V_11 ;
int V_12 , V_13 ;
unsigned long V_14 ;
V_10 = V_7 -> V_15 [ V_1 ] ;
if ( ! V_10 )
return - V_16 ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_11 = ( void * ) & V_10 -> V_11 ;
V_12 = - 1 ;
while ( ( V_12 = F_6 ( V_11 , V_10 -> V_18 , V_12 + 1 ) )
< V_10 -> V_18 ) {
if ( ! memcmp ( V_10 -> V_8 + V_13 * V_12 , V_8 , V_13 ) ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
return V_12 ;
}
}
F_7 ( & V_7 -> V_17 , V_14 ) ;
return - V_19 ;
}
int F_8 ( struct V_6 * V_7 , int V_1 , void * V_8 )
{
struct V_9 * V_10 ;
int V_12 , V_13 ;
void * V_11 ;
unsigned long V_14 ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_4 ( V_7 , V_1 , V_8 ) ;
if ( V_12 >= 0 )
return V_12 ;
V_10 = V_7 -> V_15 [ V_1 ] ;
if ( ! V_10 )
return - V_20 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_11 = ( void * ) & V_10 -> V_11 ;
do {
V_12 = F_9 ( V_11 , V_10 -> V_18 , 0 ) ;
if ( V_12 >= V_10 -> V_18 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
return - V_21 ;
}
} while ( F_10 ( V_12 , V_11 ) );
memcpy ( V_10 -> V_8 + V_13 * V_12 , V_8 , V_13 ) ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
return V_12 ;
}
int F_11 ( struct V_6 * V_7 , int V_1 , int V_12 )
{
struct V_9 * V_10 ;
int V_13 ;
void * V_11 ;
unsigned long V_14 ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 = V_7 -> V_15 [ V_1 ] ;
if ( ! V_10 || V_12 >= V_10 -> V_18 )
return - V_20 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_11 = ( void * ) & V_10 -> V_11 ;
if ( F_12 ( V_12 , V_11 ) )
memset ( V_10 -> V_8 + V_13 * V_12 , 0 , V_13 ) ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
return 0 ;
}
static void F_13 ( struct V_22 * V_23 , bool V_24 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
V_26 -> V_30 = V_31 ;
if ( V_24 ) {
V_26 -> V_32 = 0 ;
goto V_33;
}
V_26 -> V_32 = 0 ;
F_14 (ndp, np) {
F_15 (np, nc) {
if ( ! F_16 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_35 )
continue;
if ( V_7 -> V_36 [ V_37 ] . V_8 [ 2 ] & 0x1 ) {
V_26 -> V_32 = 1 ;
goto V_33;
}
}
}
V_33:
V_26 -> V_38 ( V_26 ) ;
}
static void F_17 ( unsigned long V_8 )
{
struct V_6 * V_7 = (struct V_6 * ) V_8 ;
struct V_28 * V_29 = V_7 -> V_39 ;
struct V_22 * V_23 = V_29 -> V_23 ;
struct V_40 V_41 ;
bool V_42 ;
unsigned int V_43 ;
unsigned long V_14 ;
int V_44 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_43 = V_7 -> V_43 ;
V_42 = V_7 -> V_42 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
if ( ! V_42 || ! F_16 ( & V_7 -> V_34 ) )
return;
if ( V_7 -> V_30 != V_45 &&
V_7 -> V_30 != V_35 )
return;
if ( ! ( V_43 % 2 ) ) {
V_41 . V_23 = V_23 ;
V_41 . V_39 = V_29 -> V_46 ;
V_41 . V_47 = V_7 -> V_46 ;
V_41 . type = V_48 ;
V_41 . V_49 = false ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 ) {
F_19 ( V_23 -> V_27 . V_50 , L_1 ,
V_44 ) ;
return;
}
}
if ( V_43 + 1 >= 3 ) {
if ( ! ( V_23 -> V_14 & V_51 ) &&
V_7 -> V_30 == V_35 )
F_13 ( V_23 , true ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_20 ( & V_7 -> V_30 , V_45 ) ;
F_21 ( & V_7 -> V_34 , & V_23 -> V_52 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_22 ( V_23 ) ;
return;
}
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_7 -> V_43 = V_43 + 1 ;
V_7 -> V_42 = true ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_23 ( & V_7 -> V_53 , V_54 + V_55 * ( 1 << ( V_7 -> V_43 / 2 ) ) ) ;
}
void F_24 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
F_25 ( V_7 -> V_42 ) ;
V_7 -> V_43 = 0 ;
V_7 -> V_42 = true ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_23 ( & V_7 -> V_53 , V_54 + V_55 * ( 1 << ( V_7 -> V_43 / 2 ) ) ) ;
}
void F_26 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
if ( ! V_7 -> V_42 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
return;
}
V_7 -> V_42 = false ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_27 ( & V_7 -> V_53 ) ;
}
struct V_6 * F_28 ( struct V_28 * V_29 ,
unsigned char V_46 )
{
struct V_6 * V_7 ;
F_15 (np, nc) {
if ( V_7 -> V_46 == V_46 )
return V_7 ;
}
return NULL ;
}
struct V_6 * F_29 ( struct V_28 * V_29 , unsigned char V_46 )
{
struct V_6 * V_7 , * V_56 ;
int V_12 ;
unsigned long V_14 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_46 = V_46 ;
V_7 -> V_39 = V_29 ;
V_7 -> V_30 = V_45 ;
V_7 -> V_42 = false ;
F_31 ( & V_7 -> V_53 , F_17 , ( unsigned long ) V_7 ) ;
F_32 ( & V_7 -> V_17 ) ;
F_33 ( & V_7 -> V_34 ) ;
for ( V_12 = 0 ; V_12 < V_58 ; V_12 ++ )
V_7 -> V_59 [ V_12 ] . V_12 = V_12 ;
for ( V_12 = 0 ; V_12 < V_60 ; V_12 ++ )
V_7 -> V_36 [ V_12 ] . V_12 = V_12 ;
F_5 ( & V_29 -> V_17 , V_14 ) ;
V_56 = F_28 ( V_29 , V_46 ) ;
if ( V_56 ) {
F_7 ( & V_29 -> V_17 , V_14 ) ;
F_34 ( V_7 ) ;
return V_56 ;
}
F_21 ( & V_7 -> V_61 , & V_29 -> V_62 ) ;
V_29 -> V_63 ++ ;
F_7 ( & V_29 -> V_17 , V_14 ) ;
return V_7 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_39 ;
struct V_9 * V_10 ;
unsigned long V_14 ;
int V_64 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
for ( V_64 = 0 ; V_64 < V_3 ; V_64 ++ ) {
V_10 = V_7 -> V_15 [ V_64 ] ;
if ( ! V_10 )
continue;
V_7 -> V_15 [ V_64 ] = NULL ;
F_34 ( V_10 ) ;
}
V_7 -> V_30 = V_45 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_26 ( V_7 ) ;
F_5 ( & V_29 -> V_17 , V_14 ) ;
F_36 ( & V_7 -> V_61 ) ;
V_29 -> V_63 -- ;
F_7 ( & V_29 -> V_17 , V_14 ) ;
F_34 ( V_7 ) ;
}
struct V_28 * F_37 ( struct V_22 * V_23 ,
unsigned char V_46 )
{
struct V_28 * V_29 ;
F_14 (ndp, np) {
if ( V_29 -> V_46 == V_46 )
return V_29 ;
}
return NULL ;
}
struct V_28 * F_38 ( struct V_22 * V_23 ,
unsigned char V_46 )
{
struct V_28 * V_29 , * V_56 ;
unsigned long V_14 ;
V_29 = F_30 ( sizeof( * V_29 ) , V_57 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_46 = V_46 ;
V_29 -> V_23 = V_23 ;
F_32 ( & V_29 -> V_17 ) ;
F_33 ( & V_29 -> V_62 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_56 = F_37 ( V_23 , V_46 ) ;
if ( V_56 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_34 ( V_29 ) ;
return V_56 ;
}
F_21 ( & V_29 -> V_61 , & V_23 -> V_65 ) ;
V_23 -> V_66 ++ ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
return V_29 ;
}
void F_39 ( struct V_28 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_23 ;
struct V_6 * V_7 , * V_56 ;
unsigned long V_14 ;
F_40 (nc, tmp, &np->channels, node)
F_35 ( V_7 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_36 ( & V_29 -> V_61 ) ;
V_23 -> V_66 -- ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_34 ( V_29 ) ;
}
void F_41 ( struct V_22 * V_23 ,
unsigned char V_46 ,
struct V_28 * * V_29 ,
struct V_6 * * V_7 )
{
struct V_28 * V_67 ;
struct V_6 * V_68 ;
V_67 = F_37 ( V_23 , F_42 ( V_46 ) ) ;
V_68 = V_67 ? F_28 ( V_67 , F_43 ( V_46 ) ) : NULL ;
if ( V_29 )
* V_29 = V_67 ;
if ( V_7 )
* V_7 = V_68 ;
}
struct V_69 * F_44 ( struct V_22 * V_23 , bool V_49 )
{
struct V_69 * V_70 = NULL ;
int V_64 , V_71 = F_3 ( V_23 -> V_72 ) ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
for ( V_64 = V_23 -> V_73 ; ! V_70 && V_64 < V_71 ; V_64 ++ ) {
if ( V_23 -> V_72 [ V_64 ] . V_74 )
continue;
V_70 = & V_23 -> V_72 [ V_64 ] ;
V_70 -> V_74 = true ;
V_70 -> V_49 = V_49 ;
if ( ++ V_23 -> V_73 >= V_71 )
V_23 -> V_73 = 0 ;
}
for ( V_64 = 0 ; ! V_70 && V_64 < V_23 -> V_73 ; V_64 ++ ) {
if ( V_23 -> V_72 [ V_64 ] . V_74 )
continue;
V_70 = & V_23 -> V_72 [ V_64 ] ;
V_70 -> V_74 = true ;
V_70 -> V_49 = V_49 ;
if ( ++ V_23 -> V_73 >= V_71 )
V_23 -> V_73 = 0 ;
}
F_7 ( & V_23 -> V_17 , V_14 ) ;
return V_70 ;
}
void F_45 ( struct V_69 * V_70 )
{
struct V_22 * V_23 = V_70 -> V_23 ;
struct V_75 * V_76 , * V_77 ;
unsigned long V_14 ;
bool V_49 ;
if ( V_70 -> V_42 ) {
V_70 -> V_42 = false ;
F_27 ( & V_70 -> V_53 ) ;
}
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_76 = V_70 -> V_76 ;
V_77 = V_70 -> V_77 ;
V_70 -> V_76 = NULL ;
V_70 -> V_77 = NULL ;
V_70 -> V_74 = false ;
V_49 = V_70 -> V_49 ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
if ( V_49 && V_76 && -- V_23 -> V_78 == 0 )
F_46 ( & V_23 -> V_79 ) ;
F_47 ( V_76 ) ;
F_47 ( V_77 ) ;
}
struct V_25 * F_48 ( struct V_80 * V_50 )
{
struct V_22 * V_23 ;
F_49 (ndp) {
if ( V_23 -> V_27 . V_50 == V_50 )
return & V_23 -> V_27 ;
}
return NULL ;
}
static void F_50 ( unsigned long V_8 )
{
struct V_69 * V_70 = (struct V_69 * ) V_8 ;
struct V_22 * V_23 = V_70 -> V_23 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_70 -> V_42 = false ;
if ( V_70 -> V_77 || ! V_70 -> V_76 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
return;
}
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_45 ( V_70 ) ;
}
static void F_51 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_81 ;
struct V_6 * V_7 = V_23 -> V_82 ;
struct V_40 V_41 ;
int V_44 ;
V_41 . V_23 = V_23 ;
V_41 . V_49 = true ;
switch ( V_26 -> V_30 ) {
case V_83 :
V_26 -> V_30 = V_84 ;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
V_23 -> V_78 = 1 ;
V_29 = V_23 -> V_81 ;
V_7 = V_23 -> V_82 ;
V_41 . V_39 = V_29 -> V_46 ;
if ( V_26 -> V_30 == V_84 ) {
V_41 . type = V_88 ;
V_41 . V_47 = 0x1f ;
if ( V_23 -> V_14 & V_51 )
V_41 . V_89 [ 0 ] = 0 ;
else
V_41 . V_89 [ 0 ] = 1 ;
V_26 -> V_30 = V_85 ;
} else if ( V_26 -> V_30 == V_85 ) {
V_41 . type = V_90 ;
V_41 . V_47 = V_7 -> V_46 ;
V_26 -> V_30 = V_86 ;
} else if ( V_26 -> V_30 == V_86 ) {
V_41 . type = V_91 ;
V_41 . V_47 = V_7 -> V_46 ;
V_41 . V_89 [ 0 ] = 1 ;
V_26 -> V_30 = V_87 ;
} else if ( V_26 -> V_30 == V_87 ) {
V_41 . type = V_92 ;
V_41 . V_47 = 0x1f ;
V_26 -> V_30 = V_93 ;
}
V_44 = F_18 ( & V_41 ) ;
if ( V_44 ) {
V_26 -> V_30 = V_31 ;
return;
}
break;
case V_93 :
F_20 ( & V_7 -> V_30 , V_45 ) ;
F_22 ( V_23 ) ;
break;
default:
F_52 ( V_26 -> V_50 , L_2 ,
V_26 -> V_30 ) ;
}
}
static void F_53 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_80 * V_50 = V_26 -> V_50 ;
struct V_28 * V_29 = V_23 -> V_81 ;
struct V_6 * V_7 = V_23 -> V_82 ;
struct V_40 V_41 ;
unsigned char V_12 ;
int V_44 ;
V_41 . V_23 = V_23 ;
V_41 . V_49 = true ;
switch ( V_26 -> V_30 ) {
case V_94 :
case V_95 :
V_23 -> V_78 = 1 ;
V_41 . type = V_88 ;
if ( V_23 -> V_14 & V_51 )
V_41 . V_89 [ 0 ] = 0 ;
else
V_41 . V_89 [ 0 ] = 1 ;
V_41 . V_39 = V_29 -> V_46 ;
V_41 . V_47 = 0x1f ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
V_26 -> V_30 = V_96 ;
break;
case V_96 :
V_23 -> V_78 = 1 ;
V_41 . type = V_97 ;
V_41 . V_39 = V_29 -> V_46 ;
V_41 . V_47 = V_7 -> V_46 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
V_26 -> V_30 = V_98 ;
break;
case V_98 :
case V_99 :
#if F_54 ( V_100 )
case V_101 :
#endif
case V_102 :
case V_103 :
case V_104 :
case V_105 :
V_23 -> V_78 = 1 ;
V_41 . V_39 = V_29 -> V_46 ;
V_41 . V_47 = V_7 -> V_46 ;
if ( V_26 -> V_30 == V_98 ) {
V_41 . type = V_106 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_41 . V_89 [ V_12 ] = V_50 -> V_107 [ V_12 ] ;
V_41 . V_89 [ 6 ] = 0x1 ;
V_41 . V_89 [ 7 ] = 0x1 ;
V_26 -> V_30 = V_99 ;
} else if ( V_26 -> V_30 == V_99 ) {
V_41 . type = V_108 ;
V_41 . V_109 [ 0 ] = V_7 -> V_59 [ V_110 ] . V_111 ;
V_26 -> V_30 = V_102 ;
#if F_54 ( V_100 )
if ( V_23 -> V_112 > 0 &&
( V_7 -> V_59 [ V_113 ] . V_111 &
V_114 ) )
V_26 -> V_30 = V_101 ;
else
V_26 -> V_30 = V_102 ;
} else if ( V_26 -> V_30 == V_101 ) {
V_41 . type = V_115 ;
V_41 . V_109 [ 0 ] = V_7 -> V_59 [ V_116 ] . V_111 ;
V_26 -> V_30 = V_102 ;
#endif
} else if ( V_26 -> V_30 == V_102 ) {
V_41 . type = V_117 ;
V_26 -> V_30 = V_103 ;
} else if ( V_26 -> V_30 == V_103 ) {
V_41 . type = V_118 ;
V_26 -> V_30 = V_104 ;
if ( ! ( V_7 -> V_59 [ V_119 ] . V_111 & V_120 ) )
V_26 -> V_30 = V_105 ;
} else if ( V_26 -> V_30 == V_104 ) {
V_41 . type = V_121 ;
V_41 . V_89 [ 0 ] = 0 ;
V_41 . V_109 [ 1 ] = V_7 -> V_59 [ V_119 ] . V_111 ;
V_26 -> V_30 = V_105 ;
} else if ( V_26 -> V_30 == V_105 ) {
V_41 . type = V_48 ;
V_26 -> V_30 = V_122 ;
}
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
break;
case V_122 :
if ( V_7 -> V_36 [ V_37 ] . V_8 [ 2 ] & 0x1 )
F_20 ( & V_7 -> V_30 , V_35 ) ;
else
F_20 ( & V_7 -> V_30 , V_45 ) ;
F_24 ( V_7 ) ;
F_22 ( V_23 ) ;
break;
default:
F_52 ( V_50 , L_3 ,
V_26 -> V_30 ) ;
}
return;
error:
F_13 ( V_23 , true ) ;
}
static int F_55 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 , * V_123 ;
struct V_124 * V_125 ;
unsigned long V_14 ;
V_123 = NULL ;
F_14 (ndp, np) {
F_15 (np, nc) {
if ( ! F_16 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_45 )
continue;
if ( ! V_123 )
V_123 = V_7 ;
V_125 = & V_7 -> V_36 [ V_37 ] ;
if ( V_125 -> V_8 [ 2 ] & 0x1 ) {
V_123 = V_7 ;
goto V_126;
}
}
}
if ( ! V_123 ) {
F_13 ( V_23 , true ) ;
return - V_20 ;
}
V_126:
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_21 ( & V_123 -> V_34 , & V_23 -> V_52 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
return F_22 ( V_23 ) ;
}
static bool F_56 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned int V_111 ;
F_14 (ndp, np) {
F_15 (np, nc) {
V_111 = V_7 -> V_59 [ V_113 ] . V_111 ;
if ( ! ( V_111 & V_127 ) ||
( V_111 & V_128 ) !=
V_129 ) {
V_23 -> V_14 &= ~ V_51 ;
return false ;
}
}
}
V_23 -> V_14 |= V_51 ;
return true ;
}
static int F_57 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_14 (ndp, np) {
F_15 (np, nc) {
F_25 ( V_7 -> V_30 != V_45 ||
! F_16 ( & V_7 -> V_34 ) ) ;
F_26 ( V_7 ) ;
F_21 ( & V_7 -> V_34 , & V_23 -> V_52 ) ;
}
}
F_7 ( & V_23 -> V_17 , V_14 ) ;
if ( F_16 ( & V_23 -> V_52 ) ) {
F_13 ( V_23 , false ) ;
return - V_19 ;
}
return F_22 ( V_23 ) ;
}
static void F_58 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_40 V_41 ;
unsigned char V_12 ;
int V_44 ;
V_41 . V_23 = V_23 ;
V_41 . V_49 = true ;
switch ( V_26 -> V_30 ) {
case V_130 :
V_26 -> V_30 = V_131 ;
case V_131 :
V_23 -> V_78 = 8 ;
V_41 . type = V_92 ;
V_41 . V_47 = 0x1f ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
}
V_26 -> V_30 = V_132 ;
break;
case V_132 :
V_23 -> V_78 = 16 ;
V_41 . type = V_88 ;
V_41 . V_89 [ 0 ] = 1 ;
V_41 . V_47 = 0x1f ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
}
V_41 . type = V_92 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
}
V_26 -> V_30 = V_133 ;
break;
case V_133 :
if ( ! V_23 -> V_81 )
V_23 -> V_81 = F_59 (
& V_23 -> V_65 , struct V_28 , V_61 ) ;
else if ( F_60 ( & V_23 -> V_81 -> V_61 ,
& V_23 -> V_65 ) )
V_23 -> V_81 = NULL ;
else
V_23 -> V_81 = F_61 (
V_23 -> V_81 , V_61 ) ;
if ( ! V_23 -> V_81 ) {
V_23 -> V_14 |= V_134 ;
if ( F_56 ( V_23 ) )
F_57 ( V_23 ) ;
else
F_55 ( V_23 ) ;
return;
}
V_23 -> V_78 = 1 ;
V_41 . type = V_88 ;
V_41 . V_89 [ 0 ] = 1 ;
V_41 . V_39 = V_23 -> V_81 -> V_46 ;
V_41 . V_47 = 0x1f ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
V_26 -> V_30 = V_135 ;
break;
case V_135 :
V_23 -> V_78 = 32 ;
V_41 . type = V_97 ;
V_41 . V_39 = V_23 -> V_81 -> V_46 ;
for ( V_12 = 0 ; V_12 < 0x20 ; V_12 ++ ) {
V_41 . V_47 = V_12 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
}
V_26 -> V_30 = V_136 ;
break;
case V_136 :
case V_137 :
case V_138 :
V_29 = V_23 -> V_81 ;
V_23 -> V_78 = V_29 -> V_63 ;
if ( V_26 -> V_30 == V_136 )
V_41 . type = V_139 ;
else if ( V_26 -> V_30 == V_137 )
V_41 . type = V_140 ;
else
V_41 . type = V_48 ;
V_41 . V_39 = V_29 -> V_46 ;
F_15 (np, nc) {
V_41 . V_47 = V_7 -> V_46 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
}
if ( V_26 -> V_30 == V_136 )
V_26 -> V_30 = V_137 ;
else if ( V_26 -> V_30 == V_137 )
V_26 -> V_30 = V_138 ;
else
V_26 -> V_30 = V_141 ;
break;
case V_141 :
V_23 -> V_78 = 1 ;
V_41 . type = V_92 ;
V_41 . V_39 = V_23 -> V_81 -> V_46 ;
V_41 . V_47 = 0x1f ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 )
goto error;
V_26 -> V_30 = V_133 ;
break;
default:
F_52 ( V_26 -> V_50 , L_4 ,
V_26 -> V_30 ) ;
}
return;
error:
F_13 ( V_23 , true ) ;
}
static void F_62 ( struct V_142 * V_79 )
{
struct V_22 * V_23 = F_63 ( V_79 ,
struct V_22 , V_79 ) ;
struct V_25 * V_26 = & V_23 -> V_27 ;
switch ( V_26 -> V_30 & V_143 ) {
case V_130 :
F_58 ( V_23 ) ;
break;
case V_83 :
F_51 ( V_23 ) ;
break;
case V_94 :
F_53 ( V_23 ) ;
break;
default:
F_52 ( V_26 -> V_50 , L_5 ,
V_26 -> V_30 ) ;
}
}
int F_22 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
int V_144 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_7 = F_59 ( & V_23 -> V_52 ,
struct V_6 , V_34 ) ;
if ( ! V_7 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
goto V_126;
}
V_144 = F_20 ( & V_7 -> V_30 , V_145 ) ;
F_64 ( & V_7 -> V_34 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
V_23 -> V_82 = V_7 ;
V_23 -> V_81 = V_7 -> V_39 ;
switch ( V_144 ) {
case V_45 :
V_23 -> V_27 . V_30 = V_94 ;
F_53 ( V_23 ) ;
break;
case V_35 :
V_23 -> V_27 . V_30 = V_83 ;
F_51 ( V_23 ) ;
break;
default:
F_19 ( V_23 -> V_27 . V_50 , L_6 ,
V_7 -> V_30 , V_7 -> V_39 -> V_46 , V_7 -> V_46 ) ;
F_13 ( V_23 , false ) ;
return - V_5 ;
}
return 0 ;
V_126:
V_23 -> V_82 = NULL ;
V_23 -> V_81 = NULL ;
if ( V_23 -> V_14 & V_146 ) {
V_23 -> V_14 &= ~ V_146 ;
return F_55 ( V_23 ) ;
}
F_13 ( V_23 , false ) ;
return - V_20 ;
}
static int F_65 ( struct V_147 * V_148 ,
unsigned long V_149 , void * V_8 )
{
struct V_150 * V_151 = V_8 ;
struct V_80 * V_50 = V_151 -> V_152 -> V_50 ;
struct V_25 * V_26 = F_48 ( V_50 ) ;
struct V_22 * V_23 = V_26 ? F_66 ( V_26 ) : NULL ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_40 V_41 ;
bool V_153 ;
int V_44 ;
if ( ! V_23 || ( F_67 ( & V_151 -> V_154 ) &
( V_155 | V_156 ) ) )
return V_157 ;
switch ( V_149 ) {
case V_158 :
V_153 = ( ++ V_23 -> V_112 ) == 1 ;
V_41 . type = V_115 ;
break;
case V_159 :
V_153 = ( -- V_23 -> V_112 == 0 ) ;
V_41 . type = V_160 ;
break;
default:
return V_157 ;
}
V_29 = V_23 -> V_81 ;
V_7 = V_23 -> V_82 ;
if ( ! V_153 || ! V_29 || ! V_7 )
return V_157 ;
if ( ! ( V_7 -> V_59 [ V_113 ] . V_111 & V_114 ) )
return V_157 ;
V_41 . V_23 = V_23 ;
V_41 . V_49 = false ;
V_41 . V_39 = V_29 -> V_46 ;
V_41 . V_47 = V_7 -> V_46 ;
V_41 . V_109 [ 0 ] = V_7 -> V_59 [ V_116 ] . V_111 ;
V_44 = F_18 ( & V_41 ) ;
if ( V_44 ) {
F_52 ( V_50 , L_7 ,
( V_149 == V_158 ) ? L_8 : L_9 , V_44 ) ;
return V_161 ;
}
return V_157 ;
}
struct V_25 * F_68 ( struct V_80 * V_50 ,
void (* V_38)( struct V_25 * V_27 ) )
{
struct V_22 * V_23 ;
struct V_25 * V_26 ;
unsigned long V_14 ;
int V_64 ;
V_26 = F_48 ( V_50 ) ;
if ( V_26 )
return V_26 ;
V_23 = F_30 ( sizeof( * V_23 ) , V_57 ) ;
if ( ! V_23 )
return NULL ;
V_26 = & V_23 -> V_27 ;
V_26 -> V_30 = V_162 ;
V_26 -> V_50 = V_50 ;
V_26 -> V_38 = V_38 ;
V_23 -> V_78 = 0 ;
F_33 ( & V_23 -> V_52 ) ;
F_69 ( & V_23 -> V_79 , F_62 ) ;
F_32 ( & V_23 -> V_17 ) ;
F_33 ( & V_23 -> V_65 ) ;
V_23 -> V_73 = 0 ;
for ( V_64 = 0 ; V_64 < F_3 ( V_23 -> V_72 ) ; V_64 ++ ) {
V_23 -> V_72 [ V_64 ] . V_46 = V_64 ;
V_23 -> V_72 [ V_64 ] . V_23 = V_23 ;
F_31 ( & V_23 -> V_72 [ V_64 ] . V_53 ,
F_50 ,
( unsigned long ) & V_23 -> V_72 [ V_64 ] ) ;
}
F_5 ( & V_163 , V_14 ) ;
#if F_54 ( V_100 )
V_23 -> V_112 = 0 ;
if ( F_16 ( & V_164 ) )
F_70 ( & V_165 ) ;
#endif
F_21 ( & V_23 -> V_61 , & V_164 ) ;
F_7 ( & V_163 , V_14 ) ;
V_23 -> V_166 . type = F_71 ( V_167 ) ;
V_23 -> V_166 . V_168 = V_169 ;
V_23 -> V_166 . V_50 = V_50 ;
F_72 ( & V_23 -> V_166 ) ;
return V_26 ;
}
int F_73 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_66 ( V_26 ) ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
int V_144 , V_44 ;
if ( V_26 -> V_30 != V_162 &&
V_26 -> V_30 != V_31 )
return - V_170 ;
if ( ! ( V_23 -> V_14 & V_134 ) ) {
V_26 -> V_30 = V_130 ;
F_46 ( & V_23 -> V_79 ) ;
return 0 ;
}
F_14 (ndp, np) {
F_15 (np, nc) {
V_144 = F_20 ( & V_7 -> V_30 , V_45 ) ;
F_25 ( ! F_16 ( & V_7 -> V_34 ) ||
V_144 == V_145 ) ;
}
}
if ( V_23 -> V_14 & V_51 )
V_44 = F_57 ( V_23 ) ;
else
V_44 = F_55 ( V_23 ) ;
return V_44 ;
}
void F_74 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_66 ( V_26 ) ;
struct V_28 * V_29 , * V_56 ;
unsigned long V_14 ;
F_75 ( & V_23 -> V_166 ) ;
F_40 (np, tmp, &ndp->packages, node)
F_39 ( V_29 ) ;
F_5 ( & V_163 , V_14 ) ;
F_36 ( & V_23 -> V_61 ) ;
#if F_54 ( V_100 )
if ( F_16 ( & V_164 ) )
F_76 ( & V_165 ) ;
#endif
F_7 ( & V_163 , V_14 ) ;
F_34 ( V_23 ) ;
}
