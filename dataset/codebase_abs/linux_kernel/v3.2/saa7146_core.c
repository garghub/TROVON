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
F_8 ( L_1 ,
V_2 -> V_13 , V_14 ) ;
return - V_15 ;
}
F_9 ( 1 ) ;
}
V_9 = V_11 + F_6 ( V_8 ) ;
while ( 1 ) {
V_10 = F_7 ( V_11 , V_9 ) ;
if ( ! ( F_3 ( V_2 , V_16 ) & V_17 ) )
break;
F_3 ( V_2 , V_12 ) ;
if ( V_10 ) {
F_10 ( L_2 ,
V_2 -> V_13 , V_14 ) ;
return - V_15 ;
}
F_9 ( 1 ) ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_18 ;
V_18 = V_7 ;
while ( 1 ) {
if ( F_3 ( V_2 , V_12 ) & 2 )
break;
if ( ! V_18 -- ) {
F_8 ( L_1 ,
V_2 -> V_13 , V_14 ) ;
return - V_15 ;
}
F_12 ( 1 ) ;
}
V_18 = V_8 / 5 ;
while ( 1 ) {
if ( ! ( F_3 ( V_2 , V_16 ) & V_17 ) )
break;
F_3 ( V_2 , V_12 ) ;
if ( ! V_18 -- ) {
F_10 ( L_2 ,
V_2 -> V_13 , V_14 ) ;
return - V_15 ;
}
F_12 ( 5 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , int V_19 )
{
if ( V_19 )
return F_5 ( V_2 , 50000 , 250000 ) ;
else
return F_11 ( V_2 , 50000 , 250000 ) ;
}
static struct V_20 * F_14 ( unsigned char * V_21 , int V_22 )
{
struct V_20 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
V_23 = F_15 ( V_22 , sizeof( struct V_20 ) , V_27 ) ;
if ( NULL == V_23 )
return NULL ;
F_16 ( V_23 , V_22 ) ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ , V_21 += V_28 ) {
V_25 = F_17 ( V_21 ) ;
if ( NULL == V_25 )
goto V_10;
F_2 ( F_18 ( V_25 ) ) ;
F_19 ( & V_23 [ V_26 ] , V_25 , V_28 , 0 ) ;
}
return V_23 ;
V_10:
F_20 ( V_23 ) ;
return NULL ;
}
void * F_21 ( struct V_29 * V_30 , long V_31 , struct V_32 * V_33 )
{
int V_34 = ( V_31 + V_28 - 1 ) / V_28 ;
void * V_35 = F_22 ( V_31 ) ;
int V_36 = 0 ;
if ( NULL == V_35 )
goto V_37;
if ( ! ( V_33 -> V_38 = F_14 ( V_35 , V_34 ) ) )
goto V_39;
if ( F_23 ( V_30 , V_33 ) )
goto V_40;
V_33 -> V_41 = V_34 ;
V_36 = F_24 ( V_30 , V_33 -> V_38 , V_33 -> V_41 , V_42 ) ;
if ( 0 == V_36 )
goto V_43;
if ( 0 != F_25 ( V_30 , V_33 , V_33 -> V_38 , V_36 ) )
goto V_44;
return V_35 ;
V_44:
F_26 ( V_30 , V_33 -> V_38 , V_33 -> V_41 , V_42 ) ;
V_43:
F_27 ( V_30 , V_33 ) ;
V_40:
F_20 ( V_33 -> V_38 ) ;
V_33 -> V_38 = NULL ;
V_39:
F_28 ( V_35 ) ;
V_37:
return NULL ;
}
void F_29 ( struct V_29 * V_30 , void * V_35 , struct V_32 * V_33 )
{
F_26 ( V_30 , V_33 -> V_38 , V_33 -> V_41 , V_42 ) ;
F_27 ( V_30 , V_33 ) ;
F_20 ( V_33 -> V_38 ) ;
V_33 -> V_38 = NULL ;
F_28 ( V_35 ) ;
}
void F_27 ( struct V_29 * V_30 , struct V_32 * V_33 )
{
if ( NULL == V_33 -> V_45 )
return;
F_30 ( V_30 , V_33 -> V_46 , V_33 -> V_45 , V_33 -> V_47 ) ;
V_33 -> V_45 = NULL ;
}
int F_23 ( struct V_29 * V_30 , struct V_32 * V_33 )
{
T_2 * V_45 ;
T_3 V_48 = 0 ;
V_45 = F_31 ( V_30 , V_28 , & V_48 ) ;
if ( NULL == V_45 ) {
return - V_49 ;
}
V_33 -> V_46 = V_28 ;
V_33 -> V_45 = V_45 ;
V_33 -> V_47 = V_48 ;
return 0 ;
}
int F_25 ( struct V_29 * V_30 , struct V_32 * V_33 ,
struct V_20 * V_50 , int V_51 )
{
T_2 * V_52 , V_53 ;
int V_22 = 0 ;
int V_26 , V_54 ;
F_2 ( 0 == V_51 ) ;
F_2 ( V_50 -> V_55 > V_28 ) ;
V_33 -> V_55 = V_50 -> V_55 ;
V_52 = V_33 -> V_45 ;
for ( V_26 = 0 ; V_26 < V_51 ; V_26 ++ , V_50 ++ ) {
for ( V_54 = 0 ; V_54 * 4096 < V_50 -> V_31 ; V_54 ++ , V_52 ++ ) {
* V_52 = F_32 ( F_33 ( V_50 ) + V_54 * 4096 ) ;
V_22 ++ ;
}
}
V_53 = * ( V_52 - 1 ) ;
for( V_26 = V_22 ; V_26 < 1024 ; V_26 ++ ) {
* V_52 ++ = V_53 ;
}
return 0 ;
}
static T_4 F_34 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
T_1 V_58 ;
T_1 V_59 ;
V_59 = V_58 = F_3 ( V_2 , V_60 ) ;
if ( 0 == V_58 ) {
return V_61 ;
}
if ( V_2 -> V_62 ) {
if ( V_2 -> V_62 -> V_63 & V_58 ) {
if ( V_2 -> V_62 -> V_64 )
V_2 -> V_62 -> V_64 ( V_2 , & V_58 ) ;
V_58 &= ~ V_2 -> V_62 -> V_63 ;
}
}
if ( 0 != ( V_58 & ( V_65 ) ) ) {
F_35 ( L_3 , V_58 ) ;
if ( V_2 -> V_66 && V_2 -> V_67 )
V_2 -> V_67 ( V_2 , V_58 ) ;
V_58 &= ~ V_65 ;
}
if ( 0 != ( V_58 & ( V_68 ) ) ) {
if ( V_2 -> V_66 && V_2 -> V_67 )
V_2 -> V_67 ( V_2 , V_58 ) ;
V_58 &= ~ V_68 ;
}
if ( 0 != ( V_58 & ( V_69 | V_70 ) ) ) {
F_36 ( V_2 , V_69 | V_70 ) ;
if ( 0 != V_2 -> V_71 ) {
V_2 -> V_71 = 0 ;
F_37 ( & V_2 -> V_72 ) ;
} else {
T_1 V_73 = F_3 ( V_2 , V_16 ) ;
T_1 V_74 = F_3 ( V_2 , V_75 ) ;
F_38 ( L_4 ,
V_2 -> V_13 , V_58 , V_73 , V_74 ) ;
}
V_58 &= ~ ( V_69 | V_70 ) ;
}
if( 0 != V_58 ) {
F_39 ( L_5 ,
V_58 ) ;
F_39 ( L_6 ) ;
F_36 ( V_2 , V_58 ) ;
}
F_4 ( V_2 , V_60 , V_59 ) ;
return V_76 ;
}
static int F_40 ( struct V_29 * V_30 , const struct V_77 * V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
struct V_82 * V_62 = V_80 -> V_62 ;
struct V_1 * V_2 ;
int V_10 = - V_49 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
F_39 ( L_7 ) ;
goto V_83;
}
F_42 ( L_8 , V_30 ) ;
V_10 = F_43 ( V_30 ) ;
if ( V_10 < 0 ) {
F_39 ( L_9 ) ;
goto V_84;
}
F_44 ( V_30 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_85 = V_30 -> V_85 ;
V_10 = F_45 ( V_30 , 0 , L_10 ) ;
if ( V_10 < 0 )
goto V_86;
V_2 -> V_35 = F_46 ( F_47 ( V_30 , 0 ) ,
F_48 ( V_30 , 0 ) ) ;
if ( ! V_2 -> V_35 ) {
F_39 ( L_11 ) ;
V_10 = - V_87 ;
goto V_88;
}
F_4 ( V_2 , V_89 , 0 ) ;
F_4 ( V_2 , V_90 , 0x30ff0000 ) ;
F_4 ( V_2 , V_12 , 0xf8000000 ) ;
V_10 = F_49 ( V_30 -> V_56 , F_34 , V_91 | V_92 ,
V_2 -> V_13 , V_2 ) ;
if ( V_10 < 0 ) {
F_39 ( L_12 ) ;
goto V_93;
}
V_10 = - V_49 ;
V_2 -> V_94 . V_95 = F_31 ( V_30 , V_96 ,
& V_2 -> V_94 . V_97 ) ;
if ( ! V_2 -> V_94 . V_95 )
goto V_98;
memset ( V_2 -> V_94 . V_95 , 0x0 , V_96 ) ;
V_2 -> V_99 . V_95 = F_31 ( V_30 , V_96 ,
& V_2 -> V_99 . V_97 ) ;
if ( ! V_2 -> V_99 . V_95 )
goto V_100;
memset ( V_2 -> V_99 . V_95 , 0x0 , V_96 ) ;
V_2 -> V_101 . V_95 = F_31 ( V_30 , V_96 ,
& V_2 -> V_101 . V_97 ) ;
if ( ! V_2 -> V_101 . V_95 )
goto V_102;
memset ( V_2 -> V_101 . V_95 , 0x0 , V_96 ) ;
sprintf ( V_2 -> V_13 , L_13 , V_103 ) ;
F_50 ( L_14 ,
V_2 -> V_35 , V_2 -> V_85 , V_30 -> V_56 ,
V_30 -> V_104 , V_30 -> V_105 ) ;
V_2 -> V_62 = V_62 ;
F_51 ( & V_2 -> V_106 ) ;
F_52 ( & V_2 -> V_107 ) ;
F_52 ( & V_2 -> V_108 ) ;
F_51 ( & V_2 -> V_109 ) ;
V_2 -> V_110 = V_111 ;
F_53 ( & V_2 -> V_72 ) ;
F_4 ( V_2 , V_112 , 0x1c00101f ) ;
V_10 = - V_87 ;
if ( V_62 -> V_113 && V_62 -> V_113 ( V_2 ) ) {
F_54 ( L_15 , V_2 ) ;
goto V_114;
}
if ( V_62 -> V_115 ( V_2 , V_80 ) ) {
F_54 ( L_16 , V_2 ) ;
goto V_114;
}
F_55 ( V_30 , & V_2 -> V_116 ) ;
F_56 ( & V_2 -> V_117 ) ;
F_57 ( & V_2 -> V_117 , & V_118 ) ;
V_103 ++ ;
V_10 = 0 ;
V_83:
return V_10 ;
V_114:
F_30 ( V_30 , V_96 , V_2 -> V_101 . V_95 ,
V_2 -> V_101 . V_97 ) ;
V_102:
F_30 ( V_30 , V_96 , V_2 -> V_99 . V_95 ,
V_2 -> V_99 . V_97 ) ;
V_100:
F_30 ( V_30 , V_96 , V_2 -> V_94 . V_95 ,
V_2 -> V_94 . V_97 ) ;
V_98:
F_58 ( V_30 -> V_56 , ( void * ) V_2 ) ;
V_93:
F_59 ( V_2 -> V_35 ) ;
V_88:
F_60 ( V_30 , 0 ) ;
V_86:
F_61 ( V_30 ) ;
V_84:
F_20 ( V_2 ) ;
goto V_83;
}
static void F_62 ( struct V_29 * V_119 )
{
struct V_120 * V_116 = F_63 ( V_119 ) ;
struct V_1 * V_2 = F_64 ( V_116 ) ;
struct {
void * V_121 ;
T_3 V_47 ;
} V_122 [] = {
{ V_2 -> V_101 . V_95 , V_2 -> V_101 . V_97 } ,
{ V_2 -> V_99 . V_95 , V_2 -> V_99 . V_97 } ,
{ V_2 -> V_94 . V_95 , V_2 -> V_94 . V_97 } ,
{ NULL , 0 }
} , * V_54 ;
F_42 ( L_17 , V_2 ) ;
V_2 -> V_62 -> V_123 ( V_2 ) ;
F_55 ( V_119 , NULL ) ;
F_4 ( V_2 , V_90 , 0x00ff0000 ) ;
F_4 ( V_2 , V_89 , 0 ) ;
F_58 ( V_119 -> V_56 , V_2 ) ;
for ( V_54 = V_122 ; V_54 -> V_121 ; V_54 ++ )
F_30 ( V_119 , V_96 , V_54 -> V_121 , V_54 -> V_47 ) ;
F_59 ( V_2 -> V_35 ) ;
F_60 ( V_119 , 0 ) ;
F_65 ( & V_2 -> V_117 ) ;
F_61 ( V_119 ) ;
F_20 ( V_2 ) ;
V_103 -- ;
}
int F_66 ( struct V_82 * V_62 )
{
F_42 ( L_18 , V_62 ) ;
V_62 -> V_124 . V_13 = V_62 -> V_13 ;
V_62 -> V_124 . V_125 = V_62 -> V_126 ;
V_62 -> V_124 . V_113 = F_40 ;
V_62 -> V_124 . remove = F_62 ;
F_50 ( L_19 , V_62 -> V_13 ) ;
return F_67 ( & V_62 -> V_124 ) ;
}
int F_68 ( struct V_82 * V_62 )
{
F_42 ( L_18 , V_62 ) ;
F_50 ( L_20 , V_62 -> V_13 ) ;
F_69 ( & V_62 -> V_124 ) ;
return 0 ;
}
