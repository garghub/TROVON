int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
const char * V_4 ;
const struct V_5 * V_6 ;
unsigned V_7 , V_8 , V_9 , V_10 ;
int V_11 , V_12 ;
F_2 ( & V_2 -> V_13 . V_14 , V_15 ) ;
switch ( V_2 -> V_16 ) {
#ifdef F_3
case V_17 :
V_4 = V_18 ;
break;
case V_19 :
V_4 = V_20 ;
break;
case V_21 :
V_4 = V_22 ;
break;
case V_23 :
V_4 = V_24 ;
break;
case V_25 :
V_4 = V_26 ;
break;
#endif
case V_27 :
V_4 = V_28 ;
break;
case V_29 :
V_4 = V_30 ;
break;
case V_31 :
V_4 = V_32 ;
break;
case V_33 :
V_4 = V_34 ;
break;
default:
return - V_35 ;
}
V_12 = F_4 ( & V_2 -> V_13 . V_36 , V_4 , V_2 -> V_37 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_37 , L_1 ,
V_4 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 -> V_13 . V_36 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_37 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_13 . V_36 ) ;
V_2 -> V_13 . V_36 = NULL ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_36 -> V_38 ;
V_7 = F_8 ( V_6 -> V_7 ) ;
V_8 = ( V_7 >> 20 ) & 0xfff ;
V_9 = ( V_7 >> 8 ) & 0xfff ;
V_10 = V_7 & 0xff ;
F_9 ( L_3 ,
V_8 , V_9 , V_10 ) ;
V_2 -> V_13 . V_39 = ( ( V_8 << 24 ) | ( V_9 << 16 ) |
( V_10 << 8 ) ) ;
V_12 = F_10 ( V_2 , V_3 , V_40 , true ,
V_41 ,
V_42 ,
NULL , NULL , & V_2 -> V_13 . V_43 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_37 , L_4 , V_12 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 -> V_13 . V_43 , false ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_43 ) ;
F_5 ( V_2 -> V_37 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_13 ( V_2 -> V_13 . V_43 , V_41 ,
& V_2 -> V_13 . V_44 ) ;
F_14 ( V_2 -> V_13 . V_43 ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_43 ) ;
F_5 ( V_2 -> V_37 , L_6 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 ) {
F_15 ( & V_2 -> V_13 . V_46 [ V_11 ] , 0 ) ;
V_2 -> V_13 . V_47 [ V_11 ] = NULL ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_43 == NULL )
return 0 ;
F_12 ( & V_2 -> V_13 . V_43 ) ;
F_17 ( & V_2 -> V_13 . V_48 [ 0 ] ) ;
F_17 ( & V_2 -> V_13 . V_48 [ 1 ] ) ;
F_7 ( V_2 -> V_13 . V_36 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_13 . V_43 == NULL )
return 0 ;
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 )
if ( F_19 ( & V_2 -> V_13 . V_46 [ V_11 ] ) )
break;
if ( V_11 == V_45 )
return 0 ;
return - V_35 ;
}
int F_20 ( struct V_1 * V_2 )
{
void * V_49 ;
const struct V_5 * V_6 ;
unsigned V_50 ;
int V_12 ;
if ( V_2 -> V_13 . V_43 == NULL )
return - V_35 ;
V_12 = F_11 ( V_2 -> V_13 . V_43 , false ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_37 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_21 ( V_2 -> V_13 . V_43 , & V_49 ) ;
if ( V_12 ) {
F_14 ( V_2 -> V_13 . V_43 ) ;
F_5 ( V_2 -> V_37 , L_7 , V_12 ) ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_36 -> V_38 ;
V_50 = F_8 ( V_6 -> V_51 ) ;
memcpy ( V_49 , ( V_2 -> V_13 . V_36 -> V_38 ) + V_50 ,
( V_2 -> V_13 . V_36 -> V_3 ) - V_50 ) ;
F_22 ( V_2 -> V_13 . V_43 ) ;
F_14 ( V_2 -> V_13 . V_43 ) ;
return 0 ;
}
static void V_15 ( struct V_52 * V_53 )
{
struct V_1 * V_2 =
F_23 ( V_53 , struct V_1 , V_13 . V_14 . V_53 ) ;
if ( ( F_24 ( & V_2 -> V_13 . V_48 [ 0 ] ) == 0 ) &&
( F_24 ( & V_2 -> V_13 . V_48 [ 1 ] ) == 0 ) ) {
if ( V_2 -> V_54 . V_55 ) {
F_25 ( V_2 , false ) ;
} else {
F_26 ( V_2 , 0 , 0 ) ;
}
} else {
F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_56 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
bool V_57 = false ;
bool V_58 = ! F_30 ( & V_2 -> V_13 . V_14 ) ;
V_58 &= F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_56 ) ) ;
if ( V_2 -> V_54 . V_55 ) {
V_57 = false ;
}
if ( V_58 || V_57 ) {
if ( V_2 -> V_54 . V_55 ) {
F_25 ( V_2 , true ) ;
} else {
F_26 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_31 ( struct V_1 * V_2 , struct V_59 * V_47 )
{
struct V_60 * V_48 = & V_2 -> V_13 . V_48 [ 0 ] ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 ) {
T_1 V_61 = F_19 ( & V_2 -> V_13 . V_46 [ V_11 ] ) ;
if ( ! V_61 || V_2 -> V_13 . V_47 [ V_11 ] != V_47 )
continue;
F_29 ( V_2 ) ;
V_12 = F_32 ( V_48 , V_61 , NULL ) ;
if ( V_12 )
F_33 ( L_8 , V_12 ) ;
V_2 -> V_13 . V_47 [ V_11 ] = NULL ;
F_15 ( & V_2 -> V_13 . V_46 [ V_11 ] , 0 ) ;
}
}
static int F_34 (
struct V_62 * V_63 )
{
F_35 ( V_63 -> V_2 , V_63 -> V_64 ) ;
F_36 ( V_63 -> V_64 ) ;
return 0 ;
}
int F_37 ( struct V_60 * V_48 , T_1 V_61 ,
struct V_65 * * V_65 )
{
const unsigned V_66 = 1024 ;
struct V_67 * V_68 = NULL ;
struct V_65 * V_69 = NULL ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_70 ;
int V_11 , V_12 ;
V_68 = F_38 ( sizeof( struct V_67 ) , V_71 ) ;
if ( ! V_68 )
return - V_72 ;
V_12 = F_39 ( V_48 , NULL , V_66 * 4 , V_68 ) ;
if ( V_12 ) {
F_33 ( L_9 , V_12 ) ;
F_36 ( V_68 ) ;
return V_12 ;
}
V_70 = V_68 -> V_44 + 1024 ;
V_68 -> V_73 = 0 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x0000000c ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000001 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_61 ;
if ( ( V_48 -> V_2 -> V_13 . V_39 >> 24 ) >= 52 )
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000040 ;
else
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000030 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x01000001 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000042 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x0000000a ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000001 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000080 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000060 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000100 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000100 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x0000000c ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
if ( ( V_48 -> V_2 -> V_13 . V_39 >> 24 ) >= 52 ) {
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000000 ;
}
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000014 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x05000005 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = F_40 ( V_70 ) ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_70 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000001 ;
for ( V_11 = V_68 -> V_73 ; V_11 < V_66 ; ++ V_11 )
V_68 -> V_74 [ V_11 ] = 0x0 ;
V_12 = F_41 ( V_2 , V_48 , V_68 , 1 ,
& F_34 ,
V_75 ,
& V_69 ) ;
if ( V_12 )
goto V_76;
if ( V_65 )
* V_65 = F_42 ( V_69 ) ;
F_43 ( V_69 ) ;
if ( V_77 )
return 0 ;
V_76:
F_35 ( V_2 , V_68 ) ;
F_36 ( V_68 ) ;
return V_12 ;
}
int F_32 ( struct V_60 * V_48 , T_1 V_61 ,
struct V_65 * * V_65 )
{
const unsigned V_66 = 1024 ;
struct V_67 * V_68 = NULL ;
struct V_65 * V_69 = NULL ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_70 ;
int V_11 , V_12 ;
V_68 = F_38 ( sizeof( struct V_67 ) , V_71 ) ;
if ( ! V_68 )
return - V_72 ;
V_12 = F_39 ( V_48 , NULL , V_66 * 4 , V_68 ) ;
if ( V_12 ) {
F_36 ( V_68 ) ;
F_33 ( L_9 , V_12 ) ;
return V_12 ;
}
V_70 = V_68 -> V_44 + 1024 ;
V_68 -> V_73 = 0 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x0000000c ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000001 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_61 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000014 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x05000005 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = F_40 ( V_70 ) ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = V_70 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000001 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x00000008 ;
V_68 -> V_74 [ V_68 -> V_73 ++ ] = 0x02000001 ;
for ( V_11 = V_68 -> V_73 ; V_11 < V_66 ; ++ V_11 )
V_68 -> V_74 [ V_11 ] = 0x0 ;
V_12 = F_41 ( V_2 , V_48 , V_68 , 1 ,
& F_34 ,
V_75 ,
& V_69 ) ;
if ( V_12 )
goto V_76;
if ( V_65 )
* V_65 = F_42 ( V_69 ) ;
F_43 ( V_69 ) ;
if ( V_77 )
return 0 ;
V_76:
F_35 ( V_2 , V_68 ) ;
F_36 ( V_68 ) ;
return V_12 ;
}
static int F_44 ( struct V_78 * V_79 , T_1 V_80 ,
int V_81 , int V_82 , unsigned V_3 , T_1 V_83 )
{
struct V_84 * V_85 ;
struct V_67 * V_68 = & V_79 -> V_64 [ V_80 ] ;
struct V_86 * V_87 ;
T_2 V_88 ;
if ( V_83 == 0xffffffff )
V_83 = 0 ;
V_88 = ( ( T_2 ) F_45 ( V_79 , V_80 , V_81 ) ) |
( ( T_2 ) F_45 ( V_79 , V_80 , V_82 ) ) << 32 ;
V_88 += ( ( T_2 ) V_3 ) * ( ( T_2 ) V_83 ) ;
V_85 = F_46 ( V_79 , V_88 , & V_87 ) ;
if ( V_85 == NULL ) {
F_33 ( L_10 ,
V_88 , V_81 , V_82 , V_3 , V_83 ) ;
return - V_35 ;
}
if ( ( V_88 + ( T_2 ) V_3 ) >
( ( T_2 ) V_85 -> V_89 . V_90 + 1 ) * V_91 ) {
F_33 ( L_11 ,
V_88 , V_81 , V_82 ) ;
return - V_35 ;
}
V_88 -= ( ( T_2 ) V_85 -> V_89 . V_92 ) * V_91 ;
V_88 += F_47 ( V_87 ) ;
V_88 -= ( ( T_2 ) V_3 ) * ( ( T_2 ) V_83 ) ;
V_68 -> V_74 [ V_81 ] = V_88 & 0xFFFFFFFF ;
V_68 -> V_74 [ V_82 ] = V_88 >> 32 ;
return 0 ;
}
static int F_48 ( struct V_78 * V_79 ,
T_1 V_61 , bool * V_93 )
{
unsigned V_11 ;
* V_93 = false ;
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 ) {
if ( F_19 ( & V_79 -> V_2 -> V_13 . V_46 [ V_11 ] ) == V_61 ) {
if ( V_79 -> V_2 -> V_13 . V_47 [ V_11 ] != V_79 -> V_47 ) {
F_33 ( L_12 ) ;
return - V_35 ;
}
return V_11 ;
}
}
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 ) {
if ( ! F_49 ( & V_79 -> V_2 -> V_13 . V_46 [ V_11 ] , 0 , V_61 ) ) {
V_79 -> V_2 -> V_13 . V_47 [ V_11 ] = V_79 -> V_47 ;
V_79 -> V_2 -> V_13 . V_94 [ V_11 ] = 0 ;
* V_93 = true ;
return V_11 ;
}
}
F_33 ( L_13 ) ;
return - V_35 ;
}
int F_50 ( struct V_78 * V_79 , T_1 V_80 )
{
struct V_67 * V_68 = & V_79 -> V_64 [ V_80 ] ;
unsigned V_95 = 0 , V_96 = 0 ;
int V_97 = - 1 ;
bool V_98 = false ;
bool V_99 = false ;
bool V_93 = false ;
T_1 V_100 , V_61 = 0 ;
T_1 * V_3 = & V_100 ;
int V_11 , V_12 = 0 , V_101 = 0 ;
F_29 ( V_79 -> V_2 ) ;
while ( V_101 < V_68 -> V_73 ) {
T_1 V_102 = F_45 ( V_79 , V_80 , V_101 ) ;
T_1 V_103 = F_45 ( V_79 , V_80 , V_101 + 1 ) ;
if ( ( V_102 < 8 ) || ( V_102 & 3 ) ) {
F_33 ( L_14 , V_102 ) ;
V_12 = - V_35 ;
goto V_104;
}
if ( V_98 ) {
F_33 ( L_15 ) ;
V_12 = - V_35 ;
goto V_104;
}
switch ( V_103 ) {
case 0x00000001 :
V_61 = F_45 ( V_79 , V_80 , V_101 + 2 ) ;
V_97 = F_48 ( V_79 , V_61 ,
& V_93 ) ;
if ( V_97 < 0 )
return V_97 ;
V_3 = & V_79 -> V_2 -> V_13 . V_94 [ V_97 ] ;
break;
case 0x00000002 :
V_95 = F_45 ( V_79 , V_80 , V_101 + 6 ) ;
V_96 = F_45 ( V_79 , V_80 , V_101 + 7 ) ;
break;
case 0x01000001 :
V_99 = true ;
if ( ! V_93 ) {
F_33 ( L_16 ) ;
V_12 = - V_35 ;
goto V_104;
}
* V_3 = F_45 ( V_79 , V_80 , V_101 + 8 ) *
F_45 ( V_79 , V_80 , V_101 + 10 ) *
8 * 3 / 2 ;
break;
case 0x04000001 :
case 0x04000002 :
case 0x04000005 :
case 0x04000007 :
case 0x04000008 :
case 0x04000009 :
case 0x05000002 :
break;
case 0x03000001 :
V_12 = F_44 ( V_79 , V_80 , V_101 + 10 , V_101 + 9 ,
* V_3 , 0 ) ;
if ( V_12 )
goto V_104;
V_12 = F_44 ( V_79 , V_80 , V_101 + 12 , V_101 + 11 ,
* V_3 / 3 , 0 ) ;
if ( V_12 )
goto V_104;
break;
case 0x02000001 :
V_98 = true ;
break;
case 0x05000001 :
V_12 = F_44 ( V_79 , V_80 , V_101 + 3 , V_101 + 2 ,
* V_3 * 2 , 0 ) ;
if ( V_12 )
goto V_104;
break;
case 0x05000004 :
V_100 = F_45 ( V_79 , V_80 , V_101 + 4 ) ;
V_12 = F_44 ( V_79 , V_80 , V_101 + 3 , V_101 + 2 ,
V_100 , V_96 ) ;
if ( V_12 )
goto V_104;
break;
case 0x05000005 :
V_12 = F_44 ( V_79 , V_80 , V_101 + 3 , V_101 + 2 ,
4096 , V_95 ) ;
if ( V_12 )
goto V_104;
break;
default:
F_33 ( L_17 , V_103 ) ;
V_12 = - V_35 ;
goto V_104;
}
if ( V_97 == - 1 ) {
F_33 ( L_18 ) ;
V_12 = - V_35 ;
goto V_104;
}
V_101 += V_102 / 4 ;
}
if ( V_93 && ! V_99 ) {
F_33 ( L_19 ) ;
V_12 = - V_105 ;
}
V_104:
if ( ( ! V_12 && V_98 ) || ( V_12 && V_93 ) ) {
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 )
F_49 ( & V_79 -> V_2 -> V_13 . V_46 [ V_11 ] , V_61 , 0 ) ;
}
return V_12 ;
}
bool F_51 ( struct V_60 * V_48 ,
struct V_106 * V_107 ,
bool V_108 )
{
T_2 V_88 = V_107 -> V_44 ;
F_52 ( V_48 , V_109 ) ;
F_52 ( V_48 , ( V_88 >> 3 ) & 0x000FFFFF ) ;
F_52 ( V_48 , ( V_88 >> 23 ) & 0x000FFFFF ) ;
F_52 ( V_48 , 0x01003000 | ( V_108 ? 1 : 0 ) ) ;
if ( ! V_108 )
F_52 ( V_48 , V_110 ) ;
return true ;
}
void F_53 ( struct V_60 * V_48 , struct V_67 * V_68 )
{
F_52 ( V_48 , V_111 ) ;
F_52 ( V_48 , F_54 ( V_68 -> V_44 ) ) ;
F_52 ( V_48 , F_40 ( V_68 -> V_44 ) ) ;
F_52 ( V_48 , V_68 -> V_73 ) ;
}
void F_55 ( struct V_60 * V_48 , T_3 V_88 , T_3 V_112 ,
unsigned V_113 )
{
F_56 ( V_113 & V_114 ) ;
F_52 ( V_48 , V_115 ) ;
F_52 ( V_48 , V_88 ) ;
F_52 ( V_48 , F_40 ( V_88 ) ) ;
F_52 ( V_48 , V_112 ) ;
F_52 ( V_48 , V_116 ) ;
F_52 ( V_48 , V_110 ) ;
}
int F_57 ( struct V_60 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_117 = F_58 ( V_48 ) ;
unsigned V_11 ;
int V_12 ;
V_12 = F_59 ( V_48 , 16 ) ;
if ( V_12 ) {
F_33 ( L_20 ,
V_48 -> V_101 , V_12 ) ;
return V_12 ;
}
F_52 ( V_48 , V_110 ) ;
F_60 ( V_48 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_118 ; V_11 ++ ) {
if ( F_58 ( V_48 ) != V_117 )
break;
F_61 ( 1 ) ;
}
if ( V_11 < V_2 -> V_118 ) {
F_9 ( L_21 ,
V_48 -> V_101 , V_11 ) ;
} else {
F_33 ( L_22 ,
V_48 -> V_101 ) ;
V_12 = - V_119 ;
}
return V_12 ;
}
int F_62 ( struct V_60 * V_48 )
{
struct V_65 * V_65 = NULL ;
int V_12 ;
if ( V_48 == & V_48 -> V_2 -> V_13 . V_48 [ 1 ] )
return 0 ;
V_12 = F_37 ( V_48 , 1 , NULL ) ;
if ( V_12 ) {
F_33 ( L_23 , V_12 ) ;
goto error;
}
V_12 = F_32 ( V_48 , 1 , & V_65 ) ;
if ( V_12 ) {
F_33 ( L_24 , V_12 ) ;
goto error;
}
V_12 = F_63 ( V_65 , false ) ;
if ( V_12 ) {
F_33 ( L_25 , V_12 ) ;
} else {
F_9 ( L_26 , V_48 -> V_101 ) ;
}
error:
F_43 ( V_65 ) ;
return V_12 ;
}
