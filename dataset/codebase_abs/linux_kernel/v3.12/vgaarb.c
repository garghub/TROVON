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
unsigned int V_19 , V_20 , V_21 ;
struct V_9 * V_22 ;
unsigned int V_23 ;
T_1 V_24 = 0 ;
if ( ( V_18 & V_25 ) &&
( V_12 -> V_26 & V_2 ) )
V_18 |= V_2 ;
if ( ( V_18 & V_27 ) &&
( V_12 -> V_26 & V_3 ) )
V_18 |= V_3 ;
F_13 ( L_5 , V_28 , V_18 ) ;
F_13 ( L_6 , V_28 , V_12 -> V_29 ) ;
V_19 = V_18 & ~ V_12 -> V_29 ;
if ( V_19 == 0 )
goto V_30;
V_20 = V_19 & V_31 ;
if ( V_20 == 0 )
goto V_32;
F_4 (conflict, &vga_list, list) {
unsigned int V_33 = V_20 ;
unsigned int V_34 = 0 ;
if ( V_12 == V_22 )
continue;
if ( ! F_14 ( V_12 -> V_11 , V_22 -> V_11 ) )
continue;
if ( V_12 -> V_11 -> V_35 != V_22 -> V_11 -> V_35 ) {
V_34 = 1 ;
V_33 = V_2 | V_3 ;
}
if ( V_22 -> V_36 & V_33 )
return V_22 ;
F_15 ( V_22 -> V_29 & ~ V_22 -> V_26 ) ;
V_21 = V_33 & V_22 -> V_29 ;
if ( ! V_21 )
continue;
V_24 = 0 ;
V_23 = 0 ;
if ( ! V_22 -> V_37 ) {
F_9 ( V_22 , false ) ;
V_24 |= V_38 ;
if ( V_21 & ( V_3 | V_27 ) )
V_23 |= V_39 ;
if ( V_21 & ( V_2 | V_25 ) )
V_23 |= V_40 ;
}
if ( V_34 )
V_24 |= V_41 ;
F_16 ( V_22 -> V_11 , false , V_23 , V_24 ) ;
V_22 -> V_29 &= ~ V_21 ;
if ( V_21 & V_3 )
V_22 -> V_29 &= ~ V_27 ;
if ( V_21 & V_2 )
V_22 -> V_29 &= ~ V_25 ;
}
V_32:
V_24 = 0 ;
V_23 = 0 ;
if ( ! V_12 -> V_37 ) {
V_24 |= V_38 ;
if ( V_19 & ( V_3 | V_27 ) )
V_23 |= V_39 ;
if ( V_19 & ( V_2 | V_25 ) )
V_23 |= V_40 ;
}
if ( ! ! ( V_19 & V_31 ) )
V_24 |= V_41 ;
F_16 ( V_12 -> V_11 , true , V_23 , V_24 ) ;
if ( ! V_12 -> V_37 ) {
F_9 ( V_12 , true ) ;
}
V_12 -> V_29 |= ( V_19 & V_12 -> V_26 ) ;
V_30:
V_12 -> V_36 |= ( V_18 & V_31 ) ;
if ( V_18 & V_2 )
V_12 -> V_42 ++ ;
if ( V_18 & V_3 )
V_12 -> V_43 ++ ;
if ( V_18 & V_25 )
V_12 -> V_44 ++ ;
if ( V_18 & V_27 )
V_12 -> V_45 ++ ;
return NULL ;
}
static void F_17 ( struct V_9 * V_12 , unsigned int V_18 )
{
unsigned int V_46 = V_12 -> V_36 ;
F_13 ( L_7 , V_28 ) ;
if ( ( V_18 & V_25 ) && V_12 -> V_44 > 0 ) {
V_12 -> V_44 -- ;
if ( V_12 -> V_26 & V_2 )
V_18 |= V_2 ;
}
if ( ( V_18 & V_27 ) && V_12 -> V_45 > 0 ) {
V_12 -> V_45 -- ;
if ( V_12 -> V_26 & V_3 )
V_18 |= V_3 ;
}
if ( ( V_18 & V_2 ) && V_12 -> V_42 > 0 )
V_12 -> V_42 -- ;
if ( ( V_18 & V_3 ) && V_12 -> V_43 > 0 )
V_12 -> V_43 -- ;
if ( V_12 -> V_42 == 0 )
V_12 -> V_36 &= ~ V_2 ;
if ( V_12 -> V_43 == 0 )
V_12 -> V_36 &= ~ V_3 ;
if ( V_46 != V_12 -> V_36 )
F_18 ( & V_47 ) ;
}
int F_19 ( struct V_10 * V_11 , unsigned int V_18 , int V_48 )
{
struct V_9 * V_12 , * V_22 ;
unsigned long V_24 ;
T_2 V_49 ;
int V_50 = 0 ;
F_10 () ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return 0 ;
for (; ; ) {
F_20 ( & V_51 , V_24 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
F_21 ( & V_51 , V_24 ) ;
V_50 = - V_52 ;
break;
}
V_22 = F_12 ( V_12 , V_18 ) ;
F_21 ( & V_51 , V_24 ) ;
if ( V_22 == NULL )
break;
F_22 ( & V_49 , V_53 ) ;
F_23 ( & V_47 , & V_49 ) ;
F_24 ( V_48 ?
V_54 :
V_55 ) ;
if ( F_25 ( V_53 ) ) {
V_50 = - V_56 ;
break;
}
F_26 () ;
F_27 ( & V_47 , & V_49 ) ;
F_24 ( V_57 ) ;
}
return V_50 ;
}
int F_28 ( struct V_10 * V_11 , unsigned int V_18 )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
int V_50 = 0 ;
F_10 () ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return 0 ;
F_20 ( & V_51 , V_24 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
V_50 = - V_52 ;
goto V_58;
}
if ( F_12 ( V_12 , V_18 ) )
V_50 = - V_59 ;
V_58:
F_21 ( & V_51 , V_24 ) ;
return V_50 ;
}
void F_29 ( struct V_10 * V_11 , unsigned int V_18 )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
if ( V_11 == NULL )
V_11 = F_5 () ;
if ( V_11 == NULL )
return;
F_20 ( & V_51 , V_24 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL )
goto V_58;
F_17 ( V_12 , V_18 ) ;
V_58:
F_21 ( & V_51 , V_24 ) ;
}
static void F_30 ( struct V_9 * V_12 )
{
struct V_9 * V_60 ;
struct V_61 * V_62 , * V_35 ;
struct V_10 * V_63 , * V_64 ;
V_12 -> V_37 = true ;
if ( F_31 ( & V_65 ) )
return;
V_62 = V_12 -> V_11 -> V_35 ;
while ( V_62 ) {
V_63 = V_62 -> V_66 ;
F_4 (same_bridge_vgadev, &vga_list, list) {
V_35 = V_60 -> V_11 -> V_35 ;
V_64 = V_35 -> V_66 ;
if ( V_63 == V_64 ) {
V_60 -> V_37 = false ;
}
while ( V_35 ) {
V_64 = V_35 -> V_66 ;
if ( V_64 ) {
if ( V_64 == V_12 -> V_11 -> V_35 -> V_66 )
V_12 -> V_37 = false ;
}
V_35 = V_35 -> V_67 ;
}
}
V_62 = V_62 -> V_67 ;
}
}
static bool F_32 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
struct V_61 * V_35 ;
struct V_10 * V_64 ;
T_3 V_68 ;
if ( ( V_11 -> V_69 >> 8 ) != V_70 )
return false ;
V_12 = F_33 ( sizeof( struct V_9 ) , V_71 ) ;
if ( V_12 == NULL ) {
F_34 ( L_8 ) ;
return false ;
}
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
F_20 ( & V_51 , V_24 ) ;
if ( F_3 ( V_11 ) != NULL ) {
F_35 ( 1 ) ;
goto V_72;
}
V_12 -> V_11 = V_11 ;
V_12 -> V_26 = V_2 | V_3 |
V_25 | V_27 ;
V_73 ++ ;
F_36 ( V_11 , V_74 , & V_68 ) ;
if ( V_68 & V_40 )
V_12 -> V_29 |= V_2 ;
if ( V_68 & V_39 )
V_12 -> V_29 |= V_3 ;
V_35 = V_11 -> V_35 ;
while ( V_35 ) {
V_64 = V_35 -> V_66 ;
if ( V_64 ) {
T_3 V_75 ;
F_36 ( V_64 , V_76 ,
& V_75 ) ;
if ( ! ( V_75 & V_77 ) ) {
V_12 -> V_29 = 0 ;
break;
}
}
V_35 = V_35 -> V_67 ;
}
#ifndef F_37
if ( V_13 == NULL &&
( ( V_12 -> V_29 & V_31 ) == V_31 ) )
F_6 ( V_11 ) ;
#endif
F_30 ( V_12 ) ;
F_38 ( & V_12 -> V_78 , & V_65 ) ;
V_79 ++ ;
F_39 ( L_9 ,
F_40 ( V_11 ) ,
F_1 ( V_12 -> V_26 ) ,
F_1 ( V_12 -> V_29 ) ,
F_1 ( V_12 -> V_36 ) ) ;
F_21 ( & V_51 , V_24 ) ;
return true ;
V_72:
F_21 ( & V_51 , V_24 ) ;
F_41 ( V_12 ) ;
return false ;
}
static bool F_42 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
bool V_80 = true ;
F_20 ( & V_51 , V_24 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
V_80 = false ;
goto V_58;
}
#ifndef F_37
if ( V_13 == V_11 )
F_6 ( NULL ) ;
#endif
if ( V_12 -> V_26 & ( V_2 | V_3 ) )
V_73 -- ;
F_43 ( & V_12 -> V_78 ) ;
V_79 -- ;
F_44 ( V_11 ) ;
F_18 ( & V_47 ) ;
V_58:
F_21 ( & V_51 , V_24 ) ;
F_41 ( V_12 ) ;
return V_80 ;
}
static inline void F_45 ( struct V_9 * V_12 ,
int V_81 )
{
int V_82 , V_83 , V_84 ;
V_82 = V_12 -> V_26 ;
V_83 = ~ V_81 & V_82 ;
V_84 = V_12 -> V_36 & V_83 ;
V_12 -> V_29 &= ~ V_83 ;
V_12 -> V_26 = V_81 ;
F_39 ( L_10 ,
F_40 ( V_12 -> V_11 ) ,
F_1 ( V_82 ) ,
F_1 ( V_12 -> V_26 ) ,
F_1 ( V_12 -> V_29 ) ) ;
if ( V_84 ) {
if ( V_84 & V_2 )
V_12 -> V_42 = 0 ;
if ( V_84 & V_3 )
V_12 -> V_43 = 0 ;
F_17 ( V_12 , V_84 ) ;
}
if ( V_82 & V_31 &&
! ( V_81 & V_31 ) )
V_73 -- ;
if ( ! ( V_82 & V_31 ) &&
V_81 & V_31 )
V_73 ++ ;
F_13 ( L_11 , V_73 ) ;
}
static void F_46 ( struct V_10 * V_11 , unsigned int V_26 , bool V_85 )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
V_26 &= V_31 ;
F_20 ( & V_51 , V_24 ) ;
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL )
goto V_58;
if ( V_85 && V_12 -> V_86 )
goto V_58;
F_45 ( V_12 , V_26 ) ;
V_58:
F_21 ( & V_51 , V_24 ) ;
}
void F_47 ( struct V_10 * V_11 , unsigned int V_26 )
{
F_46 ( V_11 , V_26 , false ) ;
}
static int F_48 ( char * V_4 , int V_87 , unsigned int * V_88 ,
unsigned int * V_35 , unsigned int * V_89 )
{
int V_90 ;
unsigned int V_91 , V_92 ;
V_90 = sscanf ( V_4 , L_12 , V_88 , V_35 , & V_91 , & V_92 ) ;
if ( V_90 != 4 )
return 0 ;
* V_89 = F_49 ( V_91 , V_92 ) ;
return 1 ;
}
static T_4 F_50 ( struct V_93 * V_93 , char T_5 * V_4 ,
T_6 V_87 , T_7 * V_94 )
{
struct V_95 * V_96 = V_93 -> V_97 ;
struct V_9 * V_12 ;
struct V_10 * V_11 ;
unsigned long V_24 ;
T_6 V_98 ;
int V_50 ;
char * V_99 ;
V_99 = F_33 ( 1024 , V_71 ) ;
if ( V_99 == NULL )
return - V_100 ;
F_20 ( & V_51 , V_24 ) ;
V_11 = V_96 -> V_101 ;
if ( V_11 == NULL || V_11 == V_102 ) {
F_21 ( & V_51 , V_24 ) ;
V_98 = sprintf ( V_99 , L_13 ) ;
goto V_103;
}
V_12 = F_3 ( V_11 ) ;
if ( V_12 == NULL ) {
if ( V_11 == V_96 -> V_101 )
F_44 ( V_11 ) ;
F_21 ( & V_51 , V_24 ) ;
V_98 = sprintf ( V_99 , L_13 ) ;
goto V_103;
}
V_98 = snprintf ( V_99 , 1024 ,
L_14 ,
V_73 , F_40 ( V_11 ) ,
F_1 ( V_12 -> V_26 ) ,
F_1 ( V_12 -> V_29 ) ,
F_1 ( V_12 -> V_36 ) ,
V_12 -> V_42 , V_12 -> V_43 ) ;
F_21 ( & V_51 , V_24 ) ;
V_103:
if ( V_98 > V_87 )
V_98 = V_87 ;
V_50 = F_51 ( V_4 , V_99 , V_98 ) ;
F_41 ( V_99 ) ;
if ( V_50 )
return - V_104 ;
return V_98 ;
}
static T_4 F_52 ( struct V_93 * V_93 , const char T_5 * V_4 ,
T_6 V_87 , T_7 * V_94 )
{
struct V_95 * V_96 = V_93 -> V_97 ;
struct V_105 * V_106 = NULL ;
struct V_10 * V_11 ;
unsigned int V_6 ;
char * V_107 , * V_108 ;
T_6 V_109 = V_87 ;
int V_110 ;
int V_111 ;
V_107 = F_33 ( V_87 + 1 , V_71 ) ;
if ( ! V_107 )
return - V_100 ;
if ( F_53 ( V_107 , V_4 , V_87 ) ) {
F_41 ( V_107 ) ;
return - V_104 ;
}
V_108 = V_107 ;
V_107 [ V_87 ] = '\0' ;
if ( strncmp ( V_108 , L_15 , 5 ) == 0 ) {
V_108 += 5 ;
V_109 -= 5 ;
F_13 ( L_16 , V_96 ) ;
if ( ! F_2 ( V_108 , V_109 , & V_6 ) ) {
V_110 = - V_112 ;
goto V_103;
}
if ( V_6 == V_7 ) {
V_110 = - V_112 ;
goto V_103;
}
V_11 = V_96 -> V_101 ;
if ( V_96 -> V_101 == NULL ) {
V_110 = - V_52 ;
goto V_103;
}
F_54 ( V_11 , V_6 ) ;
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
if ( V_96 -> V_114 [ V_111 ] . V_11 == V_11 ) {
if ( V_6 & V_2 )
V_96 -> V_114 [ V_111 ] . V_115 ++ ;
if ( V_6 & V_3 )
V_96 -> V_114 [ V_111 ] . V_116 ++ ;
break;
}
}
V_110 = V_87 ;
goto V_103;
} else if ( strncmp ( V_108 , L_17 , 7 ) == 0 ) {
V_108 += 7 ;
V_109 -= 7 ;
F_13 ( L_18 , V_96 ) ;
if ( strncmp ( V_108 , L_19 , 3 ) == 0 )
V_6 = V_2 | V_3 ;
else {
if ( ! F_2
( V_108 , V_109 , & V_6 ) ) {
V_110 = - V_112 ;
goto V_103;
}
}
V_11 = V_96 -> V_101 ;
if ( V_96 -> V_101 == NULL ) {
V_110 = - V_52 ;
goto V_103;
}
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
if ( V_96 -> V_114 [ V_111 ] . V_11 == V_11 )
V_106 = & V_96 -> V_114 [ V_111 ] ;
}
if ( ! V_106 ) {
V_110 = - V_117 ;
goto V_103;
}
if ( V_6 & V_2 && V_106 -> V_115 == 0 ) {
V_110 = - V_117 ;
goto V_103;
}
if ( V_6 & V_3 && V_106 -> V_116 == 0 ) {
V_110 = - V_117 ;
goto V_103;
}
F_29 ( V_11 , V_6 ) ;
if ( V_6 & V_2 )
V_106 -> V_115 -- ;
if ( V_6 & V_3 )
V_106 -> V_116 -- ;
V_110 = V_87 ;
goto V_103;
} else if ( strncmp ( V_108 , L_20 , 8 ) == 0 ) {
V_108 += 8 ;
V_109 -= 8 ;
F_13 ( L_21 , V_96 ) ;
if ( ! F_2 ( V_108 , V_109 , & V_6 ) ) {
V_110 = - V_112 ;
goto V_103;
}
V_11 = V_96 -> V_101 ;
if ( V_96 -> V_101 == NULL ) {
V_110 = - V_52 ;
goto V_103;
}
if ( F_28 ( V_11 , V_6 ) ) {
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
if ( V_96 -> V_114 [ V_111 ] . V_11 == V_11 ) {
if ( V_6 & V_2 )
V_96 -> V_114 [ V_111 ] . V_115 ++ ;
if ( V_6 & V_3 )
V_96 -> V_114 [ V_111 ] . V_116 ++ ;
break;
}
}
V_110 = V_87 ;
goto V_103;
} else {
V_110 = - V_59 ;
goto V_103;
}
} else if ( strncmp ( V_108 , L_22 , 7 ) == 0 ) {
unsigned int V_88 , V_35 , V_89 ;
struct V_9 * V_12 ;
V_108 += 7 ;
V_109 -= 7 ;
F_13 ( L_23 , V_96 ) ;
if ( ! strncmp ( V_108 , L_24 , 7 ) )
V_11 = F_8 ( F_5 () ) ;
else {
if ( ! F_48 ( V_108 , V_109 ,
& V_88 , & V_35 , & V_89 ) ) {
V_110 = - V_112 ;
goto V_103;
}
F_13 ( L_25 , V_108 ,
V_88 , V_35 , F_55 ( V_89 ) , F_56 ( V_89 ) ) ;
V_11 = F_57 ( V_88 , V_35 , V_89 ) ;
F_13 ( L_26 , V_11 ) ;
if ( ! V_11 ) {
F_34 ( L_27 ,
V_88 , V_35 , V_89 ) ;
V_110 = - V_52 ;
goto V_103;
}
}
V_12 = F_3 ( V_11 ) ;
F_13 ( L_28 , V_12 ) ;
if ( V_12 == NULL ) {
F_34 ( L_29 ) ;
F_7 ( V_11 ) ;
V_110 = - V_52 ;
goto V_103;
}
V_96 -> V_101 = V_11 ;
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
if ( V_96 -> V_114 [ V_111 ] . V_11 == V_11 )
break;
if ( V_96 -> V_114 [ V_111 ] . V_11 == NULL ) {
V_96 -> V_114 [ V_111 ] . V_11 = V_11 ;
V_96 -> V_114 [ V_111 ] . V_115 = 0 ;
V_96 -> V_114 [ V_111 ] . V_116 = 0 ;
break;
}
}
if ( V_111 == V_113 ) {
F_34 ( L_30 ,
V_113 ) ;
F_7 ( V_11 ) ;
V_110 = - V_100 ;
goto V_103;
}
V_110 = V_87 ;
F_7 ( V_11 ) ;
goto V_103;
} else if ( strncmp ( V_108 , L_31 , 8 ) == 0 ) {
V_108 += 8 ;
V_109 -= 8 ;
F_13 ( L_32 , V_96 ) ;
if ( ! F_2 ( V_108 , V_109 , & V_6 ) ) {
V_110 = - V_112 ;
goto V_103;
}
V_11 = V_96 -> V_101 ;
if ( V_96 -> V_101 == NULL ) {
V_110 = - V_52 ;
goto V_103;
}
F_46 ( V_11 , V_6 , true ) ;
V_110 = V_87 ;
goto V_103;
}
F_41 ( V_107 ) ;
return - V_112 ;
V_103:
F_41 ( V_107 ) ;
return V_110 ;
}
static unsigned int F_58 ( struct V_93 * V_93 , T_8 * V_49 )
{
struct V_95 * V_96 = V_93 -> V_97 ;
F_13 ( L_7 , V_28 ) ;
if ( V_96 == NULL )
return - V_52 ;
F_59 ( V_93 , & V_47 , V_49 ) ;
return V_118 ;
}
static int F_60 ( struct V_119 * V_119 , struct V_93 * V_93 )
{
struct V_95 * V_96 ;
unsigned long V_24 ;
F_13 ( L_7 , V_28 ) ;
V_96 = F_61 ( sizeof( * V_96 ) , V_71 ) ;
if ( V_96 == NULL )
return - V_100 ;
F_62 ( & V_96 -> V_120 ) ;
V_93 -> V_97 = V_96 ;
F_20 ( & V_121 , V_24 ) ;
F_38 ( & V_96 -> V_78 , & V_122 ) ;
F_21 ( & V_121 , V_24 ) ;
V_96 -> V_101 = F_5 () ;
V_96 -> V_114 [ 0 ] . V_11 = V_96 -> V_101 ;
V_96 -> V_114 [ 0 ] . V_115 = 0 ;
V_96 -> V_114 [ 0 ] . V_116 = 0 ;
return 0 ;
}
static int F_63 ( struct V_119 * V_119 , struct V_93 * V_93 )
{
struct V_95 * V_96 = V_93 -> V_97 ;
struct V_105 * V_106 ;
unsigned long V_24 ;
int V_111 ;
F_13 ( L_7 , V_28 ) ;
if ( V_96 == NULL )
return - V_52 ;
F_20 ( & V_121 , V_24 ) ;
F_43 ( & V_96 -> V_78 ) ;
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
V_106 = & V_96 -> V_114 [ V_111 ] ;
if ( V_106 -> V_11 == NULL )
continue;
F_13 ( L_33 ,
V_106 -> V_115 , V_106 -> V_116 ) ;
while ( V_106 -> V_115 -- )
F_29 ( V_106 -> V_11 , V_2 ) ;
while ( V_106 -> V_116 -- )
F_29 ( V_106 -> V_11 , V_3 ) ;
}
F_21 ( & V_121 , V_24 ) ;
F_41 ( V_96 ) ;
return 0 ;
}
static void F_44 ( struct V_10 * V_11 )
{
}
static void F_11 ( void )
{
struct V_9 * V_12 ;
unsigned long V_24 ;
T_9 V_81 ;
bool V_123 ;
if ( ! V_17 )
return;
F_20 ( & V_51 , V_24 ) ;
F_4 (vgadev, &vga_list, list) {
if ( V_79 > 1 )
V_123 = false ;
else
V_123 = true ;
if ( V_12 -> V_86 ) {
V_81 = V_12 -> V_86 ( V_12 -> V_16 , V_123 ) ;
F_45 ( V_12 , V_81 ) ;
}
}
F_21 ( & V_51 , V_24 ) ;
}
static int F_64 ( struct V_124 * V_125 , unsigned long V_126 ,
void * V_127 )
{
struct V_128 * V_129 = V_127 ;
struct V_10 * V_11 = F_65 ( V_129 ) ;
bool V_130 = false ;
F_13 ( L_7 , V_28 ) ;
if ( V_126 == V_131 )
V_130 = F_32 ( V_11 ) ;
else if ( V_126 == V_132 )
V_130 = F_42 ( V_11 ) ;
if ( V_130 )
F_11 () ;
return 0 ;
}
static int T_10 F_66 ( void )
{
int V_50 ;
struct V_10 * V_11 ;
struct V_9 * V_12 ;
V_50 = F_67 ( & V_133 ) ;
if ( V_50 < 0 )
F_34 ( L_34 , V_50 ) ;
F_68 ( & V_134 , & V_135 ) ;
V_11 = NULL ;
while ( ( V_11 =
F_69 ( V_136 , V_136 , V_136 ,
V_136 , V_11 ) ) != NULL )
F_32 ( V_11 ) ;
F_39 ( L_35 ) ;
F_4 (vgadev, &vga_list, list) {
if ( V_12 -> V_37 )
F_39 ( L_36 , F_40 ( V_12 -> V_11 ) ) ;
else
F_39 ( L_37 , F_40 ( V_12 -> V_11 ) ) ;
}
return V_50 ;
}
