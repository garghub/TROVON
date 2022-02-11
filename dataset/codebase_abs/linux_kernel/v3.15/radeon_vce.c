int F_1 ( struct V_1 * V_2 )
{
static const char * V_3 = L_1 ;
static const char * V_4 = L_2 ;
unsigned long V_5 ;
const char * V_6 , * V_7 ;
T_1 V_8 , V_9 , V_10 ;
int V_11 , V_12 ;
F_2 ( & V_2 -> V_13 . V_14 , V_15 ) ;
switch ( V_2 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
V_6 = V_21 ;
break;
default:
return - V_22 ;
}
V_12 = F_3 ( & V_2 -> V_23 , V_6 , V_2 -> V_24 ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_24 , L_3 ,
V_6 ) ;
return V_12 ;
}
V_5 = V_2 -> V_23 -> V_5 - strlen ( V_3 ) - 9 ;
V_7 = V_2 -> V_23 -> V_25 ;
for (; V_5 > 0 ; -- V_5 , ++ V_7 )
if ( strncmp ( V_7 , V_3 , strlen ( V_3 ) ) == 0 )
break;
if ( V_5 == 0 )
return - V_22 ;
V_7 += strlen ( V_3 ) ;
if ( sscanf ( V_7 , L_4 , & V_8 , & V_9 , & V_10 ) != 3 )
return - V_22 ;
V_5 = V_2 -> V_23 -> V_5 - strlen ( V_4 ) - 3 ;
V_7 = V_2 -> V_23 -> V_25 ;
for (; V_5 > 0 ; -- V_5 , ++ V_7 )
if ( strncmp ( V_7 , V_4 , strlen ( V_4 ) ) == 0 )
break;
if ( V_5 == 0 )
return - V_22 ;
V_7 += strlen ( V_4 ) ;
if ( sscanf ( V_7 , L_5 , & V_2 -> V_13 . V_4 ) != 1 )
return - V_22 ;
F_5 ( L_6 ,
V_8 , V_9 , V_10 , V_2 -> V_13 . V_4 ) ;
V_2 -> V_13 . V_3 = ( V_8 << 24 ) | ( V_9 << 16 ) | ( V_10 << 8 ) ;
if ( V_2 -> V_13 . V_3 != ( ( 40 << 24 ) | ( 2 << 16 ) | ( 2 << 8 ) ) )
return - V_22 ;
V_5 = F_6 ( V_2 -> V_23 -> V_5 ) +
V_26 + V_27 ;
V_12 = F_7 ( V_2 , V_5 , V_28 , true ,
V_29 , NULL , & V_2 -> V_13 . V_30 ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_24 , L_7 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_2 -> V_13 . V_30 , false ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_13 . V_30 ) ;
F_4 ( V_2 -> V_24 , L_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_10 ( V_2 -> V_13 . V_30 , V_29 ,
& V_2 -> V_13 . V_31 ) ;
F_11 ( V_2 -> V_13 . V_30 ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_13 . V_30 ) ;
F_4 ( V_2 -> V_24 , L_9 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 ) {
F_12 ( & V_2 -> V_13 . V_33 [ V_11 ] , 0 ) ;
V_2 -> V_13 . V_34 [ V_11 ] = NULL ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_30 == NULL )
return;
F_9 ( & V_2 -> V_13 . V_30 ) ;
F_14 ( V_2 -> V_23 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_13 . V_30 == NULL )
return 0 ;
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 )
if ( F_16 ( & V_2 -> V_13 . V_33 [ V_11 ] ) )
break;
if ( V_11 == V_32 )
return 0 ;
return - V_22 ;
}
int F_17 ( struct V_1 * V_2 )
{
void * V_35 ;
int V_12 ;
if ( V_2 -> V_13 . V_30 == NULL )
return - V_22 ;
V_12 = F_8 ( V_2 -> V_13 . V_30 , false ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_24 , L_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_18 ( V_2 -> V_13 . V_30 , & V_35 ) ;
if ( V_12 ) {
F_11 ( V_2 -> V_13 . V_30 ) ;
F_4 ( V_2 -> V_24 , L_10 , V_12 ) ;
return V_12 ;
}
memcpy ( V_35 , V_2 -> V_23 -> V_25 , V_2 -> V_23 -> V_5 ) ;
F_19 ( V_2 -> V_13 . V_30 ) ;
F_11 ( V_2 -> V_13 . V_30 ) ;
return 0 ;
}
static void V_15 ( struct V_36 * V_37 )
{
struct V_1 * V_2 =
F_20 ( V_37 , struct V_1 , V_13 . V_14 . V_37 ) ;
if ( ( F_21 ( V_2 , V_38 ) == 0 ) &&
( F_21 ( V_2 , V_39 ) == 0 ) ) {
if ( ( V_2 -> V_40 . V_41 == V_42 ) && V_2 -> V_40 . V_43 ) {
F_22 ( V_2 , false ) ;
} else {
F_23 ( V_2 , 0 , 0 ) ;
}
} else {
F_24 ( & V_2 -> V_13 . V_14 ,
F_25 ( V_44 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
bool V_45 = false ;
bool V_46 = ! F_27 ( & V_2 -> V_13 . V_14 ) ;
V_46 &= F_24 ( & V_2 -> V_13 . V_14 ,
F_25 ( V_44 ) ) ;
if ( ( V_2 -> V_40 . V_41 == V_42 ) && V_2 -> V_40 . V_43 ) {
V_45 = false ;
}
if ( V_46 || V_45 ) {
if ( ( V_2 -> V_40 . V_41 == V_42 ) && V_2 -> V_40 . V_43 ) {
F_22 ( V_2 , true ) ;
} else {
F_23 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_28 ( struct V_1 * V_2 , struct V_47 * V_34 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 ) {
T_2 V_48 = F_16 ( & V_2 -> V_13 . V_33 [ V_11 ] ) ;
if ( ! V_48 || V_2 -> V_13 . V_34 [ V_11 ] != V_34 )
continue;
F_26 ( V_2 ) ;
V_12 = F_29 ( V_2 , V_38 ,
V_48 , NULL ) ;
if ( V_12 )
F_30 ( L_11 , V_12 ) ;
V_2 -> V_13 . V_34 [ V_11 ] = NULL ;
F_12 ( & V_2 -> V_13 . V_33 [ V_11 ] , 0 ) ;
}
}
int F_31 ( struct V_1 * V_2 , int V_49 ,
T_2 V_48 , struct V_50 * * V_51 )
{
const unsigned V_52 = 1024 ;
struct V_53 V_54 ;
T_3 V_55 ;
int V_11 , V_12 ;
V_12 = F_32 ( V_2 , V_49 , & V_54 , NULL , V_52 * 4 ) ;
if ( V_12 ) {
F_30 ( L_12 , V_12 ) ;
return V_12 ;
}
V_55 = V_54 . V_31 + 1024 ;
V_54 . V_56 = 0 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x0000000c ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000001 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = V_48 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000030 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x01000001 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000000 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000042 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x0000000a ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000001 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000080 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000060 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000100 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000100 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x0000000c ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000000 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000014 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x05000005 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = F_33 ( V_55 ) ;
V_54 . V_57 [ V_54 . V_56 ++ ] = V_55 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000001 ;
for ( V_11 = V_54 . V_56 ; V_11 < V_52 ; ++ V_11 )
V_54 . V_57 [ V_11 ] = 0x0 ;
V_12 = F_34 ( V_2 , & V_54 , NULL ) ;
if ( V_12 ) {
F_30 ( L_13 , V_12 ) ;
}
if ( V_51 )
* V_51 = F_35 ( V_54 . V_51 ) ;
F_36 ( V_2 , & V_54 ) ;
return V_12 ;
}
int F_29 ( struct V_1 * V_2 , int V_49 ,
T_2 V_48 , struct V_50 * * V_51 )
{
const unsigned V_52 = 1024 ;
struct V_53 V_54 ;
T_3 V_55 ;
int V_11 , V_12 ;
V_12 = F_32 ( V_2 , V_49 , & V_54 , NULL , V_52 * 4 ) ;
if ( V_12 ) {
F_30 ( L_12 , V_12 ) ;
return V_12 ;
}
V_55 = V_54 . V_31 + 1024 ;
V_54 . V_56 = 0 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x0000000c ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000001 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = V_48 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000014 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x05000005 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = F_33 ( V_55 ) ;
V_54 . V_57 [ V_54 . V_56 ++ ] = V_55 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000001 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x00000008 ;
V_54 . V_57 [ V_54 . V_56 ++ ] = 0x02000001 ;
for ( V_11 = V_54 . V_56 ; V_11 < V_52 ; ++ V_11 )
V_54 . V_57 [ V_11 ] = 0x0 ;
V_12 = F_34 ( V_2 , & V_54 , NULL ) ;
if ( V_12 ) {
F_30 ( L_13 , V_12 ) ;
}
if ( V_51 )
* V_51 = F_35 ( V_54 . V_51 ) ;
F_36 ( V_2 , & V_54 ) ;
return V_12 ;
}
int F_37 ( struct V_58 * V_59 , int V_60 , int V_61 ,
unsigned V_5 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_3 V_8 , V_10 , V_66 ;
unsigned V_67 ;
V_63 = & V_59 -> V_68 [ V_59 -> V_69 ] ;
V_66 = F_38 ( V_59 , V_60 ) ;
V_67 = F_38 ( V_59 , V_61 ) ;
if ( V_67 >= V_63 -> V_56 ) {
F_30 ( L_14 ,
V_67 , V_63 -> V_56 ) ;
return - V_22 ;
}
V_65 = V_59 -> V_70 [ ( V_67 / 4 ) ] ;
V_8 = V_65 -> V_71 ;
V_10 = V_8 + F_39 ( V_65 -> V_72 ) ;
V_8 += V_66 ;
V_59 -> V_54 . V_57 [ V_60 ] = V_8 & 0xFFFFFFFF ;
V_59 -> V_54 . V_57 [ V_61 ] = V_8 >> 32 ;
if ( V_10 <= V_8 ) {
F_30 ( L_15 , V_66 ) ;
return - V_22 ;
}
if ( ( V_10 - V_8 ) < V_5 ) {
F_30 ( L_16 ,
( unsigned ) ( V_10 - V_8 ) , V_5 ) ;
return - V_22 ;
}
return 0 ;
}
int F_40 ( struct V_58 * V_59 , T_2 V_48 )
{
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 ) {
if ( F_16 ( & V_59 -> V_2 -> V_13 . V_33 [ V_11 ] ) == V_48 )
return V_11 ;
}
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 ) {
if ( ! F_41 ( & V_59 -> V_2 -> V_13 . V_33 [ V_11 ] , 0 , V_48 ) ) {
V_59 -> V_2 -> V_13 . V_34 [ V_11 ] = V_59 -> V_34 ;
V_59 -> V_2 -> V_13 . V_73 [ V_11 ] = 0 ;
return V_11 ;
}
}
F_30 ( L_17 ) ;
return - V_22 ;
}
int F_42 ( struct V_58 * V_59 )
{
int V_74 = - 1 ;
bool V_75 = false ;
T_2 V_76 , V_48 = 0 ;
T_2 * V_5 = & V_76 ;
int V_11 , V_12 ;
while ( V_59 -> V_67 < V_59 -> V_68 [ V_59 -> V_77 ] . V_56 ) {
T_2 V_78 = F_38 ( V_59 , V_59 -> V_67 ) ;
T_2 V_79 = F_38 ( V_59 , V_59 -> V_67 + 1 ) ;
if ( ( V_78 < 8 ) || ( V_78 & 3 ) ) {
F_30 ( L_18 , V_78 ) ;
return - V_22 ;
}
if ( V_75 ) {
F_30 ( L_19 ) ;
return - V_22 ;
}
switch ( V_79 ) {
case 0x00000001 :
V_48 = F_38 ( V_59 , V_59 -> V_67 + 2 ) ;
V_74 = F_40 ( V_59 , V_48 ) ;
if ( V_74 < 0 )
return V_74 ;
V_5 = & V_59 -> V_2 -> V_13 . V_73 [ V_74 ] ;
break;
case 0x00000002 :
break;
case 0x01000001 :
* V_5 = F_38 ( V_59 , V_59 -> V_67 + 8 ) *
F_38 ( V_59 , V_59 -> V_67 + 10 ) *
8 * 3 / 2 ;
break;
case 0x04000001 :
case 0x04000002 :
case 0x04000005 :
case 0x04000007 :
case 0x04000008 :
break;
case 0x03000001 :
V_12 = F_37 ( V_59 , V_59 -> V_67 + 10 , V_59 -> V_67 + 9 ,
* V_5 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_59 , V_59 -> V_67 + 12 , V_59 -> V_67 + 11 ,
* V_5 / 3 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x02000001 :
V_75 = true ;
break;
case 0x05000001 :
V_12 = F_37 ( V_59 , V_59 -> V_67 + 3 , V_59 -> V_67 + 2 ,
* V_5 * 2 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x05000004 :
V_76 = F_38 ( V_59 , V_59 -> V_67 + 4 ) ;
V_12 = F_37 ( V_59 , V_59 -> V_67 + 3 , V_59 -> V_67 + 2 ,
V_76 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x05000005 :
V_12 = F_37 ( V_59 , V_59 -> V_67 + 3 , V_59 -> V_67 + 2 ,
4096 ) ;
if ( V_12 )
return V_12 ;
break;
default:
F_30 ( L_20 , V_79 ) ;
return - V_22 ;
}
if ( V_74 == - 1 ) {
F_30 ( L_21 ) ;
return - V_22 ;
}
V_59 -> V_67 += V_78 / 4 ;
}
if ( V_75 ) {
for ( V_11 = 0 ; V_11 < V_32 ; ++ V_11 )
F_41 ( & V_59 -> V_2 -> V_13 . V_33 [ V_11 ] , V_48 , 0 ) ;
}
return 0 ;
}
bool F_43 ( struct V_1 * V_2 ,
struct V_80 * V_49 ,
struct V_81 * V_82 ,
bool V_83 )
{
T_3 V_84 = V_82 -> V_31 ;
F_44 ( V_49 , V_85 ) ;
F_44 ( V_49 , ( V_84 >> 3 ) & 0x000FFFFF ) ;
F_44 ( V_49 , ( V_84 >> 23 ) & 0x000FFFFF ) ;
F_44 ( V_49 , 0x01003000 | ( V_83 ? 1 : 0 ) ) ;
if ( ! V_83 )
F_44 ( V_49 , V_86 ) ;
return true ;
}
void F_45 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_80 * V_49 = & V_2 -> V_49 [ V_54 -> V_49 ] ;
F_44 ( V_49 , V_87 ) ;
F_44 ( V_49 , V_54 -> V_31 ) ;
F_44 ( V_49 , F_33 ( V_54 -> V_31 ) ) ;
F_44 ( V_49 , V_54 -> V_56 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_80 * V_49 = & V_2 -> V_49 [ V_51 -> V_49 ] ;
T_3 V_84 = V_2 -> V_88 [ V_51 -> V_49 ] . V_31 ;
F_44 ( V_49 , V_89 ) ;
F_44 ( V_49 , V_84 ) ;
F_44 ( V_49 , F_33 ( V_84 ) ) ;
F_44 ( V_49 , V_51 -> V_90 ) ;
F_44 ( V_49 , V_91 ) ;
F_44 ( V_49 , V_86 ) ;
}
int F_47 ( struct V_1 * V_2 , struct V_80 * V_49 )
{
T_2 V_92 = F_48 ( V_2 , V_49 ) ;
unsigned V_11 ;
int V_12 ;
V_12 = F_49 ( V_2 , V_49 , 16 ) ;
if ( V_12 ) {
F_30 ( L_22 ,
V_49 -> V_67 , V_12 ) ;
return V_12 ;
}
F_44 ( V_49 , V_86 ) ;
F_50 ( V_2 , V_49 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_93 ; V_11 ++ ) {
if ( F_48 ( V_2 , V_49 ) != V_92 )
break;
F_51 ( 1 ) ;
}
if ( V_11 < V_2 -> V_93 ) {
F_5 ( L_23 ,
V_49 -> V_67 , V_11 ) ;
} else {
F_30 ( L_24 ,
V_49 -> V_67 ) ;
V_12 = - V_94 ;
}
return V_12 ;
}
int F_52 ( struct V_1 * V_2 , struct V_80 * V_49 )
{
struct V_50 * V_51 = NULL ;
int V_12 ;
V_12 = F_31 ( V_2 , V_49 -> V_67 , 1 , NULL ) ;
if ( V_12 ) {
F_30 ( L_25 , V_12 ) ;
goto error;
}
V_12 = F_29 ( V_2 , V_49 -> V_67 , 1 , & V_51 ) ;
if ( V_12 ) {
F_30 ( L_26 , V_12 ) ;
goto error;
}
V_12 = F_53 ( V_51 , false ) ;
if ( V_12 ) {
F_30 ( L_27 , V_12 ) ;
} else {
F_5 ( L_28 , V_49 -> V_67 ) ;
}
error:
F_54 ( & V_51 ) ;
return V_12 ;
}
