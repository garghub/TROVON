static const char * F_1 ( unsigned int V_1 )
{
V_1 &= V_2 | V_3 ;
switch ( V_1 ) {
case V_2 | V_3 :
return L_1 ;
case V_2 :
return L_2 ;
case V_3 :
return L_3 ;
}
return L_4 ;
}
static int F_2 ( char * V_4 , int V_5 , int * V_6 )
{
if ( strncmp ( V_4 , L_4 , 4 ) == 0 ) {
* V_6 = V_7 ;
return 1 ;
}
if ( strncmp ( V_4 , L_1 , 6 ) == 0 )
goto V_8;
else if ( strncmp ( V_4 , L_2 , 2 ) == 0 )
goto V_8;
else if ( strncmp ( V_4 , L_3 , 3 ) == 0 )
goto V_8;
return 0 ;
V_8:
* V_6 = V_2 | V_3 ;
return 1 ;
}
static struct V_9 * F_3 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
F_4 (vgadev, &vga_list, list)
if ( V_11 == V_12 -> V_11 )
return V_12 ;
return NULL ;
}
struct V_10 * F_5 ( void )
{
return V_13 ;
}
void F_6 ( struct V_10 * V_11 )
{
if ( V_13 == V_11 )
return;
F_7 ( V_13 ) ;
V_13 = F_8 ( V_11 ) ;
}
static inline void F_9 ( struct V_9 * V_12 , bool V_14 )
{
if ( V_12 -> V_15 )
V_12 -> V_15 ( V_12 -> V_16 , V_14 ) ;
}
static void F_10 ( void )
{
if ( ! V_17 ) {
V_17 = true ;
F_11 () ;
}
}
static struct V_9 * F_12 ( struct V_9 * V_12 ,
unsigned int V_18 )
{
struct V_19 * V_20 = & V_12 -> V_11 -> V_20 ;
unsigned int V_21 , V_22 , V_23 ;
struct V_9 * V_24 ;
unsigned int V_25 ;
T_1 V_26 = 0 ;
if ( ( V_18 & V_27 ) &&
( V_12 -> V_28 & V_2 ) )
V_18 |= V_2 ;
if ( ( V_18 & V_29 ) &&
( V_12 -> V_28 & V_3 ) )
V_18 |= V_3 ;
F_13 ( V_20 , L_5 , V_30 , V_18 ) ;
F_13 ( V_20 , L_6 , V_30 , V_12 -> V_31 ) ;
V_21 = V_18 & ~ V_12 -> V_31 ;
if ( V_21 == 0 )
goto V_32;
V_22 = V_21 & V_33 ;
if ( V_22 == 0 )
goto V_34;
F_4 (conflict, &vga_list, list) {
unsigned int V_35 = V_22 ;
unsigned int V_36 = 0 ;
if ( V_12 == V_24 )
continue;
if ( ! F_14 ( V_12 -> V_11 , V_24 -> V_11 ) )
continue;
if ( V_12 -> V_11 -> V_37 != V_24 -> V_11 -> V_37 ) {
V_36 = 1 ;
V_35 = V_2 | V_3 ;
}
if ( V_24 -> V_38 & V_35 )
return V_24 ;
V_23 = V_35 & V_24 -> V_31 ;
if ( ! V_23 )
continue;
V_26 = 0 ;
V_25 = 0 ;
if ( ! V_24 -> V_39 ) {
if ( ( V_23 & V_24 -> V_28 ) & V_3 )
V_25 |= V_40 ;
if ( ( V_23 & V_24 -> V_28 ) & V_2 )
V_25 |= V_41 ;
if ( V_25 ) {
F_9 ( V_24 , false ) ;
V_26 |= V_42 ;
}
}
if ( V_36 )
V_26 |= V_43 ;
F_15 ( V_24 -> V_11 , false , V_25 , V_26 ) ;
V_24 -> V_31 &= ~ V_23 ;
if ( V_25 & V_40 )
V_24 -> V_31 &= ~ V_29 ;
if ( V_25 & V_41 )
V_24 -> V_31 &= ~ V_27 ;
}
V_34:
V_26 = 0 ;
V_25 = 0 ;
if ( ! V_12 -> V_39 ) {
V_26 |= V_42 ;
if ( V_21 & ( V_3 | V_29 ) )
V_25 |= V_40 ;
if ( V_21 & ( V_2 | V_27 ) )
V_25 |= V_41 ;
}
if ( V_21 & V_33 )
V_26 |= V_43 ;
F_15 ( V_12 -> V_11 , true , V_25 , V_26 ) ;
if ( ! V_12 -> V_39 )
F_9 ( V_12 , true ) ;
V_12 -> V_31 |= V_21 ;
V_32:
V_12 -> V_38 |= ( V_18 & V_33 ) ;
if ( V_18 & V_2 )
V_12 -> V_44 ++ ;
if ( V_18 & V_3 )
V_12 -> V_45 ++ ;
if ( V_18 & V_27 )
V_12 -> V_46 ++ ;
if ( V_18 & V_29 )
V_12 -> V_47 ++ ;
return NULL ;
}
static void F_16 ( struct V_9 * V_12 , unsigned int V_18 )
{
struct V_19 * V_20 = & V_12 -> V_11 -> V_20 ;
unsigned int V_48 = V_12 -> V_38 ;
F_13 ( V_20 , L_7 , V_30 ) ;
if ( ( V_18 & V_27 ) && V_12 -> V_46 > 0 ) {
V_12 -> V_46 -- ;
if ( V_12 -> V_28 & V_2 )
V_18 |= V_2 ;
}
if ( ( V_18 & V_29 ) && V_12 -> V_47 > 0 ) {
V_12 -> V_47 -- ;
if ( V_12 -> V_28 & V_3 )
V_18 |= V_3 ;
}
if ( ( V_18 & V_2 ) && V_12 -> V_44 > 0 )
V_12 -> V_44 -- ;
if ( ( V_18 & V_3 ) && V_12 -> V_45 > 0 )
V_12 -> V_45 -- ;
if ( V_12 -> V_44 == 0 )
V_12 -> V_38 &= ~ V_2 ;
if ( V_12 -> V_45 == 0 )
V_12 -> V_38 &= ~ V_3 ;
if ( V_48 != V_12 -> V_38 )
F_17 ( & V_49 ) ;
}
int F_18 ( struct V_10 * V_11 , unsigned int V_18 , int V_50 )
{
struct V_9 * V_12 , * V_24 ;
unsigned long V_26 ;
T_2 V_51 ;
int V_52 = 0 ;
F_10 () ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return 0 ;
for (; ; ) {
F_19 ( & V_53 , V_26 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
F_20 ( & V_53 , V_26 ) ;
V_52 = - V_54 ;
break;
}
V_24 = F_12 ( V_12 , V_18 ) ;
F_20 ( & V_53 , V_26 ) ;
if ( V_24 == NULL )
break;
F_21 ( & V_51 , V_55 ) ;
F_22 ( & V_49 , & V_51 ) ;
F_23 ( V_50 ?
V_56 :
V_57 ) ;
if ( V_50 && F_24 ( V_55 ) ) {
F_25 ( V_58 ) ;
F_26 ( & V_49 , & V_51 ) ;
V_52 = - V_59 ;
break;
}
F_27 () ;
F_26 ( & V_49 , & V_51 ) ;
}
return V_52 ;
}
int F_28 ( struct V_10 * V_11 , unsigned int V_18 )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
int V_52 = 0 ;
F_10 () ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return 0 ;
F_19 ( & V_53 , V_26 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
V_52 = - V_54 ;
goto V_60;
}
if ( F_12 ( V_12 , V_18 ) )
V_52 = - V_61 ;
V_60:
F_20 ( & V_53 , V_26 ) ;
return V_52 ;
}
void F_29 ( struct V_10 * V_11 , unsigned int V_18 )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return;
F_19 ( & V_53 , V_26 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL )
goto V_60;
F_16 ( V_12 , V_18 ) ;
V_60:
F_20 ( & V_53 , V_26 ) ;
}
static void F_30 ( struct V_9 * V_12 )
{
struct V_9 * V_62 ;
struct V_63 * V_64 , * V_37 ;
struct V_10 * V_65 , * V_66 ;
V_12 -> V_39 = true ;
if ( F_31 ( & V_67 ) )
return;
V_64 = V_12 -> V_11 -> V_37 ;
while ( V_64 ) {
V_65 = V_64 -> V_68 ;
F_4 (same_bridge_vgadev, &vga_list, list) {
V_37 = V_62 -> V_11 -> V_37 ;
V_66 = V_37 -> V_68 ;
if ( V_65 == V_66 ) {
V_62 -> V_39 = false ;
}
while ( V_37 ) {
V_66 = V_37 -> V_68 ;
if ( V_66 && V_66 == V_12 -> V_11 -> V_37 -> V_68 )
V_12 -> V_39 = false ;
V_37 = V_37 -> V_69 ;
}
}
V_64 = V_64 -> V_69 ;
}
}
static bool F_32 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
struct V_63 * V_37 ;
struct V_10 * V_66 ;
T_3 V_70 ;
if ( ( V_11 -> V_71 >> 8 ) != V_72 )
return false ;
V_12 = F_33 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_12 == NULL ) {
F_34 ( & V_11 -> V_20 , L_8 ) ;
return false ;
}
F_19 ( & V_53 , V_26 ) ;
if ( F_3 ( V_11 ) != NULL ) {
F_35 ( 1 ) ;
goto V_74;
}
V_12 -> V_11 = V_11 ;
V_12 -> V_28 = V_2 | V_3 |
V_27 | V_29 ;
V_75 ++ ;
F_36 ( V_11 , V_76 , & V_70 ) ;
if ( V_70 & V_41 )
V_12 -> V_31 |= V_2 ;
if ( V_70 & V_40 )
V_12 -> V_31 |= V_3 ;
V_37 = V_11 -> V_37 ;
while ( V_37 ) {
V_66 = V_37 -> V_68 ;
if ( V_66 ) {
T_3 V_77 ;
F_36 ( V_66 , V_78 , & V_77 ) ;
if ( ! ( V_77 & V_79 ) ) {
V_12 -> V_31 = 0 ;
break;
}
}
V_37 = V_37 -> V_69 ;
}
if ( V_13 == NULL &&
( ( V_12 -> V_31 & V_33 ) == V_33 ) ) {
F_37 ( & V_11 -> V_20 , L_9 ) ;
F_6 ( V_11 ) ;
}
F_30 ( V_12 ) ;
F_38 ( & V_12 -> V_80 , & V_67 ) ;
V_81 ++ ;
F_37 ( & V_11 -> V_20 , L_10 ,
F_1 ( V_12 -> V_28 ) ,
F_1 ( V_12 -> V_31 ) ,
F_1 ( V_12 -> V_38 ) ) ;
F_20 ( & V_53 , V_26 ) ;
return true ;
V_74:
F_20 ( & V_53 , V_26 ) ;
F_39 ( V_12 ) ;
return false ;
}
static bool F_40 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
bool V_82 = true ;
F_19 ( & V_53 , V_26 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
V_82 = false ;
goto V_60;
}
if ( V_13 == V_11 )
F_6 ( NULL ) ;
if ( V_12 -> V_28 & ( V_2 | V_3 ) )
V_75 -- ;
F_41 ( & V_12 -> V_80 ) ;
V_81 -- ;
F_42 ( V_11 ) ;
F_17 ( & V_49 ) ;
V_60:
F_20 ( & V_53 , V_26 ) ;
F_39 ( V_12 ) ;
return V_82 ;
}
static inline void F_43 ( struct V_9 * V_12 ,
int V_83 )
{
struct V_19 * V_20 = & V_12 -> V_11 -> V_20 ;
int V_84 , V_85 , V_86 ;
V_84 = V_12 -> V_28 ;
V_85 = ~ V_83 & V_84 ;
V_86 = V_12 -> V_38 & V_85 ;
V_12 -> V_28 = V_83 ;
F_37 ( V_20 , L_11 ,
F_1 ( V_84 ) ,
F_1 ( V_12 -> V_28 ) ,
F_1 ( V_12 -> V_31 ) ) ;
if ( V_86 ) {
if ( V_86 & V_2 )
V_12 -> V_44 = 0 ;
if ( V_86 & V_3 )
V_12 -> V_45 = 0 ;
F_16 ( V_12 , V_86 ) ;
}
if ( V_84 & V_33 &&
! ( V_83 & V_33 ) )
V_75 -- ;
if ( ! ( V_84 & V_33 ) &&
V_83 & V_33 )
V_75 ++ ;
F_13 ( V_20 , L_12 , V_75 ) ;
}
static void F_44 ( struct V_10 * V_11 ,
unsigned int V_28 ,
bool V_87 )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
V_28 &= V_33 ;
F_19 ( & V_53 , V_26 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL )
goto V_60;
if ( V_87 && V_12 -> V_88 )
goto V_60;
F_43 ( V_12 , V_28 ) ;
V_60:
F_20 ( & V_53 , V_26 ) ;
}
void F_45 ( struct V_10 * V_11 , unsigned int V_28 )
{
F_44 ( V_11 , V_28 , false ) ;
}
static int F_46 ( char * V_4 , int V_89 , unsigned int * V_90 ,
unsigned int * V_37 , unsigned int * V_91 )
{
int V_92 ;
unsigned int V_93 , V_94 ;
V_92 = sscanf ( V_4 , L_13 , V_90 , V_37 , & V_93 , & V_94 ) ;
if ( V_92 != 4 )
return 0 ;
* V_91 = F_47 ( V_93 , V_94 ) ;
return 1 ;
}
static T_4 F_48 ( struct V_95 * V_95 , char T_5 * V_4 ,
T_6 V_89 , T_7 * V_96 )
{
struct V_97 * V_98 = V_95 -> V_99 ;
struct V_9 * V_12 ;
struct V_10 * V_11 ;
unsigned long V_26 ;
T_6 V_100 ;
int V_52 ;
char * V_101 ;
V_101 = F_49 ( 1024 , V_73 ) ;
if ( V_101 == NULL )
return - V_102 ;
F_19 ( & V_53 , V_26 ) ;
V_11 = V_98 -> V_103 ;
if ( V_11 == NULL || V_11 == V_104 ) {
F_20 ( & V_53 , V_26 ) ;
V_100 = sprintf ( V_101 , L_14 ) ;
goto V_105;
}
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
if ( V_11 == V_98 -> V_103 )
F_42 ( V_11 ) ;
F_20 ( & V_53 , V_26 ) ;
V_100 = sprintf ( V_101 , L_14 ) ;
goto V_105;
}
V_100 = snprintf ( V_101 , 1024 ,
L_15 ,
V_75 , F_50 ( V_11 ) ,
F_1 ( V_12 -> V_28 ) ,
F_1 ( V_12 -> V_31 ) ,
F_1 ( V_12 -> V_38 ) ,
V_12 -> V_44 , V_12 -> V_45 ) ;
F_20 ( & V_53 , V_26 ) ;
V_105:
if ( V_100 > V_89 )
V_100 = V_89 ;
V_52 = F_51 ( V_4 , V_101 , V_100 ) ;
F_39 ( V_101 ) ;
if ( V_52 )
return - V_106 ;
return V_100 ;
}
static T_4 F_52 ( struct V_95 * V_95 , const char T_5 * V_4 ,
T_6 V_89 , T_7 * V_96 )
{
struct V_97 * V_98 = V_95 -> V_99 ;
struct V_107 * V_108 = NULL ;
struct V_10 * V_11 ;
unsigned int V_6 ;
char V_109 [ 64 ] , * V_110 ;
T_6 V_111 = V_89 ;
int V_112 ;
int V_113 ;
if ( V_89 >= sizeof( V_109 ) )
return - V_114 ;
if ( F_53 ( V_109 , V_4 , V_89 ) )
return - V_106 ;
V_110 = V_109 ;
V_109 [ V_89 ] = '\0' ;
if ( strncmp ( V_110 , L_16 , 5 ) == 0 ) {
V_110 += 5 ;
V_111 -= 5 ;
F_54 ( L_17 , V_98 ) ;
if ( ! F_2 ( V_110 , V_111 , & V_6 ) ) {
V_112 = - V_115 ;
goto V_105;
}
if ( V_6 == V_7 ) {
V_112 = - V_115 ;
goto V_105;
}
V_11 = V_98 -> V_103 ;
if ( V_98 -> V_103 == NULL ) {
V_112 = - V_54 ;
goto V_105;
}
F_55 ( V_11 , V_6 ) ;
for ( V_113 = 0 ; V_113 < V_116 ; V_113 ++ ) {
if ( V_98 -> V_117 [ V_113 ] . V_11 == V_11 ) {
if ( V_6 & V_2 )
V_98 -> V_117 [ V_113 ] . V_118 ++ ;
if ( V_6 & V_3 )
V_98 -> V_117 [ V_113 ] . V_119 ++ ;
break;
}
}
V_112 = V_89 ;
goto V_105;
} else if ( strncmp ( V_110 , L_18 , 7 ) == 0 ) {
V_110 += 7 ;
V_111 -= 7 ;
F_54 ( L_19 , V_98 ) ;
if ( strncmp ( V_110 , L_20 , 3 ) == 0 )
V_6 = V_2 | V_3 ;
else {
if ( ! F_2
( V_110 , V_111 , & V_6 ) ) {
V_112 = - V_115 ;
goto V_105;
}
}
V_11 = V_98 -> V_103 ;
if ( V_98 -> V_103 == NULL ) {
V_112 = - V_54 ;
goto V_105;
}
for ( V_113 = 0 ; V_113 < V_116 ; V_113 ++ ) {
if ( V_98 -> V_117 [ V_113 ] . V_11 == V_11 )
V_108 = & V_98 -> V_117 [ V_113 ] ;
}
if ( ! V_108 ) {
V_112 = - V_114 ;
goto V_105;
}
if ( V_6 & V_2 && V_108 -> V_118 == 0 ) {
V_112 = - V_114 ;
goto V_105;
}
if ( V_6 & V_3 && V_108 -> V_119 == 0 ) {
V_112 = - V_114 ;
goto V_105;
}
F_29 ( V_11 , V_6 ) ;
if ( V_6 & V_2 )
V_108 -> V_118 -- ;
if ( V_6 & V_3 )
V_108 -> V_119 -- ;
V_112 = V_89 ;
goto V_105;
} else if ( strncmp ( V_110 , L_21 , 8 ) == 0 ) {
V_110 += 8 ;
V_111 -= 8 ;
F_54 ( L_22 , V_98 ) ;
if ( ! F_2 ( V_110 , V_111 , & V_6 ) ) {
V_112 = - V_115 ;
goto V_105;
}
V_11 = V_98 -> V_103 ;
if ( V_98 -> V_103 == NULL ) {
V_112 = - V_54 ;
goto V_105;
}
if ( F_28 ( V_11 , V_6 ) ) {
for ( V_113 = 0 ; V_113 < V_116 ; V_113 ++ ) {
if ( V_98 -> V_117 [ V_113 ] . V_11 == V_11 ) {
if ( V_6 & V_2 )
V_98 -> V_117 [ V_113 ] . V_118 ++ ;
if ( V_6 & V_3 )
V_98 -> V_117 [ V_113 ] . V_119 ++ ;
break;
}
}
V_112 = V_89 ;
goto V_105;
} else {
V_112 = - V_61 ;
goto V_105;
}
} else if ( strncmp ( V_110 , L_23 , 7 ) == 0 ) {
unsigned int V_90 , V_37 , V_91 ;
struct V_9 * V_12 ;
V_110 += 7 ;
V_111 -= 7 ;
F_54 ( L_24 , V_98 ) ;
if ( ! strncmp ( V_110 , L_25 , 7 ) )
V_11 = F_8 ( F_5 () ) ;
else {
if ( ! F_46 ( V_110 , V_111 ,
& V_90 , & V_37 , & V_91 ) ) {
V_112 = - V_115 ;
goto V_105;
}
V_11 = F_56 ( V_90 , V_37 , V_91 ) ;
if ( ! V_11 ) {
F_54 ( L_26 ,
V_90 , V_37 , F_57 ( V_91 ) ,
F_58 ( V_91 ) ) ;
V_112 = - V_54 ;
goto V_105;
}
F_54 ( L_27 , V_110 ,
V_90 , V_37 , F_57 ( V_91 ) , F_58 ( V_91 ) ,
V_11 ) ;
}
V_12 = F_3 ( V_11 ) ;
F_54 ( L_28 , V_12 ) ;
if ( V_12 == NULL ) {
if ( V_11 ) {
F_13 ( & V_11 -> V_20 , L_29 ) ;
F_7 ( V_11 ) ;
}
V_112 = - V_54 ;
goto V_105;
}
V_98 -> V_103 = V_11 ;
for ( V_113 = 0 ; V_113 < V_116 ; V_113 ++ ) {
if ( V_98 -> V_117 [ V_113 ] . V_11 == V_11 )
break;
if ( V_98 -> V_117 [ V_113 ] . V_11 == NULL ) {
V_98 -> V_117 [ V_113 ] . V_11 = V_11 ;
V_98 -> V_117 [ V_113 ] . V_118 = 0 ;
V_98 -> V_117 [ V_113 ] . V_119 = 0 ;
break;
}
}
if ( V_113 == V_116 ) {
F_13 ( & V_11 -> V_20 , L_30 ,
V_116 ) ;
F_7 ( V_11 ) ;
V_112 = - V_102 ;
goto V_105;
}
V_112 = V_89 ;
F_7 ( V_11 ) ;
goto V_105;
} else if ( strncmp ( V_110 , L_31 , 8 ) == 0 ) {
V_110 += 8 ;
V_111 -= 8 ;
F_54 ( L_32 , V_98 ) ;
if ( ! F_2 ( V_110 , V_111 , & V_6 ) ) {
V_112 = - V_115 ;
goto V_105;
}
V_11 = V_98 -> V_103 ;
if ( V_98 -> V_103 == NULL ) {
V_112 = - V_54 ;
goto V_105;
}
F_44 ( V_11 , V_6 , true ) ;
V_112 = V_89 ;
goto V_105;
}
return - V_115 ;
V_105:
return V_112 ;
}
static unsigned int F_59 ( struct V_95 * V_95 , T_8 * V_51 )
{
F_54 ( L_7 , V_30 ) ;
F_60 ( V_95 , & V_49 , V_51 ) ;
return V_120 ;
}
static int F_61 ( struct V_121 * V_121 , struct V_95 * V_95 )
{
struct V_97 * V_98 ;
unsigned long V_26 ;
F_54 ( L_7 , V_30 ) ;
V_98 = F_33 ( sizeof( * V_98 ) , V_73 ) ;
if ( V_98 == NULL )
return - V_102 ;
F_62 ( & V_98 -> V_122 ) ;
V_95 -> V_99 = V_98 ;
F_19 ( & V_123 , V_26 ) ;
F_38 ( & V_98 -> V_80 , & V_124 ) ;
F_20 ( & V_123 , V_26 ) ;
V_98 -> V_103 = F_5 () ;
V_98 -> V_117 [ 0 ] . V_11 = V_98 -> V_103 ;
V_98 -> V_117 [ 0 ] . V_118 = 0 ;
V_98 -> V_117 [ 0 ] . V_119 = 0 ;
return 0 ;
}
static int F_63 ( struct V_121 * V_121 , struct V_95 * V_95 )
{
struct V_97 * V_98 = V_95 -> V_99 ;
struct V_107 * V_108 ;
unsigned long V_26 ;
int V_113 ;
F_54 ( L_7 , V_30 ) ;
F_19 ( & V_123 , V_26 ) ;
F_41 ( & V_98 -> V_80 ) ;
for ( V_113 = 0 ; V_113 < V_116 ; V_113 ++ ) {
V_108 = & V_98 -> V_117 [ V_113 ] ;
if ( V_108 -> V_11 == NULL )
continue;
F_13 ( & V_108 -> V_11 -> V_20 , L_33 ,
V_108 -> V_118 , V_108 -> V_119 ) ;
while ( V_108 -> V_118 -- )
F_29 ( V_108 -> V_11 , V_2 ) ;
while ( V_108 -> V_119 -- )
F_29 ( V_108 -> V_11 , V_3 ) ;
}
F_20 ( & V_123 , V_26 ) ;
F_39 ( V_98 ) ;
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
}
static void F_11 ( void )
{
struct V_9 * V_12 ;
unsigned long V_26 ;
T_9 V_83 ;
bool V_125 ;
if ( ! V_17 )
return;
F_19 ( & V_53 , V_26 ) ;
F_4 (vgadev, &vga_list, list) {
if ( V_81 > 1 )
V_125 = false ;
else
V_125 = true ;
if ( V_12 -> V_88 ) {
V_83 = V_12 -> V_88 ( V_12 -> V_16 ,
V_125 ) ;
F_43 ( V_12 , V_83 ) ;
}
}
F_20 ( & V_53 , V_26 ) ;
}
static int F_64 ( struct V_126 * V_127 , unsigned long V_128 ,
void * V_129 )
{
struct V_19 * V_20 = V_129 ;
struct V_10 * V_11 = F_65 ( V_20 ) ;
bool V_130 = false ;
F_13 ( V_20 , L_7 , V_30 ) ;
if ( V_128 == V_131 )
V_130 = F_32 ( V_11 ) ;
else if ( V_128 == V_132 )
V_130 = F_40 ( V_11 ) ;
if ( V_130 )
F_11 () ;
return 0 ;
}
static int T_10 F_66 ( void )
{
int V_52 ;
struct V_10 * V_11 ;
struct V_9 * V_12 ;
V_52 = F_67 ( & V_133 ) ;
if ( V_52 < 0 )
F_68 ( L_34 , V_52 ) ;
F_69 ( & V_134 , & V_135 ) ;
V_11 = NULL ;
while ( ( V_11 =
F_70 ( V_136 , V_136 , V_136 ,
V_136 , V_11 ) ) != NULL )
F_32 ( V_11 ) ;
F_4 (vgadev, &vga_list, list) {
struct V_19 * V_20 = & V_12 -> V_11 -> V_20 ;
#if F_71 ( V_137 ) || F_71 ( V_138 )
T_11 V_139 , V_140 , V_141 ;
unsigned long V_26 ;
int V_113 ;
V_141 = V_142 . V_143 + V_142 . V_144 ;
for ( V_113 = 0 ; V_113 < V_145 ; V_113 ++ ) {
V_26 = F_72 ( V_12 -> V_11 , V_113 ) ;
if ( ( V_26 & V_146 ) == 0 )
continue;
V_139 = F_73 ( V_12 -> V_11 , V_113 ) ;
V_140 = F_74 ( V_12 -> V_11 , V_113 ) ;
if ( ! V_139 || ! V_140 )
continue;
if ( V_142 . V_143 < V_139 || V_141 >= V_140 )
continue;
if ( ! F_5 () )
F_37 ( V_20 , L_35 ) ;
else if ( V_12 -> V_11 != F_5 () )
F_37 ( V_20 , L_36 ) ;
F_6 ( V_12 -> V_11 ) ;
}
#endif
if ( V_12 -> V_39 )
F_37 ( V_20 , L_37 ) ;
else
F_37 ( V_20 , L_38 ) ;
}
F_75 ( L_39 ) ;
return V_52 ;
}
