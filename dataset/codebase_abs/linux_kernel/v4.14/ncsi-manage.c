static inline int F_1 ( int V_1 )
{
int V_2 [] = { 2 , 6 , 6 , 6 } ;
F_2 ( F_3 ( V_2 ) != V_3 ) ;
if ( V_1 < V_4 || V_1 >= V_3 )
return - V_5 ;
return V_2 [ V_1 ] ;
}
T_1 * F_4 ( struct V_6 * V_7 , int V_1 , int V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_10 = V_7 -> V_12 [ V_1 ] ;
if ( ! V_10 )
return NULL ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 < 0 )
return NULL ;
return V_10 -> V_13 + V_11 * V_8 ;
}
int F_5 ( struct V_6 * V_7 , int V_1 , void * V_13 )
{
struct V_9 * V_10 ;
void * V_14 ;
int V_8 , V_11 ;
unsigned long V_15 ;
V_10 = V_7 -> V_12 [ V_1 ] ;
if ( ! V_10 )
return - V_16 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_14 = ( void * ) & V_10 -> V_14 ;
V_8 = - 1 ;
while ( ( V_8 = F_7 ( V_14 , V_10 -> V_18 , V_8 + 1 ) )
< V_10 -> V_18 ) {
if ( ! V_13 || ! memcmp ( V_10 -> V_13 + V_11 * V_8 , V_13 , V_11 ) ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
return V_8 ;
}
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
return - V_19 ;
}
int F_9 ( struct V_6 * V_7 , int V_1 , void * V_13 )
{
struct V_9 * V_10 ;
int V_8 , V_11 ;
void * V_14 ;
unsigned long V_15 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_8 = F_5 ( V_7 , V_1 , V_13 ) ;
if ( V_8 >= 0 )
return V_8 ;
V_10 = V_7 -> V_12 [ V_1 ] ;
if ( ! V_10 )
return - V_20 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_14 = ( void * ) & V_10 -> V_14 ;
do {
V_8 = F_10 ( V_14 , V_10 -> V_18 , 0 ) ;
if ( V_8 >= V_10 -> V_18 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
return - V_21 ;
}
} while ( F_11 ( V_8 , V_14 ) );
memcpy ( V_10 -> V_13 + V_11 * V_8 , V_13 , V_11 ) ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
return V_8 ;
}
int F_12 ( struct V_6 * V_7 , int V_1 , int V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
void * V_14 ;
unsigned long V_15 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_10 = V_7 -> V_12 [ V_1 ] ;
if ( ! V_10 || V_8 >= V_10 -> V_18 )
return - V_20 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_14 = ( void * ) & V_10 -> V_14 ;
if ( F_13 ( V_8 , V_14 ) )
memset ( V_10 -> V_13 + V_11 * V_8 , 0 , V_11 ) ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
return 0 ;
}
static void F_14 ( struct V_22 * V_23 , bool V_24 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned long V_15 ;
V_26 -> V_30 = V_31 ;
if ( V_24 ) {
V_26 -> V_32 = 0 ;
goto V_33;
}
V_26 -> V_32 = 0 ;
F_15 (ndp, np) {
F_16 (np, nc) {
F_6 ( & V_7 -> V_17 , V_15 ) ;
if ( ! F_17 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_35 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
continue;
}
if ( V_7 -> V_36 [ V_37 ] . V_13 [ 2 ] & 0x1 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
V_26 -> V_32 = 1 ;
goto V_33;
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
}
}
V_33:
V_26 -> V_38 ( V_26 ) ;
}
static void F_18 ( unsigned long V_13 )
{
struct V_6 * V_7 = (struct V_6 * ) V_13 ;
struct V_28 * V_29 = V_7 -> V_39 ;
struct V_22 * V_23 = V_29 -> V_23 ;
struct V_40 * V_41 ;
struct V_42 V_43 ;
bool V_44 , V_45 ;
unsigned int V_46 ;
unsigned long V_15 ;
int V_30 , V_47 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_30 = V_7 -> V_30 ;
V_45 = ! F_17 ( & V_7 -> V_34 ) ;
V_44 = V_7 -> V_48 . V_44 ;
V_46 = V_7 -> V_48 . V_30 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
if ( ! V_44 || V_45 ) {
F_19 ( V_7 ) ;
return;
}
if ( V_30 != V_49 &&
V_30 != V_35 ) {
F_19 ( V_7 ) ;
return;
}
switch ( V_46 ) {
case V_50 :
case V_51 :
V_43 . V_23 = V_23 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
V_43 . type = V_54 ;
V_43 . V_55 = 0 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
F_21 ( V_23 -> V_27 . V_56 , L_1 ,
V_47 ) ;
break;
case V_57 ... V_58 :
break;
default:
if ( ! ( V_23 -> V_15 & V_59 ) ) {
F_14 ( V_23 , true ) ;
V_23 -> V_15 |= V_60 ;
}
F_19 ( V_7 ) ;
V_41 = & V_7 -> V_36 [ V_37 ] ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_7 -> V_30 = V_61 ;
V_41 -> V_13 [ 2 ] &= ~ 0x1 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_7 -> V_30 = V_35 ;
F_22 ( & V_7 -> V_34 , & V_23 -> V_62 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_23 ( V_23 ) ;
return;
}
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_7 -> V_48 . V_30 ++ ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_24 ( & V_7 -> V_48 . V_63 , V_64 + V_65 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
unsigned long V_15 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
F_26 ( V_7 -> V_48 . V_44 ) ;
V_7 -> V_48 . V_44 = true ;
V_7 -> V_48 . V_30 = V_50 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_24 ( & V_7 -> V_48 . V_63 , V_64 + V_65 ) ;
}
void F_19 ( struct V_6 * V_7 )
{
unsigned long V_15 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
if ( ! V_7 -> V_48 . V_44 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
return;
}
V_7 -> V_48 . V_44 = false ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_27 ( & V_7 -> V_48 . V_63 ) ;
}
struct V_6 * F_28 ( struct V_28 * V_29 ,
unsigned char V_52 )
{
struct V_6 * V_7 ;
F_16 (np, nc) {
if ( V_7 -> V_52 == V_52 )
return V_7 ;
}
return NULL ;
}
struct V_6 * F_29 ( struct V_28 * V_29 , unsigned char V_52 )
{
struct V_6 * V_7 , * V_66 ;
int V_8 ;
unsigned long V_15 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_67 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_52 = V_52 ;
V_7 -> V_39 = V_29 ;
V_7 -> V_30 = V_49 ;
V_7 -> V_48 . V_44 = false ;
F_31 ( & V_7 -> V_48 . V_63 ,
F_18 , ( unsigned long ) V_7 ) ;
F_32 ( & V_7 -> V_17 ) ;
F_33 ( & V_7 -> V_34 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ )
V_7 -> V_69 [ V_8 ] . V_8 = V_8 ;
for ( V_8 = 0 ; V_8 < V_70 ; V_8 ++ )
V_7 -> V_36 [ V_8 ] . V_8 = V_8 ;
F_6 ( & V_29 -> V_17 , V_15 ) ;
V_66 = F_28 ( V_29 , V_52 ) ;
if ( V_66 ) {
F_8 ( & V_29 -> V_17 , V_15 ) ;
F_34 ( V_7 ) ;
return V_66 ;
}
F_22 ( & V_7 -> V_71 , & V_29 -> V_72 ) ;
V_29 -> V_73 ++ ;
F_8 ( & V_29 -> V_17 , V_15 ) ;
return V_7 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_39 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
int V_74 ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
for ( V_74 = 0 ; V_74 < V_3 ; V_74 ++ ) {
V_10 = V_7 -> V_12 [ V_74 ] ;
if ( ! V_10 )
continue;
V_7 -> V_12 [ V_74 ] = NULL ;
F_34 ( V_10 ) ;
}
V_7 -> V_30 = V_49 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_19 ( V_7 ) ;
F_6 ( & V_29 -> V_17 , V_15 ) ;
F_36 ( & V_7 -> V_71 ) ;
V_29 -> V_73 -- ;
F_8 ( & V_29 -> V_17 , V_15 ) ;
F_34 ( V_7 ) ;
}
struct V_28 * F_37 ( struct V_22 * V_23 ,
unsigned char V_52 )
{
struct V_28 * V_29 ;
F_15 (ndp, np) {
if ( V_29 -> V_52 == V_52 )
return V_29 ;
}
return NULL ;
}
struct V_28 * F_38 ( struct V_22 * V_23 ,
unsigned char V_52 )
{
struct V_28 * V_29 , * V_66 ;
unsigned long V_15 ;
V_29 = F_30 ( sizeof( * V_29 ) , V_67 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_52 = V_52 ;
V_29 -> V_23 = V_23 ;
F_32 ( & V_29 -> V_17 ) ;
F_33 ( & V_29 -> V_72 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_66 = F_37 ( V_23 , V_52 ) ;
if ( V_66 ) {
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_34 ( V_29 ) ;
return V_66 ;
}
F_22 ( & V_29 -> V_71 , & V_23 -> V_75 ) ;
V_23 -> V_76 ++ ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
return V_29 ;
}
void F_39 ( struct V_28 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_23 ;
struct V_6 * V_7 , * V_66 ;
unsigned long V_15 ;
F_40 (nc, tmp, &np->channels, node)
F_35 ( V_7 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
F_36 ( & V_29 -> V_71 ) ;
V_23 -> V_76 -- ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_34 ( V_29 ) ;
}
void F_41 ( struct V_22 * V_23 ,
unsigned char V_52 ,
struct V_28 * * V_29 ,
struct V_6 * * V_7 )
{
struct V_28 * V_77 ;
struct V_6 * V_78 ;
V_77 = F_37 ( V_23 , F_42 ( V_52 ) ) ;
V_78 = V_77 ? F_28 ( V_77 , F_43 ( V_52 ) ) : NULL ;
if ( V_29 )
* V_29 = V_77 ;
if ( V_7 )
* V_7 = V_78 ;
}
struct V_79 * F_44 ( struct V_22 * V_23 ,
unsigned int V_55 )
{
struct V_79 * V_80 = NULL ;
int V_74 , V_81 = F_3 ( V_23 -> V_82 ) ;
unsigned long V_15 ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
for ( V_74 = V_23 -> V_83 ; V_74 < V_81 ; V_74 ++ ) {
if ( V_23 -> V_82 [ V_74 ] . V_84 )
continue;
V_80 = & V_23 -> V_82 [ V_74 ] ;
V_80 -> V_84 = true ;
V_80 -> V_15 = V_55 ;
V_23 -> V_83 = V_74 + 1 ;
goto V_85;
}
for ( V_74 = V_86 ; V_74 < V_23 -> V_83 ; V_74 ++ ) {
if ( V_23 -> V_82 [ V_74 ] . V_84 )
continue;
V_80 = & V_23 -> V_82 [ V_74 ] ;
V_80 -> V_84 = true ;
V_80 -> V_15 = V_55 ;
V_23 -> V_83 = V_74 + 1 ;
goto V_85;
}
V_85:
F_8 ( & V_23 -> V_17 , V_15 ) ;
return V_80 ;
}
void F_45 ( struct V_79 * V_80 )
{
struct V_22 * V_23 = V_80 -> V_23 ;
struct V_87 * V_88 , * V_89 ;
unsigned long V_15 ;
bool V_90 ;
if ( V_80 -> V_44 ) {
V_80 -> V_44 = false ;
F_27 ( & V_80 -> V_63 ) ;
}
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_88 = V_80 -> V_88 ;
V_89 = V_80 -> V_89 ;
V_80 -> V_88 = NULL ;
V_80 -> V_89 = NULL ;
V_80 -> V_84 = false ;
V_90 = ! ! ( V_80 -> V_15 & V_91 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
if ( V_90 && V_88 && -- V_23 -> V_92 == 0 )
F_46 ( & V_23 -> V_93 ) ;
F_47 ( V_88 ) ;
F_47 ( V_89 ) ;
}
struct V_25 * F_48 ( struct V_94 * V_56 )
{
struct V_22 * V_23 ;
F_49 (ndp) {
if ( V_23 -> V_27 . V_56 == V_56 )
return & V_23 -> V_27 ;
}
return NULL ;
}
static void F_50 ( unsigned long V_13 )
{
struct V_79 * V_80 = (struct V_79 * ) V_13 ;
struct V_22 * V_23 = V_80 -> V_23 ;
unsigned long V_15 ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_80 -> V_44 = false ;
if ( V_80 -> V_89 || ! V_80 -> V_88 ) {
F_8 ( & V_23 -> V_17 , V_15 ) ;
return;
}
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_45 ( V_80 ) ;
}
static void F_51 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_95 ;
struct V_6 * V_7 = V_23 -> V_96 ;
struct V_42 V_43 ;
unsigned long V_15 ;
int V_47 ;
V_43 . V_23 = V_23 ;
V_43 . V_55 = V_91 ;
switch ( V_26 -> V_30 ) {
case V_97 :
V_26 -> V_30 = V_98 ;
case V_98 :
V_23 -> V_92 = 1 ;
V_43 . type = V_99 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_100 ;
if ( V_23 -> V_15 & V_59 )
V_43 . V_101 [ 0 ] = 0 ;
else
V_43 . V_101 [ 0 ] = 1 ;
if ( V_23 -> V_15 & V_60 )
V_26 -> V_30 = V_102 ;
else
V_26 -> V_30 = V_103 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
break;
case V_102 :
V_23 -> V_92 = V_29 -> V_73 ;
V_43 . type = V_54 ;
V_43 . V_39 = V_29 -> V_52 ;
V_26 -> V_30 = V_103 ;
F_16 (np, nc) {
V_43 . V_53 = V_7 -> V_52 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
break;
case V_103 :
V_23 -> V_92 = 1 ;
V_43 . type = V_104 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
V_26 -> V_30 = V_105 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
break;
case V_105 :
V_23 -> V_92 = 1 ;
V_43 . type = V_106 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
V_43 . V_101 [ 0 ] = 1 ;
V_26 -> V_30 = V_107 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
break;
case V_107 :
V_23 -> V_92 = 1 ;
V_43 . type = V_108 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_100 ;
V_26 -> V_30 = V_109 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
break;
case V_109 :
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_7 -> V_30 = V_49 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_23 ( V_23 ) ;
break;
default:
F_52 ( V_26 -> V_56 , L_2 ,
V_26 -> V_30 ) ;
}
return;
error:
V_26 -> V_30 = V_31 ;
}
static int F_53 ( struct V_22 * V_23 , struct V_6 * V_7 ,
struct V_42 * V_43 )
{
int V_8 ;
T_1 * V_13 ;
T_2 V_110 ;
V_8 = F_5 ( V_7 , V_111 , NULL ) ;
if ( V_8 < 0 ) {
return - 1 ;
}
V_13 = F_4 ( V_7 , V_111 , V_8 ) ;
if ( ! V_13 ) {
F_21 ( V_23 -> V_27 . V_56 ,
L_3 , V_8 ) ;
V_110 = 0 ;
} else {
V_110 = * ( T_2 * ) V_13 ;
}
F_54 ( V_112 , V_23 -> V_27 . V_56 ,
L_4 ,
V_110 , V_8 + 1 ) ;
F_12 ( V_7 , V_111 , V_8 ) ;
V_43 -> type = V_113 ;
V_43 -> V_114 [ 1 ] = V_110 ;
V_43 -> V_101 [ 6 ] = V_8 + 1 ;
V_43 -> V_101 [ 7 ] = 0x00 ;
return 0 ;
}
static int F_55 ( struct V_22 * V_23 , struct V_6 * V_7 ,
struct V_42 * V_43 )
{
struct V_115 * V_116 = NULL ;
int V_8 = 0 ;
F_56 (vlan, &ndp->vlan_vids, list) {
V_8 = F_5 ( V_7 , V_111 , & V_116 -> V_110 ) ;
if ( V_8 < 0 ) {
F_54 ( V_112 , V_23 -> V_27 . V_56 ,
L_5 ,
V_116 -> V_110 ) ;
break;
}
F_54 ( V_112 , V_23 -> V_27 . V_56 ,
L_6 ,
V_116 -> V_110 , V_8 ) ;
}
if ( ! V_116 || V_8 >= 0 ) {
F_54 ( V_112 , V_23 -> V_27 . V_56 ,
L_7 ) ;
return - 1 ;
}
V_8 = F_9 ( V_7 , V_111 , & V_116 -> V_110 ) ;
if ( V_8 < 0 ) {
F_21 ( V_23 -> V_27 . V_56 ,
L_8 , V_8 ) ;
if ( V_8 == - V_21 )
F_21 ( V_23 -> V_27 . V_56 ,
L_9 ,
V_7 -> V_52 ) ;
return - 1 ;
}
F_54 ( V_112 , V_23 -> V_27 . V_56 ,
L_10 ,
V_116 -> V_110 , V_8 + 1 ) ;
V_43 -> type = V_113 ;
V_43 -> V_114 [ 1 ] = V_116 -> V_110 ;
V_43 -> V_101 [ 6 ] = V_8 + 1 ;
V_43 -> V_101 [ 7 ] = 0x01 ;
return 0 ;
}
static void F_57 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_94 * V_56 = V_26 -> V_56 ;
struct V_28 * V_29 = V_23 -> V_95 ;
struct V_6 * V_7 = V_23 -> V_96 ;
struct V_6 * V_117 = NULL ;
struct V_42 V_43 ;
unsigned char V_8 ;
unsigned long V_15 ;
int V_47 ;
V_43 . V_23 = V_23 ;
V_43 . V_55 = V_91 ;
switch ( V_26 -> V_30 ) {
case V_118 :
case V_119 :
V_23 -> V_92 = 1 ;
V_43 . type = V_99 ;
if ( V_23 -> V_15 & V_59 )
V_43 . V_101 [ 0 ] = 0 ;
else
V_43 . V_101 [ 0 ] = 1 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_100 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
V_26 -> V_30 = V_120 ;
break;
case V_120 :
V_23 -> V_92 = 1 ;
V_43 . type = V_121 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
V_26 -> V_30 = V_122 ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
#if F_58 ( V_127 )
case V_128 :
#endif
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_23 -> V_92 = 1 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
if ( V_26 -> V_30 == V_122 ) {
V_47 = F_53 ( V_23 , V_7 , & V_43 ) ;
if ( V_47 ) {
V_26 -> V_30 = V_123 ;
F_46 ( & V_23 -> V_93 ) ;
break;
}
V_26 -> V_30 = V_122 ;
} else if ( V_26 -> V_30 == V_123 ) {
V_47 = F_55 ( V_23 , V_7 , & V_43 ) ;
if ( V_47 ) {
V_26 -> V_30 = V_124 ;
F_46 ( & V_23 -> V_93 ) ;
break;
}
V_26 -> V_30 = V_123 ;
} else if ( V_26 -> V_30 == V_124 ) {
if ( F_17 ( & V_23 -> V_133 ) ) {
V_43 . type = V_134 ;
} else {
V_43 . type = V_135 ;
V_43 . V_101 [ 3 ] = V_136 ;
}
V_26 -> V_30 = V_125 ;
} else if ( V_26 -> V_30 == V_125 ) {
V_43 . type = V_137 ;
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ )
V_43 . V_101 [ V_8 ] = V_56 -> V_138 [ V_8 ] ;
V_43 . V_101 [ 6 ] = 0x1 ;
V_43 . V_101 [ 7 ] = 0x1 ;
V_26 -> V_30 = V_126 ;
} else if ( V_26 -> V_30 == V_126 ) {
V_43 . type = V_139 ;
V_43 . V_140 [ 0 ] = V_7 -> V_69 [ V_141 ] . V_142 ;
V_26 -> V_30 = V_129 ;
#if F_58 ( V_127 )
if ( V_23 -> V_143 > 0 &&
( V_7 -> V_69 [ V_144 ] . V_142 &
V_145 ) )
V_26 -> V_30 = V_128 ;
else
V_26 -> V_30 = V_129 ;
} else if ( V_26 -> V_30 == V_128 ) {
V_43 . type = V_146 ;
V_43 . V_140 [ 0 ] = V_7 -> V_69 [ V_147 ] . V_142 ;
V_26 -> V_30 = V_129 ;
#endif
} else if ( V_26 -> V_30 == V_129 ) {
V_43 . type = V_148 ;
V_26 -> V_30 = V_130 ;
} else if ( V_26 -> V_30 == V_130 ) {
V_43 . type = V_149 ;
V_26 -> V_30 = V_131 ;
if ( ! ( V_7 -> V_69 [ V_150 ] . V_142 & V_151 ) )
V_26 -> V_30 = V_132 ;
} else if ( V_26 -> V_30 == V_131 ) {
V_43 . type = V_152 ;
V_43 . V_101 [ 0 ] = 0 ;
V_43 . V_140 [ 1 ] = V_7 -> V_69 [ V_150 ] . V_142 ;
V_26 -> V_30 = V_132 ;
} else if ( V_26 -> V_30 == V_132 ) {
V_43 . type = V_54 ;
V_26 -> V_30 = V_153 ;
}
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
break;
case V_153 :
F_6 ( & V_7 -> V_17 , V_15 ) ;
if ( V_7 -> V_154 ) {
V_7 -> V_154 = false ;
V_7 -> V_30 = V_49 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
F_22 ( & V_7 -> V_34 , & V_23 -> V_62 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_54 ( V_112 , V_56 ,
L_11 ) ;
F_23 ( V_23 ) ;
break;
}
if ( V_7 -> V_36 [ V_37 ] . V_13 [ 2 ] & 0x1 ) {
V_117 = V_7 ;
V_7 -> V_30 = V_35 ;
} else {
V_117 = NULL ;
V_7 -> V_30 = V_49 ;
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_23 -> V_155 = V_117 ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_25 ( V_7 ) ;
F_23 ( V_23 ) ;
break;
default:
F_52 ( V_56 , L_12 ,
V_26 -> V_30 ) ;
}
return;
error:
F_14 ( V_23 , true ) ;
}
static int F_59 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 , * V_85 , * V_117 ;
struct V_40 * V_41 ;
unsigned long V_15 ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_117 = V_23 -> V_155 ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
V_85 = NULL ;
F_15 (ndp, np) {
F_16 (np, nc) {
F_6 ( & V_7 -> V_17 , V_15 ) ;
if ( ! F_17 ( & V_7 -> V_34 ) ||
V_7 -> V_30 != V_49 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
continue;
}
if ( ! V_85 )
V_85 = V_7 ;
if ( V_7 == V_117 )
V_85 = V_7 ;
V_41 = & V_7 -> V_36 [ V_37 ] ;
if ( V_41 -> V_13 [ 2 ] & 0x1 ) {
F_8 ( & V_7 -> V_17 , V_15 ) ;
V_85 = V_7 ;
goto V_156;
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
}
}
if ( ! V_85 ) {
F_14 ( V_23 , true ) ;
return - V_20 ;
}
V_156:
F_6 ( & V_23 -> V_17 , V_15 ) ;
F_22 ( & V_85 -> V_34 , & V_23 -> V_62 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
return F_23 ( V_23 ) ;
}
static bool F_60 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned int V_142 ;
bool V_157 = false ;
F_15 (ndp, np) {
F_16 (np, nc) {
V_157 = true ;
V_142 = V_7 -> V_69 [ V_144 ] . V_142 ;
if ( ! ( V_142 & V_158 ) ||
( V_142 & V_159 ) !=
V_160 ) {
V_23 -> V_15 &= ~ V_59 ;
return false ;
}
}
}
if ( V_157 ) {
V_23 -> V_15 |= V_59 ;
return true ;
}
V_23 -> V_15 &= ~ V_59 ;
return false ;
}
static int F_61 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned long V_15 ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
F_15 (ndp, np) {
F_16 (np, nc) {
F_26 ( V_7 -> V_30 != V_49 ||
! F_17 ( & V_7 -> V_34 ) ) ;
F_19 ( V_7 ) ;
F_22 ( & V_7 -> V_34 , & V_23 -> V_62 ) ;
}
}
F_8 ( & V_23 -> V_17 , V_15 ) ;
if ( F_17 ( & V_23 -> V_62 ) ) {
F_14 ( V_23 , false ) ;
return - V_19 ;
}
return F_23 ( V_23 ) ;
}
static void F_62 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_42 V_43 ;
unsigned char V_8 ;
int V_47 ;
V_43 . V_23 = V_23 ;
V_43 . V_55 = V_91 ;
switch ( V_26 -> V_30 ) {
case V_161 :
V_26 -> V_30 = V_162 ;
case V_162 :
V_23 -> V_92 = 8 ;
V_43 . type = V_108 ;
V_43 . V_53 = V_100 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_43 . V_39 = V_8 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
V_26 -> V_30 = V_163 ;
break;
case V_163 :
V_23 -> V_92 = 16 ;
V_43 . type = V_99 ;
V_43 . V_101 [ 0 ] = 1 ;
V_43 . V_53 = V_100 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_43 . V_39 = V_8 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
V_43 . type = V_108 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_43 . V_39 = V_8 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
V_26 -> V_30 = V_164 ;
break;
case V_164 :
if ( ! V_23 -> V_95 )
V_23 -> V_95 = F_63 (
& V_23 -> V_75 , struct V_28 , V_71 ) ;
else if ( F_64 ( & V_23 -> V_95 -> V_71 ,
& V_23 -> V_75 ) )
V_23 -> V_95 = NULL ;
else
V_23 -> V_95 = F_65 (
V_23 -> V_95 , V_71 ) ;
if ( ! V_23 -> V_95 ) {
V_23 -> V_15 |= V_165 ;
if ( F_60 ( V_23 ) )
F_61 ( V_23 ) ;
else
F_59 ( V_23 ) ;
return;
}
V_23 -> V_92 = 1 ;
V_43 . type = V_99 ;
V_43 . V_101 [ 0 ] = 1 ;
V_43 . V_39 = V_23 -> V_95 -> V_52 ;
V_43 . V_53 = V_100 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
V_26 -> V_30 = V_166 ;
break;
case V_166 :
V_23 -> V_92 = V_100 ;
V_43 . type = V_121 ;
V_43 . V_39 = V_23 -> V_95 -> V_52 ;
for ( V_8 = 0 ; V_8 < V_100 ; V_8 ++ ) {
V_43 . V_53 = V_8 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
V_26 -> V_30 = V_167 ;
break;
case V_167 :
case V_168 :
case V_169 :
V_29 = V_23 -> V_95 ;
V_23 -> V_92 = V_29 -> V_73 ;
if ( V_26 -> V_30 == V_167 )
V_43 . type = V_170 ;
else if ( V_26 -> V_30 == V_168 )
V_43 . type = V_171 ;
else
V_43 . type = V_54 ;
V_43 . V_39 = V_29 -> V_52 ;
F_16 (np, nc) {
V_43 . V_53 = V_7 -> V_52 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
}
if ( V_26 -> V_30 == V_167 )
V_26 -> V_30 = V_168 ;
else if ( V_26 -> V_30 == V_168 )
V_26 -> V_30 = V_169 ;
else
V_26 -> V_30 = V_172 ;
break;
case V_172 :
V_23 -> V_92 = 1 ;
V_43 . type = V_108 ;
V_43 . V_39 = V_23 -> V_95 -> V_52 ;
V_43 . V_53 = V_100 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 )
goto error;
V_26 -> V_30 = V_164 ;
break;
default:
F_52 ( V_26 -> V_56 , L_13 ,
V_26 -> V_30 ) ;
}
return;
error:
F_14 ( V_23 , true ) ;
}
static void F_66 ( struct V_173 * V_93 )
{
struct V_22 * V_23 = F_67 ( V_93 ,
struct V_22 , V_93 ) ;
struct V_25 * V_26 = & V_23 -> V_27 ;
switch ( V_26 -> V_30 & V_174 ) {
case V_161 :
F_62 ( V_23 ) ;
break;
case V_97 :
F_51 ( V_23 ) ;
break;
case V_118 :
F_57 ( V_23 ) ;
break;
default:
F_52 ( V_26 -> V_56 , L_14 ,
V_26 -> V_30 ) ;
}
}
int F_23 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
int V_175 ;
unsigned long V_15 ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
V_7 = F_63 ( & V_23 -> V_62 ,
struct V_6 , V_34 ) ;
if ( ! V_7 ) {
F_8 ( & V_23 -> V_17 , V_15 ) ;
goto V_156;
}
F_68 ( & V_7 -> V_34 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_175 = V_7 -> V_30 ;
V_7 -> V_30 = V_61 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
V_23 -> V_96 = V_7 ;
V_23 -> V_95 = V_7 -> V_39 ;
switch ( V_175 ) {
case V_49 :
V_23 -> V_27 . V_30 = V_118 ;
F_57 ( V_23 ) ;
break;
case V_35 :
V_23 -> V_27 . V_30 = V_97 ;
F_51 ( V_23 ) ;
break;
default:
F_21 ( V_23 -> V_27 . V_56 , L_15 ,
V_175 , V_7 -> V_39 -> V_52 , V_7 -> V_52 ) ;
F_14 ( V_23 , false ) ;
return - V_5 ;
}
return 0 ;
V_156:
V_23 -> V_96 = NULL ;
V_23 -> V_95 = NULL ;
if ( V_23 -> V_15 & V_60 ) {
V_23 -> V_15 &= ~ V_60 ;
return F_59 ( V_23 ) ;
}
F_14 ( V_23 , false ) ;
return - V_20 ;
}
static int F_69 ( struct V_176 * V_177 ,
unsigned long V_178 , void * V_13 )
{
struct V_179 * V_180 = V_13 ;
struct V_94 * V_56 = V_180 -> V_181 -> V_56 ;
struct V_25 * V_26 = F_48 ( V_56 ) ;
struct V_22 * V_23 = V_26 ? F_70 ( V_26 ) : NULL ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
struct V_42 V_43 ;
bool V_182 ;
int V_47 ;
if ( ! V_23 || ( F_71 ( & V_180 -> V_183 ) &
( V_184 | V_185 ) ) )
return V_186 ;
switch ( V_178 ) {
case V_187 :
V_182 = ( ++ V_23 -> V_143 ) == 1 ;
V_43 . type = V_146 ;
break;
case V_188 :
V_182 = ( -- V_23 -> V_143 == 0 ) ;
V_43 . type = V_189 ;
break;
default:
return V_186 ;
}
V_29 = V_23 -> V_95 ;
V_7 = V_23 -> V_96 ;
if ( ! V_182 || ! V_29 || ! V_7 )
return V_186 ;
if ( ! ( V_7 -> V_69 [ V_144 ] . V_142 & V_145 ) )
return V_186 ;
V_43 . V_23 = V_23 ;
V_43 . V_55 = 0 ;
V_43 . V_39 = V_29 -> V_52 ;
V_43 . V_53 = V_7 -> V_52 ;
V_43 . V_140 [ 0 ] = V_7 -> V_69 [ V_147 ] . V_142 ;
V_47 = F_20 ( & V_43 ) ;
if ( V_47 ) {
F_52 ( V_56 , L_16 ,
( V_178 == V_187 ) ? L_17 : L_18 , V_47 ) ;
return V_190 ;
}
return V_186 ;
}
static int F_72 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = & V_23 -> V_27 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
unsigned long V_15 ;
unsigned int V_191 = 0 ;
F_15 (ndp, np) {
F_16 (np, nc) {
F_6 ( & V_7 -> V_17 , V_15 ) ;
if ( V_7 -> V_30 != V_35 ) {
if ( ( V_23 -> V_27 . V_30 & 0xff00 ) ==
V_118 ||
! F_17 ( & V_7 -> V_34 ) ) {
F_54 ( V_112 , V_26 -> V_56 ,
L_19 ,
V_7 ) ;
V_7 -> V_154 = true ;
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
continue;
}
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_19 ( V_7 ) ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_7 -> V_30 = V_49 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_6 ( & V_23 -> V_17 , V_15 ) ;
F_22 ( & V_7 -> V_34 , & V_23 -> V_62 ) ;
F_8 ( & V_23 -> V_17 , V_15 ) ;
F_54 ( V_112 , V_26 -> V_56 ,
L_20 , V_7 ) ;
V_191 ++ ;
}
}
return V_191 ;
}
int F_73 ( struct V_94 * V_56 , T_3 V_192 , T_2 V_110 )
{
struct V_22 * V_23 ;
unsigned int V_193 = 0 ;
struct V_115 * V_116 ;
struct V_25 * V_26 ;
bool V_85 = false ;
if ( V_110 == 0 )
return 0 ;
V_26 = F_48 ( V_56 ) ;
if ( ! V_26 ) {
F_52 ( V_56 , L_21 ) ;
return 0 ;
}
V_23 = F_70 ( V_26 ) ;
F_56 (vlan, &ndp->vlan_vids, list) {
V_193 ++ ;
if ( V_116 -> V_110 == V_110 ) {
F_54 ( V_112 , V_56 ,
L_22 , V_110 ) ;
return 0 ;
}
}
if ( V_193 >= V_194 ) {
F_52 ( V_56 ,
L_23 ,
V_110 , V_194 ) ;
return - V_21 ;
}
V_116 = F_30 ( sizeof( * V_116 ) , V_195 ) ;
if ( ! V_116 )
return - V_196 ;
V_116 -> V_192 = V_192 ;
V_116 -> V_110 = V_110 ;
F_74 ( & V_116 -> V_197 , & V_23 -> V_133 ) ;
F_54 ( V_112 , V_56 , L_24 , V_110 ) ;
V_85 = F_72 ( V_23 ) != 0 ;
return V_85 ? F_23 ( V_23 ) : 0 ;
}
int F_75 ( struct V_94 * V_56 , T_3 V_192 , T_2 V_110 )
{
struct V_115 * V_116 , * V_66 ;
struct V_22 * V_23 ;
struct V_25 * V_26 ;
bool V_85 = false ;
if ( V_110 == 0 )
return 0 ;
V_26 = F_48 ( V_56 ) ;
if ( ! V_26 ) {
F_52 ( V_56 , L_25 ) ;
return 0 ;
}
V_23 = F_70 ( V_26 ) ;
F_40 (vlan, tmp, &ndp->vlan_vids, list)
if ( V_116 -> V_110 == V_110 ) {
F_54 ( V_112 , V_56 ,
L_26 , V_110 ) ;
F_36 ( & V_116 -> V_197 ) ;
V_85 = true ;
F_34 ( V_116 ) ;
}
if ( ! V_85 ) {
F_21 ( V_56 , L_27 , V_110 ) ;
return - V_5 ;
}
V_85 = F_72 ( V_23 ) != 0 ;
return V_85 ? F_23 ( V_23 ) : 0 ;
}
struct V_25 * F_76 ( struct V_94 * V_56 ,
void (* V_38)( struct V_25 * V_27 ) )
{
struct V_22 * V_23 ;
struct V_25 * V_26 ;
unsigned long V_15 ;
int V_74 ;
V_26 = F_48 ( V_56 ) ;
if ( V_26 )
return V_26 ;
V_23 = F_30 ( sizeof( * V_23 ) , V_67 ) ;
if ( ! V_23 )
return NULL ;
V_26 = & V_23 -> V_27 ;
V_26 -> V_30 = V_198 ;
V_26 -> V_56 = V_56 ;
V_26 -> V_38 = V_38 ;
V_23 -> V_92 = 0 ;
F_33 ( & V_23 -> V_62 ) ;
F_33 ( & V_23 -> V_133 ) ;
F_77 ( & V_23 -> V_93 , F_66 ) ;
F_32 ( & V_23 -> V_17 ) ;
F_33 ( & V_23 -> V_75 ) ;
V_23 -> V_83 = V_86 ;
for ( V_74 = 0 ; V_74 < F_3 ( V_23 -> V_82 ) ; V_74 ++ ) {
V_23 -> V_82 [ V_74 ] . V_52 = V_74 ;
V_23 -> V_82 [ V_74 ] . V_23 = V_23 ;
F_31 ( & V_23 -> V_82 [ V_74 ] . V_63 ,
F_50 ,
( unsigned long ) & V_23 -> V_82 [ V_74 ] ) ;
}
F_6 ( & V_199 , V_15 ) ;
#if F_58 ( V_127 )
V_23 -> V_143 = 0 ;
if ( F_17 ( & V_200 ) )
F_78 ( & V_201 ) ;
#endif
F_22 ( & V_23 -> V_71 , & V_200 ) ;
F_8 ( & V_199 , V_15 ) ;
V_23 -> V_202 . type = F_79 ( V_203 ) ;
V_23 -> V_202 . V_204 = V_205 ;
V_23 -> V_202 . V_56 = V_56 ;
F_80 ( & V_23 -> V_202 ) ;
return V_26 ;
}
int F_81 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_70 ( V_26 ) ;
int V_47 ;
if ( V_26 -> V_30 != V_198 &&
V_26 -> V_30 != V_31 )
return - V_206 ;
if ( ! ( V_23 -> V_15 & V_165 ) ) {
V_26 -> V_30 = V_161 ;
F_46 ( & V_23 -> V_93 ) ;
return 0 ;
}
if ( V_23 -> V_15 & V_59 )
V_47 = F_61 ( V_23 ) ;
else
V_47 = F_59 ( V_23 ) ;
return V_47 ;
}
void F_82 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_70 ( V_26 ) ;
struct V_28 * V_29 ;
struct V_6 * V_7 ;
bool V_45 ;
int V_175 ;
unsigned long V_15 ;
F_15 (ndp, np) {
F_16 (np, nc) {
F_19 ( V_7 ) ;
F_6 ( & V_7 -> V_17 , V_15 ) ;
V_45 = ! F_17 ( & V_7 -> V_34 ) ;
V_175 = V_7 -> V_30 ;
V_7 -> V_30 = V_49 ;
F_8 ( & V_7 -> V_17 , V_15 ) ;
F_26 ( V_45 ||
V_175 == V_61 ) ;
}
}
F_14 ( V_23 , true ) ;
}
void F_83 ( struct V_25 * V_26 )
{
struct V_22 * V_23 = F_70 ( V_26 ) ;
struct V_28 * V_29 , * V_66 ;
unsigned long V_15 ;
F_84 ( & V_23 -> V_202 ) ;
F_40 (np, tmp, &ndp->packages, node)
F_39 ( V_29 ) ;
F_6 ( & V_199 , V_15 ) ;
F_36 ( & V_23 -> V_71 ) ;
#if F_58 ( V_127 )
if ( F_17 ( & V_200 ) )
F_85 ( & V_201 ) ;
#endif
F_8 ( & V_199 , V_15 ) ;
F_34 ( V_23 ) ;
}
