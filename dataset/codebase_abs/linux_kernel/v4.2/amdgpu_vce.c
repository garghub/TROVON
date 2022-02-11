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
default:
return - V_31 ;
}
V_12 = F_4 ( & V_2 -> V_13 . V_32 , V_4 , V_2 -> V_33 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_33 , L_1 ,
V_4 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 -> V_13 . V_32 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_33 , L_2 ,
V_4 ) ;
F_7 ( V_2 -> V_13 . V_32 ) ;
V_2 -> V_13 . V_32 = NULL ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_32 -> V_34 ;
V_7 = F_8 ( V_6 -> V_7 ) ;
V_8 = ( V_7 >> 20 ) & 0xfff ;
V_9 = ( V_7 >> 8 ) & 0xfff ;
V_10 = V_7 & 0xff ;
F_9 ( L_3 ,
V_8 , V_9 , V_10 ) ;
V_2 -> V_13 . V_35 = ( ( V_8 << 24 ) | ( V_9 << 16 ) |
( V_10 << 8 ) ) ;
V_12 = F_10 ( V_2 , V_3 , V_36 , true ,
V_37 , 0 , NULL , & V_2 -> V_13 . V_38 ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_33 , L_4 , V_12 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 -> V_13 . V_38 , false ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_38 ) ;
F_5 ( V_2 -> V_33 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_13 ( V_2 -> V_13 . V_38 , V_37 ,
& V_2 -> V_13 . V_39 ) ;
F_14 ( V_2 -> V_13 . V_38 ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_13 . V_38 ) ;
F_5 ( V_2 -> V_33 , L_6 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 ) {
F_15 ( & V_2 -> V_13 . V_41 [ V_11 ] , 0 ) ;
V_2 -> V_13 . V_42 [ V_11 ] = NULL ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_38 == NULL )
return 0 ;
F_12 ( & V_2 -> V_13 . V_38 ) ;
F_17 ( & V_2 -> V_13 . V_43 [ 0 ] ) ;
F_17 ( & V_2 -> V_13 . V_43 [ 1 ] ) ;
F_7 ( V_2 -> V_13 . V_32 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_13 . V_38 == NULL )
return 0 ;
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 )
if ( F_19 ( & V_2 -> V_13 . V_41 [ V_11 ] ) )
break;
if ( V_11 == V_40 )
return 0 ;
return - V_31 ;
}
int F_20 ( struct V_1 * V_2 )
{
void * V_44 ;
const struct V_5 * V_6 ;
unsigned V_45 ;
int V_12 ;
if ( V_2 -> V_13 . V_38 == NULL )
return - V_31 ;
V_12 = F_11 ( V_2 -> V_13 . V_38 , false ) ;
if ( V_12 ) {
F_5 ( V_2 -> V_33 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_21 ( V_2 -> V_13 . V_38 , & V_44 ) ;
if ( V_12 ) {
F_14 ( V_2 -> V_13 . V_38 ) ;
F_5 ( V_2 -> V_33 , L_7 , V_12 ) ;
return V_12 ;
}
V_6 = ( const struct V_5 * ) V_2 -> V_13 . V_32 -> V_34 ;
V_45 = F_8 ( V_6 -> V_46 ) ;
memcpy ( V_44 , ( V_2 -> V_13 . V_32 -> V_34 ) + V_45 ,
( V_2 -> V_13 . V_32 -> V_3 ) - V_45 ) ;
F_22 ( V_2 -> V_13 . V_38 ) ;
F_14 ( V_2 -> V_13 . V_38 ) ;
return 0 ;
}
static void V_15 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
F_23 ( V_48 , struct V_1 , V_13 . V_14 . V_48 ) ;
if ( ( F_24 ( & V_2 -> V_13 . V_43 [ 0 ] ) == 0 ) &&
( F_24 ( & V_2 -> V_13 . V_43 [ 1 ] ) == 0 ) ) {
if ( V_2 -> V_49 . V_50 ) {
F_25 ( V_2 , false ) ;
} else {
F_26 ( V_2 , 0 , 0 ) ;
}
} else {
F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_51 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
bool V_52 = false ;
bool V_53 = ! F_30 ( & V_2 -> V_13 . V_14 ) ;
V_53 &= F_27 ( & V_2 -> V_13 . V_14 ,
F_28 ( V_51 ) ) ;
if ( V_2 -> V_49 . V_50 ) {
V_52 = false ;
}
if ( V_53 || V_52 ) {
if ( V_2 -> V_49 . V_50 ) {
F_25 ( V_2 , true ) ;
} else {
F_26 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_31 ( struct V_1 * V_2 , struct V_54 * V_42 )
{
struct V_55 * V_43 = & V_2 -> V_13 . V_43 [ 0 ] ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 ) {
T_1 V_56 = F_19 ( & V_2 -> V_13 . V_41 [ V_11 ] ) ;
if ( ! V_56 || V_2 -> V_13 . V_42 [ V_11 ] != V_42 )
continue;
F_29 ( V_2 ) ;
V_12 = F_32 ( V_43 , V_56 , NULL ) ;
if ( V_12 )
F_33 ( L_8 , V_12 ) ;
V_2 -> V_13 . V_42 [ V_11 ] = NULL ;
F_15 ( & V_2 -> V_13 . V_41 [ V_11 ] , 0 ) ;
}
}
int F_34 ( struct V_55 * V_43 , T_1 V_56 ,
struct V_57 * * V_58 )
{
const unsigned V_59 = 1024 ;
struct V_60 V_61 ;
T_2 V_62 ;
int V_11 , V_12 ;
V_12 = F_35 ( V_43 , NULL , V_59 * 4 , & V_61 ) ;
if ( V_12 ) {
F_33 ( L_9 , V_12 ) ;
return V_12 ;
}
V_62 = V_61 . V_39 + 1024 ;
V_61 . V_63 = 0 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x0000000c ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000001 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = V_56 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000030 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x01000001 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000000 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000042 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x0000000a ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000001 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000080 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000060 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000100 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000100 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x0000000c ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000000 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000014 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x05000005 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = F_36 ( V_62 ) ;
V_61 . V_64 [ V_61 . V_63 ++ ] = V_62 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000001 ;
for ( V_11 = V_61 . V_63 ; V_11 < V_59 ; ++ V_11 )
V_61 . V_64 [ V_11 ] = 0x0 ;
V_12 = F_37 ( V_43 -> V_2 , 1 , & V_61 , V_65 ) ;
if ( V_12 ) {
F_33 ( L_10 , V_12 ) ;
}
if ( V_58 )
* V_58 = F_38 ( V_61 . V_58 ) ;
F_39 ( V_43 -> V_2 , & V_61 ) ;
return V_12 ;
}
int F_32 ( struct V_55 * V_43 , T_1 V_56 ,
struct V_57 * * V_58 )
{
const unsigned V_59 = 1024 ;
struct V_60 V_61 ;
T_2 V_62 ;
int V_11 , V_12 ;
V_12 = F_35 ( V_43 , NULL , V_59 * 4 , & V_61 ) ;
if ( V_12 ) {
F_33 ( L_9 , V_12 ) ;
return V_12 ;
}
V_62 = V_61 . V_39 + 1024 ;
V_61 . V_63 = 0 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x0000000c ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000001 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = V_56 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000014 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x05000005 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = F_36 ( V_62 ) ;
V_61 . V_64 [ V_61 . V_63 ++ ] = V_62 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000001 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x00000008 ;
V_61 . V_64 [ V_61 . V_63 ++ ] = 0x02000001 ;
for ( V_11 = V_61 . V_63 ; V_11 < V_59 ; ++ V_11 )
V_61 . V_64 [ V_11 ] = 0x0 ;
V_12 = F_37 ( V_43 -> V_2 , 1 , & V_61 , V_65 ) ;
if ( V_12 ) {
F_33 ( L_10 , V_12 ) ;
}
if ( V_58 )
* V_58 = F_38 ( V_61 . V_58 ) ;
F_39 ( V_43 -> V_2 , & V_61 ) ;
return V_12 ;
}
static int F_40 ( struct V_66 * V_67 , T_1 V_68 ,
int V_69 , int V_70 , unsigned V_3 , T_1 V_71 )
{
struct V_72 * V_73 ;
struct V_60 * V_61 = & V_67 -> V_74 [ V_68 ] ;
struct V_75 * V_76 ;
T_2 V_77 ;
if ( V_71 == 0xffffffff )
V_71 = 0 ;
V_77 = ( ( T_2 ) F_41 ( V_67 , V_68 , V_69 ) ) |
( ( T_2 ) F_41 ( V_67 , V_68 , V_70 ) ) << 32 ;
V_77 += ( ( T_2 ) V_3 ) * ( ( T_2 ) V_71 ) ;
V_73 = F_42 ( V_67 , V_77 , & V_76 ) ;
if ( V_73 == NULL ) {
F_33 ( L_11 ,
V_77 , V_69 , V_70 , V_3 , V_71 ) ;
return - V_31 ;
}
if ( ( V_77 + ( T_2 ) V_3 ) >
( ( T_2 ) V_73 -> V_78 . V_79 + 1 ) * V_80 ) {
F_33 ( L_12 ,
V_77 , V_69 , V_70 ) ;
return - V_31 ;
}
V_77 -= ( ( T_2 ) V_73 -> V_78 . V_81 ) * V_80 ;
V_77 += F_43 ( V_76 ) ;
V_77 -= ( ( T_2 ) V_3 ) * ( ( T_2 ) V_71 ) ;
V_61 -> V_64 [ V_69 ] = V_77 & 0xFFFFFFFF ;
V_61 -> V_64 [ V_70 ] = V_77 >> 32 ;
return 0 ;
}
static int F_44 ( struct V_66 * V_67 ,
T_1 V_56 , bool * V_82 )
{
unsigned V_11 ;
* V_82 = false ;
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 ) {
if ( F_19 ( & V_67 -> V_2 -> V_13 . V_41 [ V_11 ] ) == V_56 ) {
if ( V_67 -> V_2 -> V_13 . V_42 [ V_11 ] != V_67 -> V_42 ) {
F_33 ( L_13 ) ;
return - V_31 ;
}
return V_11 ;
}
}
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 ) {
if ( ! F_45 ( & V_67 -> V_2 -> V_13 . V_41 [ V_11 ] , 0 , V_56 ) ) {
V_67 -> V_2 -> V_13 . V_42 [ V_11 ] = V_67 -> V_42 ;
V_67 -> V_2 -> V_13 . V_83 [ V_11 ] = 0 ;
* V_82 = true ;
return V_11 ;
}
}
F_33 ( L_14 ) ;
return - V_31 ;
}
int F_46 ( struct V_66 * V_67 , T_1 V_68 )
{
struct V_60 * V_61 = & V_67 -> V_74 [ V_68 ] ;
unsigned V_84 = 0 , V_85 = 0 ;
int V_86 = - 1 ;
bool V_87 = false ;
bool V_88 = false ;
bool V_82 = false ;
T_1 V_89 , V_56 = 0 ;
T_1 * V_3 = & V_89 ;
int V_11 , V_12 = 0 , V_90 = 0 ;
F_29 ( V_67 -> V_2 ) ;
while ( V_90 < V_61 -> V_63 ) {
T_1 V_91 = F_41 ( V_67 , V_68 , V_90 ) ;
T_1 V_92 = F_41 ( V_67 , V_68 , V_90 + 1 ) ;
if ( ( V_91 < 8 ) || ( V_91 & 3 ) ) {
F_33 ( L_15 , V_91 ) ;
V_12 = - V_31 ;
goto V_93;
}
if ( V_87 ) {
F_33 ( L_16 ) ;
V_12 = - V_31 ;
goto V_93;
}
switch ( V_92 ) {
case 0x00000001 :
V_56 = F_41 ( V_67 , V_68 , V_90 + 2 ) ;
V_86 = F_44 ( V_67 , V_56 ,
& V_82 ) ;
if ( V_86 < 0 )
return V_86 ;
V_3 = & V_67 -> V_2 -> V_13 . V_83 [ V_86 ] ;
break;
case 0x00000002 :
V_84 = F_41 ( V_67 , V_68 , V_90 + 6 ) ;
V_85 = F_41 ( V_67 , V_68 , V_90 + 7 ) ;
break;
case 0x01000001 :
V_88 = true ;
if ( ! V_82 ) {
F_33 ( L_17 ) ;
V_12 = - V_31 ;
goto V_93;
}
* V_3 = F_41 ( V_67 , V_68 , V_90 + 8 ) *
F_41 ( V_67 , V_68 , V_90 + 10 ) *
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
V_12 = F_40 ( V_67 , V_68 , V_90 + 10 , V_90 + 9 ,
* V_3 , 0 ) ;
if ( V_12 )
goto V_93;
V_12 = F_40 ( V_67 , V_68 , V_90 + 12 , V_90 + 11 ,
* V_3 / 3 , 0 ) ;
if ( V_12 )
goto V_93;
break;
case 0x02000001 :
V_87 = true ;
break;
case 0x05000001 :
V_12 = F_40 ( V_67 , V_68 , V_90 + 3 , V_90 + 2 ,
* V_3 * 2 , 0 ) ;
if ( V_12 )
goto V_93;
break;
case 0x05000004 :
V_89 = F_41 ( V_67 , V_68 , V_90 + 4 ) ;
V_12 = F_40 ( V_67 , V_68 , V_90 + 3 , V_90 + 2 ,
V_89 , V_85 ) ;
if ( V_12 )
goto V_93;
break;
case 0x05000005 :
V_12 = F_40 ( V_67 , V_68 , V_90 + 3 , V_90 + 2 ,
4096 , V_84 ) ;
if ( V_12 )
goto V_93;
break;
default:
F_33 ( L_18 , V_92 ) ;
V_12 = - V_31 ;
goto V_93;
}
if ( V_86 == - 1 ) {
F_33 ( L_19 ) ;
V_12 = - V_31 ;
goto V_93;
}
V_90 += V_91 / 4 ;
}
if ( V_82 && ! V_88 ) {
F_33 ( L_20 ) ;
V_12 = - V_94 ;
}
V_93:
if ( ( ! V_12 && V_87 ) || ( V_12 && V_82 ) ) {
for ( V_11 = 0 ; V_11 < V_40 ; ++ V_11 )
F_45 ( & V_67 -> V_2 -> V_13 . V_41 [ V_11 ] , V_56 , 0 ) ;
}
return V_12 ;
}
bool F_47 ( struct V_55 * V_43 ,
struct V_95 * V_96 ,
bool V_97 )
{
T_2 V_77 = V_96 -> V_39 ;
F_48 ( V_43 , V_98 ) ;
F_48 ( V_43 , ( V_77 >> 3 ) & 0x000FFFFF ) ;
F_48 ( V_43 , ( V_77 >> 23 ) & 0x000FFFFF ) ;
F_48 ( V_43 , 0x01003000 | ( V_97 ? 1 : 0 ) ) ;
if ( ! V_97 )
F_48 ( V_43 , V_99 ) ;
return true ;
}
void F_49 ( struct V_55 * V_43 , struct V_60 * V_61 )
{
F_48 ( V_43 , V_100 ) ;
F_48 ( V_43 , F_50 ( V_61 -> V_39 ) ) ;
F_48 ( V_43 , F_36 ( V_61 -> V_39 ) ) ;
F_48 ( V_43 , V_61 -> V_63 ) ;
}
void F_51 ( struct V_55 * V_43 , T_3 V_77 , T_3 V_101 ,
unsigned V_102 )
{
F_52 ( V_102 & V_103 ) ;
F_48 ( V_43 , V_104 ) ;
F_48 ( V_43 , V_77 ) ;
F_48 ( V_43 , F_36 ( V_77 ) ) ;
F_48 ( V_43 , V_101 ) ;
F_48 ( V_43 , V_105 ) ;
F_48 ( V_43 , V_99 ) ;
}
int F_53 ( struct V_55 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
T_1 V_106 = F_54 ( V_43 ) ;
unsigned V_11 ;
int V_12 ;
V_12 = F_55 ( V_43 , 16 ) ;
if ( V_12 ) {
F_33 ( L_21 ,
V_43 -> V_90 , V_12 ) ;
return V_12 ;
}
F_48 ( V_43 , V_99 ) ;
F_56 ( V_43 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_107 ; V_11 ++ ) {
if ( F_54 ( V_43 ) != V_106 )
break;
F_57 ( 1 ) ;
}
if ( V_11 < V_2 -> V_107 ) {
F_9 ( L_22 ,
V_43 -> V_90 , V_11 ) ;
} else {
F_33 ( L_23 ,
V_43 -> V_90 ) ;
V_12 = - V_108 ;
}
return V_12 ;
}
int F_58 ( struct V_55 * V_43 )
{
struct V_57 * V_58 = NULL ;
int V_12 ;
V_12 = F_34 ( V_43 , 1 , NULL ) ;
if ( V_12 ) {
F_33 ( L_24 , V_12 ) ;
goto error;
}
V_12 = F_32 ( V_43 , 1 , & V_58 ) ;
if ( V_12 ) {
F_33 ( L_25 , V_12 ) ;
goto error;
}
V_12 = F_59 ( V_58 , false ) ;
if ( V_12 ) {
F_33 ( L_26 , V_12 ) ;
} else {
F_9 ( L_27 , V_43 -> V_90 ) ;
}
error:
F_60 ( & V_58 ) ;
return V_12 ;
}
