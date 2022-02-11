void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
F_2 ( V_3 > 3 ) ;
V_5 = F_3 ( V_2 , V_6 ) ;
V_5 &= ~ ( 0xff << ( 8 * V_3 ) ) ;
V_5 |= ( V_4 << ( 8 * V_3 ) ) ;
F_4 ( V_2 , V_6 , V_5 ) ;
}
static inline int F_5 ( struct V_1 * V_2 ,
unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_9 ;
int V_10 ;
V_9 = V_11 + F_6 ( V_7 ) ;
while ( 1 ) {
V_10 = F_7 ( V_11 , V_9 ) ;
if ( F_3 ( V_2 , V_12 ) & 2 )
break;
if ( V_10 ) {
F_8 ( V_13 L_1
L_2 ,
V_2 -> V_14 , V_15 ) ;
return - V_16 ;
}
F_9 ( 1 ) ;
}
V_9 = V_11 + F_6 ( V_8 ) ;
while ( 1 ) {
V_10 = F_7 ( V_11 , V_9 ) ;
if ( ! ( F_3 ( V_2 , V_17 ) & V_18 ) )
break;
F_3 ( V_2 , V_12 ) ;
if ( V_10 ) {
F_10 ( ( L_3
L_4 , V_2 -> V_14 , V_15 ) ) ;
return - V_16 ;
}
F_9 ( 1 ) ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_19 ;
V_19 = V_7 ;
while ( 1 ) {
if ( F_3 ( V_2 , V_12 ) & 2 )
break;
if ( ! V_19 -- ) {
F_8 ( V_13 L_1
L_2 ,
V_2 -> V_14 , V_15 ) ;
return - V_16 ;
}
F_12 ( 1 ) ;
}
V_19 = V_8 / 5 ;
while ( 1 ) {
if ( ! ( F_3 ( V_2 , V_17 ) & V_18 ) )
break;
F_3 ( V_2 , V_12 ) ;
if ( ! V_19 -- ) {
F_10 ( ( L_3
L_4 , V_2 -> V_14 , V_15 ) ) ;
return - V_16 ;
}
F_12 ( 5 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , int V_20 )
{
if ( V_20 )
return F_5 ( V_2 , 50000 , 250000 ) ;
else
return F_11 ( V_2 , 50000 , 250000 ) ;
}
static struct V_21 * F_14 ( unsigned char * V_22 , int V_23 )
{
struct V_21 * V_24 ;
struct V_25 * V_26 ;
int V_27 ;
V_24 = F_15 ( V_23 , sizeof( struct V_21 ) , V_28 ) ;
if ( NULL == V_24 )
return NULL ;
F_16 ( V_24 , V_23 ) ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ , V_22 += V_29 ) {
V_26 = F_17 ( V_22 ) ;
if ( NULL == V_26 )
goto V_10;
F_2 ( F_18 ( V_26 ) ) ;
F_19 ( & V_24 [ V_27 ] , V_26 , V_29 , 0 ) ;
}
return V_24 ;
V_10:
F_20 ( V_24 ) ;
return NULL ;
}
void * F_21 ( struct V_30 * V_31 , long V_32 , struct V_33 * V_34 )
{
int V_35 = ( V_32 + V_29 - 1 ) / V_29 ;
void * V_36 = F_22 ( V_32 ) ;
int V_37 = 0 ;
if ( NULL == V_36 )
goto V_38;
if ( ! ( V_34 -> V_39 = F_14 ( V_36 , V_35 ) ) )
goto V_40;
if ( F_23 ( V_31 , V_34 ) )
goto V_41;
V_34 -> V_42 = V_35 ;
V_37 = F_24 ( V_31 , V_34 -> V_39 , V_34 -> V_42 , V_43 ) ;
if ( 0 == V_37 )
goto V_44;
if ( 0 != F_25 ( V_31 , V_34 , V_34 -> V_39 , V_37 ) )
goto V_45;
return V_36 ;
V_45:
F_26 ( V_31 , V_34 -> V_39 , V_34 -> V_42 , V_43 ) ;
V_44:
F_27 ( V_31 , V_34 ) ;
V_41:
F_20 ( V_34 -> V_39 ) ;
V_34 -> V_39 = NULL ;
V_40:
F_28 ( V_36 ) ;
V_38:
return NULL ;
}
void F_29 ( struct V_30 * V_31 , void * V_36 , struct V_33 * V_34 )
{
F_26 ( V_31 , V_34 -> V_39 , V_34 -> V_42 , V_43 ) ;
F_27 ( V_31 , V_34 ) ;
F_20 ( V_34 -> V_39 ) ;
V_34 -> V_39 = NULL ;
F_28 ( V_36 ) ;
}
void F_27 ( struct V_30 * V_31 , struct V_33 * V_34 )
{
if ( NULL == V_34 -> V_46 )
return;
F_30 ( V_31 , V_34 -> V_47 , V_34 -> V_46 , V_34 -> V_48 ) ;
V_34 -> V_46 = NULL ;
}
int F_23 ( struct V_30 * V_31 , struct V_33 * V_34 )
{
T_2 * V_46 ;
T_3 V_49 = 0 ;
V_46 = F_31 ( V_31 , V_29 , & V_49 ) ;
if ( NULL == V_46 ) {
return - V_50 ;
}
V_34 -> V_47 = V_29 ;
V_34 -> V_46 = V_46 ;
V_34 -> V_48 = V_49 ;
return 0 ;
}
int F_25 ( struct V_30 * V_31 , struct V_33 * V_34 ,
struct V_21 * V_51 , int V_52 )
{
T_2 * V_53 , V_54 ;
int V_23 = 0 ;
int V_27 , V_55 ;
F_2 ( 0 == V_52 ) ;
F_2 ( V_51 -> V_56 > V_29 ) ;
V_34 -> V_56 = V_51 -> V_56 ;
V_53 = V_34 -> V_46 ;
for ( V_27 = 0 ; V_27 < V_52 ; V_27 ++ , V_51 ++ ) {
for ( V_55 = 0 ; V_55 * 4096 < V_51 -> V_32 ; V_55 ++ , V_53 ++ ) {
* V_53 = F_32 ( F_33 ( V_51 ) + V_55 * 4096 ) ;
V_23 ++ ;
}
}
V_54 = * ( V_53 - 1 ) ;
for( V_27 = V_23 ; V_27 < 1024 ; V_27 ++ ) {
* V_53 ++ = V_54 ;
}
return 0 ;
}
static T_4 F_34 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_1 V_59 ;
T_1 V_60 ;
V_60 = V_59 = F_3 ( V_2 , V_61 ) ;
if ( 0 == V_59 ) {
return V_62 ;
}
if ( V_2 -> V_63 ) {
if ( V_2 -> V_63 -> V_64 & V_59 ) {
if ( V_2 -> V_63 -> V_65 )
V_2 -> V_63 -> V_65 ( V_2 , & V_59 ) ;
V_59 &= ~ V_2 -> V_63 -> V_64 ;
}
}
if ( 0 != ( V_59 & ( V_66 ) ) ) {
F_35 ( ( L_5 , V_59 ) ) ;
if ( V_2 -> V_67 && V_2 -> V_68 )
V_2 -> V_68 ( V_2 , V_59 ) ;
V_59 &= ~ V_66 ;
}
if ( 0 != ( V_59 & ( V_69 ) ) ) {
if ( V_2 -> V_67 && V_2 -> V_68 )
V_2 -> V_68 ( V_2 , V_59 ) ;
V_59 &= ~ V_69 ;
}
if ( 0 != ( V_59 & ( V_70 | V_71 ) ) ) {
F_36 ( V_2 , V_70 | V_71 ) ;
if ( 0 != V_2 -> V_72 ) {
V_2 -> V_72 = 0 ;
F_37 ( & V_2 -> V_73 ) ;
} else {
T_1 V_74 = F_3 ( V_2 , V_17 ) ;
T_1 V_75 = F_3 ( V_2 , V_76 ) ;
F_8 ( V_77 L_6 ,
V_2 -> V_14 , V_59 , V_74 , V_75 ) ;
}
V_59 &= ~ ( V_70 | V_71 ) ;
}
if( 0 != V_59 ) {
F_38 ( ( L_7 , V_59 ) ) ;
F_38 ( ( L_8 ) ) ;
F_36 ( V_2 , V_59 ) ;
}
F_4 ( V_2 , V_61 , V_60 ) ;
return V_78 ;
}
static int F_39 ( struct V_30 * V_31 , const struct V_79 * V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_80 -> V_83 ;
struct V_84 * V_63 = V_82 -> V_63 ;
struct V_1 * V_2 ;
int V_10 = - V_50 ;
V_2 = F_40 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
F_38 ( ( L_9 ) ) ;
goto V_85;
}
F_41 ( ( L_10 , V_31 ) ) ;
V_10 = F_42 ( V_31 ) ;
if ( V_10 < 0 ) {
F_38 ( ( L_11 ) ) ;
goto V_86;
}
F_43 ( V_31 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_87 = V_31 -> V_87 ;
V_10 = F_44 ( V_31 , 0 , L_12 ) ;
if ( V_10 < 0 )
goto V_88;
V_2 -> V_36 = F_45 ( F_46 ( V_31 , 0 ) ,
F_47 ( V_31 , 0 ) ) ;
if ( ! V_2 -> V_36 ) {
F_38 ( ( L_13 ) ) ;
V_10 = - V_89 ;
goto V_90;
}
F_4 ( V_2 , V_91 , 0 ) ;
F_4 ( V_2 , V_92 , 0x30ff0000 ) ;
F_4 ( V_2 , V_12 , 0xf8000000 ) ;
V_10 = F_48 ( V_31 -> V_57 , F_34 , V_93 | V_94 ,
V_2 -> V_14 , V_2 ) ;
if ( V_10 < 0 ) {
F_38 ( ( L_14 ) ) ;
goto V_95;
}
V_10 = - V_50 ;
V_2 -> V_96 . V_97 = F_31 ( V_31 , V_98 ,
& V_2 -> V_96 . V_99 ) ;
if ( ! V_2 -> V_96 . V_97 )
goto V_100;
memset ( V_2 -> V_96 . V_97 , 0x0 , V_98 ) ;
V_2 -> V_101 . V_97 = F_31 ( V_31 , V_98 ,
& V_2 -> V_101 . V_99 ) ;
if ( ! V_2 -> V_101 . V_97 )
goto V_102;
memset ( V_2 -> V_101 . V_97 , 0x0 , V_98 ) ;
V_2 -> V_103 . V_97 = F_31 ( V_31 , V_98 ,
& V_2 -> V_103 . V_99 ) ;
if ( ! V_2 -> V_103 . V_97 )
goto V_104;
memset ( V_2 -> V_103 . V_97 , 0x0 , V_98 ) ;
sprintf ( V_2 -> V_14 , L_15 , V_105 ) ;
F_49 ( ( L_16 , V_2 -> V_36 , V_2 -> V_87 , V_31 -> V_57 , V_31 -> V_106 , V_31 -> V_107 ) ) ;
V_2 -> V_63 = V_63 ;
F_50 ( & V_2 -> V_108 ) ;
F_51 ( & V_2 -> V_109 ) ;
F_51 ( & V_2 -> V_110 ) ;
F_50 ( & V_2 -> V_111 ) ;
V_2 -> V_112 = V_113 ;
F_52 ( & V_2 -> V_73 ) ;
F_4 ( V_2 , V_114 , 0x1c00101f ) ;
V_10 = - V_89 ;
if ( V_63 -> V_115 && V_63 -> V_115 ( V_2 ) ) {
F_53 ( ( L_17 , V_2 ) ) ;
goto V_116;
}
if ( V_63 -> V_117 ( V_2 , V_82 ) ) {
F_53 ( ( L_18 , V_2 ) ) ;
goto V_116;
}
F_54 ( V_31 , & V_2 -> V_118 ) ;
F_55 ( & V_2 -> V_119 ) ;
F_56 ( & V_2 -> V_119 , & V_120 ) ;
V_105 ++ ;
V_10 = 0 ;
V_85:
return V_10 ;
V_116:
F_30 ( V_31 , V_98 , V_2 -> V_103 . V_97 ,
V_2 -> V_103 . V_99 ) ;
V_104:
F_30 ( V_31 , V_98 , V_2 -> V_101 . V_97 ,
V_2 -> V_101 . V_99 ) ;
V_102:
F_30 ( V_31 , V_98 , V_2 -> V_96 . V_97 ,
V_2 -> V_96 . V_99 ) ;
V_100:
F_57 ( V_31 -> V_57 , ( void * ) V_2 ) ;
V_95:
F_58 ( V_2 -> V_36 ) ;
V_90:
F_59 ( V_31 , 0 ) ;
V_88:
F_60 ( V_31 ) ;
V_86:
F_20 ( V_2 ) ;
goto V_85;
}
static void F_61 ( struct V_30 * V_121 )
{
struct V_122 * V_118 = F_62 ( V_121 ) ;
struct V_1 * V_2 = F_63 ( V_118 ) ;
struct {
void * V_123 ;
T_3 V_48 ;
} V_124 [] = {
{ V_2 -> V_103 . V_97 , V_2 -> V_103 . V_99 } ,
{ V_2 -> V_101 . V_97 , V_2 -> V_101 . V_99 } ,
{ V_2 -> V_96 . V_97 , V_2 -> V_96 . V_99 } ,
{ NULL , 0 }
} , * V_55 ;
F_41 ( ( L_19 , V_2 ) ) ;
V_2 -> V_63 -> V_125 ( V_2 ) ;
F_54 ( V_121 , NULL ) ;
F_4 ( V_2 , V_92 , 0x00ff0000 ) ;
F_4 ( V_2 , V_91 , 0 ) ;
F_57 ( V_121 -> V_57 , V_2 ) ;
for ( V_55 = V_124 ; V_55 -> V_123 ; V_55 ++ )
F_30 ( V_121 , V_98 , V_55 -> V_123 , V_55 -> V_48 ) ;
F_58 ( V_2 -> V_36 ) ;
F_59 ( V_121 , 0 ) ;
F_64 ( & V_2 -> V_119 ) ;
F_60 ( V_121 ) ;
F_20 ( V_2 ) ;
V_105 -- ;
}
int F_65 ( struct V_84 * V_63 )
{
F_41 ( ( L_20 , V_63 ) ) ;
V_63 -> V_126 . V_14 = V_63 -> V_14 ;
V_63 -> V_126 . V_127 = V_63 -> V_128 ;
V_63 -> V_126 . V_115 = F_39 ;
V_63 -> V_126 . remove = F_61 ;
F_8 ( L_21 , V_63 -> V_14 ) ;
return F_66 ( & V_63 -> V_126 ) ;
}
int F_67 ( struct V_84 * V_63 )
{
F_41 ( ( L_20 , V_63 ) ) ;
F_8 ( L_22 , V_63 -> V_14 ) ;
F_68 ( & V_63 -> V_126 ) ;
return 0 ;
}
