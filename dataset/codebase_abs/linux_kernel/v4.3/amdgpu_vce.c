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
default:
return - V_33 ;
}
V_12 = F_4 ( & V_2 -> V_13 . V_34 , V_4 , V_2 -> V_35 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_35 , L_1 ,
V_4 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 -> V_13 . V_34 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_35 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_13 . V_34 ) ;
V_2 -> V_13 . V_34 = NULL ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_34 -> V_36 ;
V_7 = F_8 ( V_6 -> V_7 ) ;
V_8 = ( V_7 >> 20 ) & 0xfff ;
V_9 = ( V_7 >> 8 ) & 0xfff ;
V_10 = V_7 & 0xff ;
F_9 ( L_3 ,
V_8 , V_9 , V_10 ) ;
V_2 -> V_13 . V_37 = ( ( V_8 << 24 ) | ( V_9 << 16 ) |
( V_10 << 8 ) ) ;
V_12 = F_10 ( V_2 , V_3 , V_38 , true ,
V_39 ,
V_40 ,
NULL , NULL , & V_2 -> V_13 . V_41 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_35 , L_4 , V_12 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 -> V_13 . V_41 , false ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_41 ) ;
F_5 ( V_2 -> V_35 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_13 ( V_2 -> V_13 . V_41 , V_39 ,
& V_2 -> V_13 . V_42 ) ;
F_14 ( V_2 -> V_13 . V_41 ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_41 ) ;
F_5 ( V_2 -> V_35 , L_6 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 ) {
F_15 ( & V_2 -> V_13 . V_44 [ V_11 ] , 0 ) ;
V_2 -> V_13 . V_45 [ V_11 ] = NULL ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_41 == NULL )
return 0 ;
F_12 ( & V_2 -> V_13 . V_41 ) ;
F_17 ( & V_2 -> V_13 . V_46 [ 0 ] ) ;
F_17 ( & V_2 -> V_13 . V_46 [ 1 ] ) ;
F_7 ( V_2 -> V_13 . V_34 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_13 . V_41 == NULL )
return 0 ;
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 )
if ( F_19 ( & V_2 -> V_13 . V_44 [ V_11 ] ) )
break;
if ( V_11 == V_43 )
return 0 ;
return - V_33 ;
}
int F_20 ( struct V_1 * V_2 )
{
void * V_47 ;
const struct V_5 * V_6 ;
unsigned V_48 ;
int V_12 ;
if ( V_2 -> V_13 . V_41 == NULL )
return - V_33 ;
V_12 = F_11 ( V_2 -> V_13 . V_41 , false ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_35 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_21 ( V_2 -> V_13 . V_41 , & V_47 ) ;
if ( V_12 ) {
F_14 ( V_2 -> V_13 . V_41 ) ;
F_5 ( V_2 -> V_35 , L_7 , V_12 ) ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_34 -> V_36 ;
V_48 = F_8 ( V_6 -> V_49 ) ;
memcpy ( V_47 , ( V_2 -> V_13 . V_34 -> V_36 ) + V_48 ,
( V_2 -> V_13 . V_34 -> V_3 ) - V_48 ) ;
F_22 ( V_2 -> V_13 . V_41 ) ;
F_14 ( V_2 -> V_13 . V_41 ) ;
return 0 ;
}
static void V_15 ( struct V_50 * V_51 )
{
struct V_1 * V_2 =
F_23 ( V_51 , struct V_1 , V_13 . V_14 . V_51 ) ;
if ( ( F_24 ( & V_2 -> V_13 . V_46 [ 0 ] ) == 0 ) &&
( F_24 ( & V_2 -> V_13 . V_46 [ 1 ] ) == 0 ) ) {
if ( V_2 -> V_52 . V_53 ) {
F_25 ( V_2 , false ) ;
} else {
F_26 ( V_2 , 0 , 0 ) ;
}
} else {
F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_54 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
bool V_55 = false ;
bool V_56 = ! F_30 ( & V_2 -> V_13 . V_14 ) ;
V_56 &= F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_54 ) ) ;
if ( V_2 -> V_52 . V_53 ) {
V_55 = false ;
}
if ( V_56 || V_55 ) {
if ( V_2 -> V_52 . V_53 ) {
F_25 ( V_2 , true ) ;
} else {
F_26 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_31 ( struct V_1 * V_2 , struct V_57 * V_45 )
{
struct V_58 * V_46 = & V_2 -> V_13 . V_46 [ 0 ] ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 ) {
T_1 V_59 = F_19 ( & V_2 -> V_13 . V_44 [ V_11 ] ) ;
if ( ! V_59 || V_2 -> V_13 . V_45 [ V_11 ] != V_45 )
continue;
F_29 ( V_2 ) ;
V_12 = F_32 ( V_46 , V_59 , NULL ) ;
if ( V_12 )
F_33 ( L_8 , V_12 ) ;
V_2 -> V_13 . V_45 [ V_11 ] = NULL ;
F_15 ( & V_2 -> V_13 . V_44 [ V_11 ] , 0 ) ;
}
}
static int F_34 (
struct V_60 * V_61 )
{
F_35 ( V_61 -> V_2 , V_61 -> V_62 ) ;
F_36 ( V_61 -> V_62 ) ;
return 0 ;
}
int F_37 ( struct V_58 * V_46 , T_1 V_59 ,
struct V_63 * * V_63 )
{
const unsigned V_64 = 1024 ;
struct V_65 * V_66 = NULL ;
struct V_63 * V_67 = NULL ;
struct V_1 * V_2 = V_46 -> V_2 ;
T_2 V_68 ;
int V_11 , V_12 ;
V_66 = F_38 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_66 )
return - V_70 ;
V_12 = F_39 ( V_46 , NULL , V_64 * 4 , V_66 ) ;
if ( V_12 ) {
F_33 ( L_9 , V_12 ) ;
F_36 ( V_66 ) ;
return V_12 ;
}
V_68 = V_66 -> V_42 + 1024 ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x0000000c ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000001 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = V_59 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000030 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x01000001 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000000 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000042 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x0000000a ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000001 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000080 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000060 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000100 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000100 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x0000000c ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000000 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000014 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x05000005 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = F_40 ( V_68 ) ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = V_68 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000001 ;
for ( V_11 = V_66 -> V_71 ; V_11 < V_64 ; ++ V_11 )
V_66 -> V_72 [ V_11 ] = 0x0 ;
V_12 = F_41 ( V_2 , V_46 , V_66 , 1 ,
& F_34 ,
V_73 ,
& V_67 ) ;
if ( V_12 )
goto V_74;
if ( V_63 )
* V_63 = F_42 ( V_67 ) ;
F_43 ( V_67 ) ;
if ( V_75 )
return 0 ;
V_74:
F_35 ( V_2 , V_66 ) ;
F_36 ( V_66 ) ;
return V_12 ;
}
int F_32 ( struct V_58 * V_46 , T_1 V_59 ,
struct V_63 * * V_63 )
{
const unsigned V_64 = 1024 ;
struct V_65 * V_66 = NULL ;
struct V_63 * V_67 = NULL ;
struct V_1 * V_2 = V_46 -> V_2 ;
T_2 V_68 ;
int V_11 , V_12 ;
V_66 = F_38 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_66 )
return - V_70 ;
V_12 = F_39 ( V_46 , NULL , V_64 * 4 , V_66 ) ;
if ( V_12 ) {
F_36 ( V_66 ) ;
F_33 ( L_9 , V_12 ) ;
return V_12 ;
}
V_68 = V_66 -> V_42 + 1024 ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x0000000c ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000001 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = V_59 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000014 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x05000005 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = F_40 ( V_68 ) ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = V_68 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000001 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x00000008 ;
V_66 -> V_72 [ V_66 -> V_71 ++ ] = 0x02000001 ;
for ( V_11 = V_66 -> V_71 ; V_11 < V_64 ; ++ V_11 )
V_66 -> V_72 [ V_11 ] = 0x0 ;
V_12 = F_41 ( V_2 , V_46 , V_66 , 1 ,
& F_34 ,
V_73 ,
& V_67 ) ;
if ( V_12 )
goto V_74;
if ( V_63 )
* V_63 = F_42 ( V_67 ) ;
F_43 ( V_67 ) ;
if ( V_75 )
return 0 ;
V_74:
F_35 ( V_2 , V_66 ) ;
F_36 ( V_66 ) ;
return V_12 ;
}
static int F_44 ( struct V_76 * V_77 , T_1 V_78 ,
int V_79 , int V_80 , unsigned V_3 , T_1 V_81 )
{
struct V_82 * V_83 ;
struct V_65 * V_66 = & V_77 -> V_62 [ V_78 ] ;
struct V_84 * V_85 ;
T_2 V_86 ;
if ( V_81 == 0xffffffff )
V_81 = 0 ;
V_86 = ( ( T_2 ) F_45 ( V_77 , V_78 , V_79 ) ) |
( ( T_2 ) F_45 ( V_77 , V_78 , V_80 ) ) << 32 ;
V_86 += ( ( T_2 ) V_3 ) * ( ( T_2 ) V_81 ) ;
V_83 = F_46 ( V_77 , V_86 , & V_85 ) ;
if ( V_83 == NULL ) {
F_33 ( L_10 ,
V_86 , V_79 , V_80 , V_3 , V_81 ) ;
return - V_33 ;
}
if ( ( V_86 + ( T_2 ) V_3 ) >
( ( T_2 ) V_83 -> V_87 . V_88 + 1 ) * V_89 ) {
F_33 ( L_11 ,
V_86 , V_79 , V_80 ) ;
return - V_33 ;
}
V_86 -= ( ( T_2 ) V_83 -> V_87 . V_90 ) * V_89 ;
V_86 += F_47 ( V_85 ) ;
V_86 -= ( ( T_2 ) V_3 ) * ( ( T_2 ) V_81 ) ;
V_66 -> V_72 [ V_79 ] = V_86 & 0xFFFFFFFF ;
V_66 -> V_72 [ V_80 ] = V_86 >> 32 ;
return 0 ;
}
static int F_48 ( struct V_76 * V_77 ,
T_1 V_59 , bool * V_91 )
{
unsigned V_11 ;
* V_91 = false ;
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 ) {
if ( F_19 ( & V_77 -> V_2 -> V_13 . V_44 [ V_11 ] ) == V_59 ) {
if ( V_77 -> V_2 -> V_13 . V_45 [ V_11 ] != V_77 -> V_45 ) {
F_33 ( L_12 ) ;
return - V_33 ;
}
return V_11 ;
}
}
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 ) {
if ( ! F_49 ( & V_77 -> V_2 -> V_13 . V_44 [ V_11 ] , 0 , V_59 ) ) {
V_77 -> V_2 -> V_13 . V_45 [ V_11 ] = V_77 -> V_45 ;
V_77 -> V_2 -> V_13 . V_92 [ V_11 ] = 0 ;
* V_91 = true ;
return V_11 ;
}
}
F_33 ( L_13 ) ;
return - V_33 ;
}
int F_50 ( struct V_76 * V_77 , T_1 V_78 )
{
struct V_65 * V_66 = & V_77 -> V_62 [ V_78 ] ;
unsigned V_93 = 0 , V_94 = 0 ;
int V_95 = - 1 ;
bool V_96 = false ;
bool V_97 = false ;
bool V_91 = false ;
T_1 V_98 , V_59 = 0 ;
T_1 * V_3 = & V_98 ;
int V_11 , V_12 = 0 , V_99 = 0 ;
F_29 ( V_77 -> V_2 ) ;
while ( V_99 < V_66 -> V_71 ) {
T_1 V_100 = F_45 ( V_77 , V_78 , V_99 ) ;
T_1 V_101 = F_45 ( V_77 , V_78 , V_99 + 1 ) ;
if ( ( V_100 < 8 ) || ( V_100 & 3 ) ) {
F_33 ( L_14 , V_100 ) ;
V_12 = - V_33 ;
goto V_102;
}
if ( V_96 ) {
F_33 ( L_15 ) ;
V_12 = - V_33 ;
goto V_102;
}
switch ( V_101 ) {
case 0x00000001 :
V_59 = F_45 ( V_77 , V_78 , V_99 + 2 ) ;
V_95 = F_48 ( V_77 , V_59 ,
& V_91 ) ;
if ( V_95 < 0 )
return V_95 ;
V_3 = & V_77 -> V_2 -> V_13 . V_92 [ V_95 ] ;
break;
case 0x00000002 :
V_93 = F_45 ( V_77 , V_78 , V_99 + 6 ) ;
V_94 = F_45 ( V_77 , V_78 , V_99 + 7 ) ;
break;
case 0x01000001 :
V_97 = true ;
if ( ! V_91 ) {
F_33 ( L_16 ) ;
V_12 = - V_33 ;
goto V_102;
}
* V_3 = F_45 ( V_77 , V_78 , V_99 + 8 ) *
F_45 ( V_77 , V_78 , V_99 + 10 ) *
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
V_12 = F_44 ( V_77 , V_78 , V_99 + 10 , V_99 + 9 ,
* V_3 , 0 ) ;
if ( V_12 )
goto V_102;
V_12 = F_44 ( V_77 , V_78 , V_99 + 12 , V_99 + 11 ,
* V_3 / 3 , 0 ) ;
if ( V_12 )
goto V_102;
break;
case 0x02000001 :
V_96 = true ;
break;
case 0x05000001 :
V_12 = F_44 ( V_77 , V_78 , V_99 + 3 , V_99 + 2 ,
* V_3 * 2 , 0 ) ;
if ( V_12 )
goto V_102;
break;
case 0x05000004 :
V_98 = F_45 ( V_77 , V_78 , V_99 + 4 ) ;
V_12 = F_44 ( V_77 , V_78 , V_99 + 3 , V_99 + 2 ,
V_98 , V_94 ) ;
if ( V_12 )
goto V_102;
break;
case 0x05000005 :
V_12 = F_44 ( V_77 , V_78 , V_99 + 3 , V_99 + 2 ,
4096 , V_93 ) ;
if ( V_12 )
goto V_102;
break;
default:
F_33 ( L_17 , V_101 ) ;
V_12 = - V_33 ;
goto V_102;
}
if ( V_95 == - 1 ) {
F_33 ( L_18 ) ;
V_12 = - V_33 ;
goto V_102;
}
V_99 += V_100 / 4 ;
}
if ( V_91 && ! V_97 ) {
F_33 ( L_19 ) ;
V_12 = - V_103 ;
}
V_102:
if ( ( ! V_12 && V_96 ) || ( V_12 && V_91 ) ) {
for ( V_11 = 0 ; V_11 < V_43 ; ++ V_11 )
F_49 ( & V_77 -> V_2 -> V_13 . V_44 [ V_11 ] , V_59 , 0 ) ;
}
return V_12 ;
}
bool F_51 ( struct V_58 * V_46 ,
struct V_104 * V_105 ,
bool V_106 )
{
T_2 V_86 = V_105 -> V_42 ;
F_52 ( V_46 , V_107 ) ;
F_52 ( V_46 , ( V_86 >> 3 ) & 0x000FFFFF ) ;
F_52 ( V_46 , ( V_86 >> 23 ) & 0x000FFFFF ) ;
F_52 ( V_46 , 0x01003000 | ( V_106 ? 1 : 0 ) ) ;
if ( ! V_106 )
F_52 ( V_46 , V_108 ) ;
return true ;
}
void F_53 ( struct V_58 * V_46 , struct V_65 * V_66 )
{
F_52 ( V_46 , V_109 ) ;
F_52 ( V_46 , F_54 ( V_66 -> V_42 ) ) ;
F_52 ( V_46 , F_40 ( V_66 -> V_42 ) ) ;
F_52 ( V_46 , V_66 -> V_71 ) ;
}
void F_55 ( struct V_58 * V_46 , T_3 V_86 , T_3 V_110 ,
unsigned V_111 )
{
F_56 ( V_111 & V_112 ) ;
F_52 ( V_46 , V_113 ) ;
F_52 ( V_46 , V_86 ) ;
F_52 ( V_46 , F_40 ( V_86 ) ) ;
F_52 ( V_46 , V_110 ) ;
F_52 ( V_46 , V_114 ) ;
F_52 ( V_46 , V_108 ) ;
}
int F_57 ( struct V_58 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_115 = F_58 ( V_46 ) ;
unsigned V_11 ;
int V_12 ;
V_12 = F_59 ( V_46 , 16 ) ;
if ( V_12 ) {
F_33 ( L_20 ,
V_46 -> V_99 , V_12 ) ;
return V_12 ;
}
F_52 ( V_46 , V_108 ) ;
F_60 ( V_46 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_116 ; V_11 ++ ) {
if ( F_58 ( V_46 ) != V_115 )
break;
F_61 ( 1 ) ;
}
if ( V_11 < V_2 -> V_116 ) {
F_9 ( L_21 ,
V_46 -> V_99 , V_11 ) ;
} else {
F_33 ( L_22 ,
V_46 -> V_99 ) ;
V_12 = - V_117 ;
}
return V_12 ;
}
int F_62 ( struct V_58 * V_46 )
{
struct V_63 * V_63 = NULL ;
int V_12 ;
if ( V_46 == & V_46 -> V_2 -> V_13 . V_46 [ 1 ] )
return 0 ;
V_12 = F_37 ( V_46 , 1 , NULL ) ;
if ( V_12 ) {
F_33 ( L_23 , V_12 ) ;
goto error;
}
V_12 = F_32 ( V_46 , 1 , & V_63 ) ;
if ( V_12 ) {
F_33 ( L_24 , V_12 ) ;
goto error;
}
V_12 = F_63 ( V_63 , false ) ;
if ( V_12 ) {
F_33 ( L_25 , V_12 ) ;
} else {
F_9 ( L_26 , V_46 -> V_99 ) ;
}
error:
F_43 ( V_63 ) ;
return V_12 ;
}
