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
unsigned long V_14 ;
V_26 -> V_30 = V_31 ;
if ( V_24 ) {
V_26 -> V_32 = 0 ;
goto V_33;
}
V_26 -> V_32 = 0 ;
F_14 (ndp, np) {
F_15 (np, nc) {
F_5 ( & V_7 -> V_17 , V_14 ) ;
if ( ! F_16 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_35 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
continue;
}
if ( V_7 -> V_36 [ V_37 ] . V_8 [ 2 ] & 0x1 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
V_26 -> V_32 = 1 ;
goto V_33;
}
F_7 ( & V_7 -> V_17 , V_14 ) ;
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
bool V_42 , V_43 ;
unsigned int V_44 ;
unsigned long V_14 ;
int V_30 , V_45 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_30 = V_7 -> V_30 ;
V_43 = ! F_16 ( & V_7 -> V_34 ) ;
V_42 = V_7 -> V_46 . V_42 ;
V_44 = V_7 -> V_46 . V_30 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
if ( ! V_42 || V_43 )
return;
if ( V_30 != V_47 &&
V_30 != V_35 )
return;
switch ( V_44 ) {
case V_48 :
case V_49 :
V_41 . V_23 = V_23 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
V_41 . type = V_52 ;
V_41 . V_53 = 0 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 ) {
F_19 ( V_23 -> V_27 . V_54 , L_1 ,
V_45 ) ;
return;
}
break;
case V_55 ... V_56 :
break;
default:
if ( ! ( V_23 -> V_14 & V_57 ) &&
V_30 == V_35 ) {
F_13 ( V_23 , true ) ;
V_23 -> V_14 |= V_58 ;
}
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_7 -> V_30 = V_59 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_7 -> V_30 = V_47 ;
F_20 ( & V_7 -> V_34 , & V_23 -> V_60 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_21 ( V_23 ) ;
return;
}
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_7 -> V_46 . V_30 ++ ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_22 ( & V_7 -> V_46 . V_61 , V_62 + V_63 ) ;
}
void F_23 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
F_24 ( V_7 -> V_46 . V_42 ) ;
V_7 -> V_46 . V_42 = true ;
V_7 -> V_46 . V_30 = V_48 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_22 ( & V_7 -> V_46 . V_61 , V_62 + V_63 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
if ( ! V_7 -> V_46 . V_42 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
return;
}
V_7 -> V_46 . V_42 = false ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_26 ( & V_7 -> V_46 . V_61 ) ;
}
struct V_6 * F_27 ( struct V_28 * V_29 ,
unsigned char V_50 )
{
struct V_6 * V_7 ;
F_15 (np, nc) {
if ( V_7 -> V_50 == V_50 )
return V_7 ;
}
return NULL ;
}
struct V_6 * F_28 ( struct V_28 * V_29 , unsigned char V_50 )
{
struct V_6 * V_7 , * V_64 ;
int V_12 ;
unsigned long V_14 ;
V_7 = F_29 ( sizeof( * V_7 ) , V_65 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_50 = V_50 ;
V_7 -> V_39 = V_29 ;
V_7 -> V_30 = V_47 ;
V_7 -> V_46 . V_42 = false ;
F_30 ( & V_7 -> V_46 . V_61 ,
F_17 , ( unsigned long ) V_7 ) ;
F_31 ( & V_7 -> V_17 ) ;
F_32 ( & V_7 -> V_34 ) ;
for ( V_12 = 0 ; V_12 < V_66 ; V_12 ++ )
V_7 -> V_67 [ V_12 ] . V_12 = V_12 ;
for ( V_12 = 0 ; V_12 < V_68 ; V_12 ++ )
V_7 -> V_36 [ V_12 ] . V_12 = V_12 ;
F_5 ( & V_29 -> V_17 , V_14 ) ;
V_64 = F_27 ( V_29 , V_50 ) ;
if ( V_64 ) {
F_7 ( & V_29 -> V_17 , V_14 ) ;
F_33 ( V_7 ) ;
return V_64 ;
}
F_20 ( & V_7 -> V_69 , & V_29 -> V_70 ) ;
V_29 -> V_71 ++ ;
F_7 ( & V_29 -> V_17 , V_14 ) ;
return V_7 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_39 ;
struct V_9 * V_10 ;
unsigned long V_14 ;
int V_72 ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
for ( V_72 = 0 ; V_72 < V_3 ; V_72 ++ ) {
V_10 = V_7 -> V_15 [ V_72 ] ;
if ( ! V_10 )
continue;
V_7 -> V_15 [ V_72 ] = NULL ;
F_33 ( V_10 ) ;
}
V_7 -> V_30 = V_47 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_25 ( V_7 ) ;
F_5 ( & V_29 -> V_17 , V_14 ) ;
F_35 ( & V_7 -> V_69 ) ;
V_29 -> V_71 -- ;
F_7 ( & V_29 -> V_17 , V_14 ) ;
F_33 ( V_7 ) ;
}
struct V_28 * F_36 ( struct V_22 * V_23 ,
unsigned char V_50 )
{
struct V_28 * V_29 ;
F_14 (ndp, np) {
if ( V_29 -> V_50 == V_50 )
return V_29 ;
}
return NULL ;
}
struct V_28 * F_37 ( struct V_22 * V_23 ,
unsigned char V_50 )
{
struct V_28 * V_29 , * V_64 ;
unsigned long V_14 ;
V_29 = F_29 ( sizeof( * V_29 ) , V_65 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_50 = V_50 ;
V_29 -> V_23 = V_23 ;
F_31 ( & V_29 -> V_17 ) ;
F_32 ( & V_29 -> V_70 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_64 = F_36 ( V_23 , V_50 ) ;
if ( V_64 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_33 ( V_29 ) ;
return V_64 ;
}
F_20 ( & V_29 -> V_69 , & V_23 -> V_73 ) ;
V_23 -> V_74 ++ ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
return V_29 ;
}
void F_38 ( struct V_28 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_23 ;
struct V_6 * V_7 , * V_64 ;
unsigned long V_14 ;
F_39 (nc, tmp, &np->channels, node)
F_34 ( V_7 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_35 ( & V_29 -> V_69 ) ;
V_23 -> V_74 -- ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_33 ( V_29 ) ;
}
void F_40 ( struct V_22 * V_23 ,
unsigned char V_50 ,
struct V_28 * * V_29 ,
struct V_6 * * V_7 )
{
struct V_28 * V_75 ;
struct V_6 * V_76 ;
V_75 = F_36 ( V_23 , F_41 ( V_50 ) ) ;
V_76 = V_75 ? F_27 ( V_75 , F_42 ( V_50 ) ) : NULL ;
if ( V_29 )
* V_29 = V_75 ;
if ( V_7 )
* V_7 = V_76 ;
}
struct V_77 * F_43 ( struct V_22 * V_23 ,
unsigned int V_53 )
{
struct V_77 * V_78 = NULL ;
int V_72 , V_79 = F_3 ( V_23 -> V_80 ) ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
for ( V_72 = V_23 -> V_81 ; V_72 < V_79 ; V_72 ++ ) {
if ( V_23 -> V_80 [ V_72 ] . V_82 )
continue;
V_78 = & V_23 -> V_80 [ V_72 ] ;
V_78 -> V_82 = true ;
V_78 -> V_14 = V_53 ;
V_23 -> V_81 = V_72 + 1 ;
goto V_83;
}
for ( V_72 = V_84 ; V_72 < V_23 -> V_81 ; V_72 ++ ) {
if ( V_23 -> V_80 [ V_72 ] . V_82 )
continue;
V_78 = & V_23 -> V_80 [ V_72 ] ;
V_78 -> V_82 = true ;
V_78 -> V_14 = V_53 ;
V_23 -> V_81 = V_72 + 1 ;
goto V_83;
}
V_83:
F_7 ( & V_23 -> V_17 , V_14 ) ;
return V_78 ;
}
void F_44 ( struct V_77 * V_78 )
{
struct V_22 * V_23 = V_78 -> V_23 ;
struct V_85 * V_86 , * V_87 ;
unsigned long V_14 ;
bool V_88 ;
if ( V_78 -> V_42 ) {
V_78 -> V_42 = false ;
F_26 ( & V_78 -> V_61 ) ;
}
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_86 = V_78 -> V_86 ;
V_87 = V_78 -> V_87 ;
V_78 -> V_86 = NULL ;
V_78 -> V_87 = NULL ;
V_78 -> V_82 = false ;
V_88 = ! ! ( V_78 -> V_14 & V_89 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
if ( V_88 && V_86 && -- V_23 -> V_90 == 0 )
F_45 ( & V_23 -> V_91 ) ;
F_46 ( V_86 ) ;
F_46 ( V_87 ) ;
}
struct V_25 * F_47 ( struct V_92 * V_54 )
{
struct V_22 * V_23 ;
F_48 (ndp) {
if ( V_23 -> V_27 . V_54 == V_54 )
return & V_23 -> V_27 ;
}
return NULL ;
}
static void F_49 ( unsigned long V_8 )
{
struct V_77 * V_78 = (struct V_77 * ) V_8 ;
struct V_22 * V_23 = V_78 -> V_23 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_78 -> V_42 = false ;
if ( V_78 -> V_87 || ! V_78 -> V_86 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
return;
}
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_44 ( V_78 ) ;
}
static void F_50 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_93 ;
struct V_6 * V_7 = V_23 -> V_94 ;
struct V_40 V_41 ;
unsigned long V_14 ;
int V_45 ;
V_41 . V_23 = V_23 ;
V_41 . V_53 = V_89 ;
switch ( V_26 -> V_30 ) {
case V_95 :
V_26 -> V_30 = V_96 ;
case V_96 :
V_23 -> V_90 = 1 ;
V_41 . type = V_97 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_98 ;
if ( V_23 -> V_14 & V_57 )
V_41 . V_99 [ 0 ] = 0 ;
else
V_41 . V_99 [ 0 ] = 1 ;
if ( V_23 -> V_14 & V_58 )
V_26 -> V_30 = V_100 ;
else
V_26 -> V_30 = V_101 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
break;
case V_100 :
V_23 -> V_90 = V_29 -> V_71 ;
V_41 . type = V_52 ;
V_41 . V_39 = V_29 -> V_50 ;
V_26 -> V_30 = V_101 ;
F_15 (np, nc) {
V_41 . V_51 = V_7 -> V_50 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
break;
case V_101 :
V_23 -> V_90 = 1 ;
V_41 . type = V_102 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
V_26 -> V_30 = V_103 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
break;
case V_103 :
V_23 -> V_90 = 1 ;
V_41 . type = V_104 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
V_41 . V_99 [ 0 ] = 1 ;
V_26 -> V_30 = V_105 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
break;
case V_105 :
V_23 -> V_90 = 1 ;
V_41 . type = V_106 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_98 ;
V_26 -> V_30 = V_107 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
break;
case V_107 :
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_7 -> V_30 = V_47 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_21 ( V_23 ) ;
break;
default:
F_51 ( V_26 -> V_54 , L_2 ,
V_26 -> V_30 ) ;
}
return;
error:
V_26 -> V_30 = V_31 ;
}
static void F_52 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_92 * V_54 = V_26 -> V_54 ;
struct V_28 * V_29 = V_23 -> V_93 ;
struct V_6 * V_7 = V_23 -> V_94 ;
struct V_6 * V_108 = NULL ;
struct V_40 V_41 ;
unsigned char V_12 ;
unsigned long V_14 ;
int V_45 ;
V_41 . V_23 = V_23 ;
V_41 . V_53 = V_89 ;
switch ( V_26 -> V_30 ) {
case V_109 :
case V_110 :
V_23 -> V_90 = 1 ;
V_41 . type = V_97 ;
if ( V_23 -> V_14 & V_57 )
V_41 . V_99 [ 0 ] = 0 ;
else
V_41 . V_99 [ 0 ] = 1 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_98 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
V_26 -> V_30 = V_111 ;
break;
case V_111 :
V_23 -> V_90 = 1 ;
V_41 . type = V_112 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
V_26 -> V_30 = V_113 ;
break;
case V_113 :
case V_114 :
#if F_53 ( V_115 )
case V_116 :
#endif
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_23 -> V_90 = 1 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
if ( V_26 -> V_30 == V_113 ) {
V_41 . type = V_121 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_41 . V_99 [ V_12 ] = V_54 -> V_122 [ V_12 ] ;
V_41 . V_99 [ 6 ] = 0x1 ;
V_41 . V_99 [ 7 ] = 0x1 ;
V_26 -> V_30 = V_114 ;
} else if ( V_26 -> V_30 == V_114 ) {
V_41 . type = V_123 ;
V_41 . V_124 [ 0 ] = V_7 -> V_67 [ V_125 ] . V_126 ;
V_26 -> V_30 = V_117 ;
#if F_53 ( V_115 )
if ( V_23 -> V_127 > 0 &&
( V_7 -> V_67 [ V_128 ] . V_126 &
V_129 ) )
V_26 -> V_30 = V_116 ;
else
V_26 -> V_30 = V_117 ;
} else if ( V_26 -> V_30 == V_116 ) {
V_41 . type = V_130 ;
V_41 . V_124 [ 0 ] = V_7 -> V_67 [ V_131 ] . V_126 ;
V_26 -> V_30 = V_117 ;
#endif
} else if ( V_26 -> V_30 == V_117 ) {
V_41 . type = V_132 ;
V_26 -> V_30 = V_118 ;
} else if ( V_26 -> V_30 == V_118 ) {
V_41 . type = V_133 ;
V_26 -> V_30 = V_119 ;
if ( ! ( V_7 -> V_67 [ V_134 ] . V_126 & V_135 ) )
V_26 -> V_30 = V_120 ;
} else if ( V_26 -> V_30 == V_119 ) {
V_41 . type = V_136 ;
V_41 . V_99 [ 0 ] = 0 ;
V_41 . V_124 [ 1 ] = V_7 -> V_67 [ V_134 ] . V_126 ;
V_26 -> V_30 = V_120 ;
} else if ( V_26 -> V_30 == V_120 ) {
V_41 . type = V_52 ;
V_26 -> V_30 = V_137 ;
}
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
break;
case V_137 :
F_5 ( & V_7 -> V_17 , V_14 ) ;
if ( V_7 -> V_36 [ V_37 ] . V_8 [ 2 ] & 0x1 ) {
V_108 = V_7 ;
V_7 -> V_30 = V_35 ;
} else {
V_108 = NULL ;
V_7 -> V_30 = V_47 ;
}
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_23 -> V_138 = V_108 ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_23 ( V_7 ) ;
F_21 ( V_23 ) ;
break;
default:
F_51 ( V_54 , L_3 ,
V_26 -> V_30 ) ;
}
return;
error:
F_13 ( V_23 , true ) ;
}
static int F_54 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 , * V_83 , * V_108 ;
struct V_139 * V_140 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_108 = V_23 -> V_138 ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
V_83 = NULL ;
F_14 (ndp, np) {
F_15 (np, nc) {
F_5 ( & V_7 -> V_17 , V_14 ) ;
if ( ! F_16 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_47 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
continue;
}
if ( ! V_83 )
V_83 = V_7 ;
if ( V_7 == V_108 )
V_83 = V_7 ;
V_140 = & V_7 -> V_36 [ V_37 ] ;
if ( V_140 -> V_8 [ 2 ] & 0x1 ) {
F_7 ( & V_7 -> V_17 , V_14 ) ;
V_83 = V_7 ;
goto V_141;
}
F_7 ( & V_7 -> V_17 , V_14 ) ;
}
}
if ( ! V_83 ) {
F_13 ( V_23 , true ) ;
return - V_20 ;
}
V_141:
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_20 ( & V_83 -> V_34 , & V_23 -> V_60 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
return F_21 ( V_23 ) ;
}
static bool F_55 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned int V_126 ;
F_14 (ndp, np) {
F_15 (np, nc) {
V_126 = V_7 -> V_67 [ V_128 ] . V_126 ;
if ( ! ( V_126 & V_142 ) ||
( V_126 & V_143 ) !=
V_144 ) {
V_23 -> V_14 &= ~ V_57 ;
return false ;
}
}
}
V_23 -> V_14 |= V_57 ;
return true ;
}
static int F_56 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
F_14 (ndp, np) {
F_15 (np, nc) {
F_24 ( V_7 -> V_30 != V_47 ||
! F_16 ( & V_7 -> V_34 ) ) ;
F_25 ( V_7 ) ;
F_20 ( & V_7 -> V_34 , & V_23 -> V_60 ) ;
}
}
F_7 ( & V_23 -> V_17 , V_14 ) ;
if ( F_16 ( & V_23 -> V_60 ) ) {
F_13 ( V_23 , false ) ;
return - V_19 ;
}
return F_21 ( V_23 ) ;
}
static void F_57 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_40 V_41 ;
unsigned char V_12 ;
int V_45 ;
V_41 . V_23 = V_23 ;
V_41 . V_53 = V_89 ;
switch ( V_26 -> V_30 ) {
case V_145 :
V_26 -> V_30 = V_146 ;
case V_146 :
V_23 -> V_90 = 8 ;
V_41 . type = V_106 ;
V_41 . V_51 = V_98 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
V_26 -> V_30 = V_147 ;
break;
case V_147 :
V_23 -> V_90 = 16 ;
V_41 . type = V_97 ;
V_41 . V_99 [ 0 ] = 1 ;
V_41 . V_51 = V_98 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
V_41 . type = V_106 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_41 . V_39 = V_12 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
V_26 -> V_30 = V_148 ;
break;
case V_148 :
if ( ! V_23 -> V_93 )
V_23 -> V_93 = F_58 (
& V_23 -> V_73 , struct V_28 , V_69 ) ;
else if ( F_59 ( & V_23 -> V_93 -> V_69 ,
& V_23 -> V_73 ) )
V_23 -> V_93 = NULL ;
else
V_23 -> V_93 = F_60 (
V_23 -> V_93 , V_69 ) ;
if ( ! V_23 -> V_93 ) {
V_23 -> V_14 |= V_149 ;
if ( F_55 ( V_23 ) )
F_56 ( V_23 ) ;
else
F_54 ( V_23 ) ;
return;
}
V_23 -> V_90 = 1 ;
V_41 . type = V_97 ;
V_41 . V_99 [ 0 ] = 1 ;
V_41 . V_39 = V_23 -> V_93 -> V_50 ;
V_41 . V_51 = V_98 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
V_26 -> V_30 = V_150 ;
break;
case V_150 :
V_23 -> V_90 = V_98 ;
V_41 . type = V_112 ;
V_41 . V_39 = V_23 -> V_93 -> V_50 ;
for ( V_12 = 0 ; V_12 < V_98 ; V_12 ++ ) {
V_41 . V_51 = V_12 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
V_26 -> V_30 = V_151 ;
break;
case V_151 :
case V_152 :
case V_153 :
V_29 = V_23 -> V_93 ;
V_23 -> V_90 = V_29 -> V_71 ;
if ( V_26 -> V_30 == V_151 )
V_41 . type = V_154 ;
else if ( V_26 -> V_30 == V_152 )
V_41 . type = V_155 ;
else
V_41 . type = V_52 ;
V_41 . V_39 = V_29 -> V_50 ;
F_15 (np, nc) {
V_41 . V_51 = V_7 -> V_50 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
}
if ( V_26 -> V_30 == V_151 )
V_26 -> V_30 = V_152 ;
else if ( V_26 -> V_30 == V_152 )
V_26 -> V_30 = V_153 ;
else
V_26 -> V_30 = V_156 ;
break;
case V_156 :
V_23 -> V_90 = 1 ;
V_41 . type = V_106 ;
V_41 . V_39 = V_23 -> V_93 -> V_50 ;
V_41 . V_51 = V_98 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 )
goto error;
V_26 -> V_30 = V_148 ;
break;
default:
F_51 ( V_26 -> V_54 , L_4 ,
V_26 -> V_30 ) ;
}
return;
error:
F_13 ( V_23 , true ) ;
}
static void F_61 ( struct V_157 * V_91 )
{
struct V_22 * V_23 = F_62 ( V_91 ,
struct V_22 , V_91 ) ;
struct V_25 * V_26 = & V_23 -> V_27 ;
switch ( V_26 -> V_30 & V_158 ) {
case V_145 :
F_57 ( V_23 ) ;
break;
case V_95 :
F_50 ( V_23 ) ;
break;
case V_109 :
F_52 ( V_23 ) ;
break;
default:
F_51 ( V_26 -> V_54 , L_5 ,
V_26 -> V_30 ) ;
}
}
int F_21 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
int V_159 ;
unsigned long V_14 ;
F_5 ( & V_23 -> V_17 , V_14 ) ;
V_7 = F_58 ( & V_23 -> V_60 ,
struct V_6 , V_34 ) ;
if ( ! V_7 ) {
F_7 ( & V_23 -> V_17 , V_14 ) ;
goto V_141;
}
F_63 ( & V_7 -> V_34 ) ;
F_7 ( & V_23 -> V_17 , V_14 ) ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_159 = V_7 -> V_30 ;
V_7 -> V_30 = V_59 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
V_23 -> V_94 = V_7 ;
V_23 -> V_93 = V_7 -> V_39 ;
switch ( V_159 ) {
case V_47 :
V_23 -> V_27 . V_30 = V_109 ;
F_52 ( V_23 ) ;
break;
case V_35 :
V_23 -> V_27 . V_30 = V_95 ;
F_50 ( V_23 ) ;
break;
default:
F_19 ( V_23 -> V_27 . V_54 , L_6 ,
V_159 , V_7 -> V_39 -> V_50 , V_7 -> V_50 ) ;
F_13 ( V_23 , false ) ;
return - V_5 ;
}
return 0 ;
V_141:
V_23 -> V_94 = NULL ;
V_23 -> V_93 = NULL ;
if ( V_23 -> V_14 & V_58 ) {
V_23 -> V_14 &= ~ V_58 ;
return F_54 ( V_23 ) ;
}
F_13 ( V_23 , false ) ;
return - V_20 ;
}
static int F_64 ( struct V_160 * V_161 ,
unsigned long V_162 , void * V_8 )
{
struct V_163 * V_164 = V_8 ;
struct V_92 * V_54 = V_164 -> V_165 -> V_54 ;
struct V_25 * V_26 = F_47 ( V_54 ) ;
struct V_22 * V_23 = V_26 ? F_65 ( V_26 ) : NULL ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_40 V_41 ;
bool V_166 ;
int V_45 ;
if ( ! V_23 || ( F_66 ( & V_164 -> V_167 ) &
( V_168 | V_169 ) ) )
return V_170 ;
switch ( V_162 ) {
case V_171 :
V_166 = ( ++ V_23 -> V_127 ) == 1 ;
V_41 . type = V_130 ;
break;
case V_172 :
V_166 = ( -- V_23 -> V_127 == 0 ) ;
V_41 . type = V_173 ;
break;
default:
return V_170 ;
}
V_29 = V_23 -> V_93 ;
V_7 = V_23 -> V_94 ;
if ( ! V_166 || ! V_29 || ! V_7 )
return V_170 ;
if ( ! ( V_7 -> V_67 [ V_128 ] . V_126 & V_129 ) )
return V_170 ;
V_41 . V_23 = V_23 ;
V_41 . V_53 = 0 ;
V_41 . V_39 = V_29 -> V_50 ;
V_41 . V_51 = V_7 -> V_50 ;
V_41 . V_124 [ 0 ] = V_7 -> V_67 [ V_131 ] . V_126 ;
V_45 = F_18 ( & V_41 ) ;
if ( V_45 ) {
F_51 ( V_54 , L_7 ,
( V_162 == V_171 ) ? L_8 : L_9 , V_45 ) ;
return V_174 ;
}
return V_170 ;
}
struct V_25 * F_67 ( struct V_92 * V_54 ,
void (* V_38)( struct V_25 * V_27 ) )
{
struct V_22 * V_23 ;
struct V_25 * V_26 ;
unsigned long V_14 ;
int V_72 ;
V_26 = F_47 ( V_54 ) ;
if ( V_26 )
return V_26 ;
V_23 = F_29 ( sizeof( * V_23 ) , V_65 ) ;
if ( ! V_23 )
return NULL ;
V_26 = & V_23 -> V_27 ;
V_26 -> V_30 = V_175 ;
V_26 -> V_54 = V_54 ;
V_26 -> V_38 = V_38 ;
V_23 -> V_90 = 0 ;
F_32 ( & V_23 -> V_60 ) ;
F_68 ( & V_23 -> V_91 , F_61 ) ;
F_31 ( & V_23 -> V_17 ) ;
F_32 ( & V_23 -> V_73 ) ;
V_23 -> V_81 = V_84 ;
for ( V_72 = 0 ; V_72 < F_3 ( V_23 -> V_80 ) ; V_72 ++ ) {
V_23 -> V_80 [ V_72 ] . V_50 = V_72 ;
V_23 -> V_80 [ V_72 ] . V_23 = V_23 ;
F_30 ( & V_23 -> V_80 [ V_72 ] . V_61 ,
F_49 ,
( unsigned long ) & V_23 -> V_80 [ V_72 ] ) ;
}
F_5 ( & V_176 , V_14 ) ;
#if F_53 ( V_115 )
V_23 -> V_127 = 0 ;
if ( F_16 ( & V_177 ) )
F_69 ( & V_178 ) ;
#endif
F_20 ( & V_23 -> V_69 , & V_177 ) ;
F_7 ( & V_176 , V_14 ) ;
V_23 -> V_179 . type = F_70 ( V_180 ) ;
V_23 -> V_179 . V_181 = V_182 ;
V_23 -> V_179 . V_54 = V_54 ;
F_71 ( & V_23 -> V_179 ) ;
return V_26 ;
}
int F_72 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_65 ( V_26 ) ;
int V_45 ;
if ( V_26 -> V_30 != V_175 &&
V_26 -> V_30 != V_31 )
return - V_183 ;
if ( ! ( V_23 -> V_14 & V_149 ) ) {
V_26 -> V_30 = V_145 ;
F_45 ( & V_23 -> V_91 ) ;
return 0 ;
}
if ( V_23 -> V_14 & V_57 )
V_45 = F_56 ( V_23 ) ;
else
V_45 = F_54 ( V_23 ) ;
return V_45 ;
}
void F_73 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_65 ( V_26 ) ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
bool V_43 ;
int V_159 ;
unsigned long V_14 ;
F_14 (ndp, np) {
F_15 (np, nc) {
F_25 ( V_7 ) ;
F_5 ( & V_7 -> V_17 , V_14 ) ;
V_43 = ! F_16 ( & V_7 -> V_34 ) ;
V_159 = V_7 -> V_30 ;
V_7 -> V_30 = V_47 ;
F_7 ( & V_7 -> V_17 , V_14 ) ;
F_24 ( V_43 ||
V_159 == V_59 ) ;
}
}
F_13 ( V_23 , true ) ;
}
void F_74 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_65 ( V_26 ) ;
struct V_28 * V_29 , * V_64 ;
unsigned long V_14 ;
F_75 ( & V_23 -> V_179 ) ;
F_39 (np, tmp, &ndp->packages, node)
F_38 ( V_29 ) ;
F_5 ( & V_176 , V_14 ) ;
F_35 ( & V_23 -> V_69 ) ;
#if F_53 ( V_115 )
if ( F_16 ( & V_177 ) )
F_76 ( & V_178 ) ;
#endif
F_7 ( & V_176 , V_14 ) ;
F_33 ( V_23 ) ;
}
