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
case V_21 :
V_6 = V_22 ;
break;
default:
return - V_23 ;
}
V_12 = F_3 ( & V_2 -> V_24 , V_6 , V_2 -> V_25 ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_25 , L_3 ,
V_6 ) ;
return V_12 ;
}
V_5 = V_2 -> V_24 -> V_5 - strlen ( V_3 ) - 9 ;
V_7 = V_2 -> V_24 -> V_26 ;
for (; V_5 > 0 ; -- V_5 , ++ V_7 )
if ( strncmp ( V_7 , V_3 , strlen ( V_3 ) ) == 0 )
break;
if ( V_5 == 0 )
return - V_23 ;
V_7 += strlen ( V_3 ) ;
if ( sscanf ( V_7 , L_4 , & V_8 , & V_9 , & V_10 ) != 3 )
return - V_23 ;
V_5 = V_2 -> V_24 -> V_5 - strlen ( V_4 ) - 3 ;
V_7 = V_2 -> V_24 -> V_26 ;
for (; V_5 > 0 ; -- V_5 , ++ V_7 )
if ( strncmp ( V_7 , V_4 , strlen ( V_4 ) ) == 0 )
break;
if ( V_5 == 0 )
return - V_23 ;
V_7 += strlen ( V_4 ) ;
if ( sscanf ( V_7 , L_5 , & V_2 -> V_13 . V_4 ) != 1 )
return - V_23 ;
F_5 ( L_6 ,
V_8 , V_9 , V_10 , V_2 -> V_13 . V_4 ) ;
V_2 -> V_13 . V_3 = ( V_8 << 24 ) | ( V_9 << 16 ) | ( V_10 << 8 ) ;
if ( V_2 -> V_13 . V_3 != ( ( 40 << 24 ) | ( 2 << 16 ) | ( 2 << 8 ) ) )
return - V_23 ;
V_5 = F_6 ( V_2 -> V_24 -> V_5 ) +
V_27 + V_28 ;
V_12 = F_7 ( V_2 , V_5 , V_29 , true ,
V_30 , 0 , NULL , NULL ,
& V_2 -> V_13 . V_31 ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_25 , L_7 , V_12 ) ;
return V_12 ;
}
V_12 = F_8 ( V_2 -> V_13 . V_31 , false ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_13 . V_31 ) ;
F_4 ( V_2 -> V_25 , L_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_10 ( V_2 -> V_13 . V_31 , V_30 ,
& V_2 -> V_13 . V_32 ) ;
F_11 ( V_2 -> V_13 . V_31 ) ;
if ( V_12 ) {
F_9 ( & V_2 -> V_13 . V_31 ) ;
F_4 ( V_2 -> V_25 , L_9 , V_12 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 ) {
F_12 ( & V_2 -> V_13 . V_34 [ V_11 ] , 0 ) ;
V_2 -> V_13 . V_35 [ V_11 ] = NULL ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_31 == NULL )
return;
F_9 ( & V_2 -> V_13 . V_31 ) ;
F_14 ( V_2 -> V_24 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_13 . V_31 == NULL )
return 0 ;
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 )
if ( F_16 ( & V_2 -> V_13 . V_34 [ V_11 ] ) )
break;
if ( V_11 == V_33 )
return 0 ;
return - V_23 ;
}
int F_17 ( struct V_1 * V_2 )
{
void * V_36 ;
int V_12 ;
if ( V_2 -> V_13 . V_31 == NULL )
return - V_23 ;
V_12 = F_8 ( V_2 -> V_13 . V_31 , false ) ;
if ( V_12 ) {
F_4 ( V_2 -> V_25 , L_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_18 ( V_2 -> V_13 . V_31 , & V_36 ) ;
if ( V_12 ) {
F_11 ( V_2 -> V_13 . V_31 ) ;
F_4 ( V_2 -> V_25 , L_10 , V_12 ) ;
return V_12 ;
}
memcpy ( V_36 , V_2 -> V_24 -> V_26 , V_2 -> V_24 -> V_5 ) ;
F_19 ( V_2 -> V_13 . V_31 ) ;
F_11 ( V_2 -> V_13 . V_31 ) ;
return 0 ;
}
static void V_15 ( struct V_37 * V_38 )
{
struct V_1 * V_2 =
F_20 ( V_38 , struct V_1 , V_13 . V_14 . V_38 ) ;
if ( ( F_21 ( V_2 , V_39 ) == 0 ) &&
( F_21 ( V_2 , V_40 ) == 0 ) ) {
if ( ( V_2 -> V_41 . V_42 == V_43 ) && V_2 -> V_41 . V_44 ) {
F_22 ( V_2 , false ) ;
} else {
F_23 ( V_2 , 0 , 0 ) ;
}
} else {
F_24 ( & V_2 -> V_13 . V_14 ,
F_25 ( V_45 ) ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
bool V_46 = false ;
bool V_47 = ! F_27 ( & V_2 -> V_13 . V_14 ) ;
V_47 &= F_24 ( & V_2 -> V_13 . V_14 ,
F_25 ( V_45 ) ) ;
if ( ( V_2 -> V_41 . V_42 == V_43 ) && V_2 -> V_41 . V_44 ) {
V_46 = false ;
}
if ( V_47 || V_46 ) {
if ( ( V_2 -> V_41 . V_42 == V_43 ) && V_2 -> V_41 . V_44 ) {
F_22 ( V_2 , true ) ;
} else {
F_23 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_28 ( struct V_1 * V_2 , struct V_48 * V_35 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 ) {
T_2 V_49 = F_16 ( & V_2 -> V_13 . V_34 [ V_11 ] ) ;
if ( ! V_49 || V_2 -> V_13 . V_35 [ V_11 ] != V_35 )
continue;
F_26 ( V_2 ) ;
V_12 = F_29 ( V_2 , V_39 ,
V_49 , NULL ) ;
if ( V_12 )
F_30 ( L_11 , V_12 ) ;
V_2 -> V_13 . V_35 [ V_11 ] = NULL ;
F_12 ( & V_2 -> V_13 . V_34 [ V_11 ] , 0 ) ;
}
}
int F_31 ( struct V_1 * V_2 , int V_50 ,
T_2 V_49 , struct V_51 * * V_52 )
{
const unsigned V_53 = 1024 ;
struct V_54 V_55 ;
T_3 V_56 ;
int V_11 , V_12 ;
V_12 = F_32 ( V_2 , V_50 , & V_55 , NULL , V_53 * 4 ) ;
if ( V_12 ) {
F_30 ( L_12 , V_12 ) ;
return V_12 ;
}
V_56 = V_55 . V_32 + 1024 ;
V_55 . V_57 = 0 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x0000000c ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000001 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = V_49 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000030 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x01000001 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000000 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000042 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x0000000a ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000001 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000080 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000060 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000100 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000100 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x0000000c ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000000 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000014 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x05000005 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = F_33 ( V_56 ) ;
V_55 . V_58 [ V_55 . V_57 ++ ] = V_56 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000001 ;
for ( V_11 = V_55 . V_57 ; V_11 < V_53 ; ++ V_11 )
V_55 . V_58 [ V_11 ] = 0x0 ;
V_12 = F_34 ( V_2 , & V_55 , NULL , false ) ;
if ( V_12 ) {
F_30 ( L_13 , V_12 ) ;
}
if ( V_52 )
* V_52 = F_35 ( V_55 . V_52 ) ;
F_36 ( V_2 , & V_55 ) ;
return V_12 ;
}
int F_29 ( struct V_1 * V_2 , int V_50 ,
T_2 V_49 , struct V_51 * * V_52 )
{
const unsigned V_53 = 1024 ;
struct V_54 V_55 ;
T_3 V_56 ;
int V_11 , V_12 ;
V_12 = F_32 ( V_2 , V_50 , & V_55 , NULL , V_53 * 4 ) ;
if ( V_12 ) {
F_30 ( L_12 , V_12 ) ;
return V_12 ;
}
V_56 = V_55 . V_32 + 1024 ;
V_55 . V_57 = 0 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x0000000c ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000001 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = V_49 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000014 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x05000005 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = F_33 ( V_56 ) ;
V_55 . V_58 [ V_55 . V_57 ++ ] = V_56 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000001 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x00000008 ;
V_55 . V_58 [ V_55 . V_57 ++ ] = 0x02000001 ;
for ( V_11 = V_55 . V_57 ; V_11 < V_53 ; ++ V_11 )
V_55 . V_58 [ V_11 ] = 0x0 ;
V_12 = F_34 ( V_2 , & V_55 , NULL , false ) ;
if ( V_12 ) {
F_30 ( L_13 , V_12 ) ;
}
if ( V_52 )
* V_52 = F_35 ( V_55 . V_52 ) ;
F_36 ( V_2 , & V_55 ) ;
return V_12 ;
}
int F_37 ( struct V_59 * V_60 , int V_61 , int V_62 ,
unsigned V_5 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_8 , V_10 , V_67 ;
unsigned V_68 ;
V_64 = & V_60 -> V_69 [ V_60 -> V_70 ] ;
V_67 = F_38 ( V_60 , V_61 ) ;
V_68 = F_38 ( V_60 , V_62 ) ;
if ( V_68 >= V_64 -> V_57 ) {
F_30 ( L_14 ,
V_68 , V_64 -> V_57 ) ;
return - V_23 ;
}
V_66 = V_60 -> V_71 [ ( V_68 / 4 ) ] ;
V_8 = V_66 -> V_72 ;
V_10 = V_8 + F_39 ( V_66 -> V_73 ) ;
V_8 += V_67 ;
V_60 -> V_55 . V_58 [ V_61 ] = V_8 & 0xFFFFFFFF ;
V_60 -> V_55 . V_58 [ V_62 ] = V_8 >> 32 ;
if ( V_10 <= V_8 ) {
F_30 ( L_15 , V_67 ) ;
return - V_23 ;
}
if ( ( V_10 - V_8 ) < V_5 ) {
F_30 ( L_16 ,
( unsigned ) ( V_10 - V_8 ) , V_5 ) ;
return - V_23 ;
}
return 0 ;
}
int F_40 ( struct V_59 * V_60 , T_2 V_49 )
{
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 ) {
if ( F_16 ( & V_60 -> V_2 -> V_13 . V_34 [ V_11 ] ) == V_49 )
return V_11 ;
}
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 ) {
if ( ! F_41 ( & V_60 -> V_2 -> V_13 . V_34 [ V_11 ] , 0 , V_49 ) ) {
V_60 -> V_2 -> V_13 . V_35 [ V_11 ] = V_60 -> V_35 ;
V_60 -> V_2 -> V_13 . V_74 [ V_11 ] = 0 ;
return V_11 ;
}
}
F_30 ( L_17 ) ;
return - V_23 ;
}
int F_42 ( struct V_59 * V_60 )
{
int V_75 = - 1 ;
bool V_76 = false ;
T_2 V_77 , V_49 = 0 ;
T_2 * V_5 = & V_77 ;
int V_11 , V_12 ;
while ( V_60 -> V_68 < V_60 -> V_69 [ V_60 -> V_78 ] . V_57 ) {
T_2 V_79 = F_38 ( V_60 , V_60 -> V_68 ) ;
T_2 V_80 = F_38 ( V_60 , V_60 -> V_68 + 1 ) ;
if ( ( V_79 < 8 ) || ( V_79 & 3 ) ) {
F_30 ( L_18 , V_79 ) ;
return - V_23 ;
}
if ( V_76 ) {
F_30 ( L_19 ) ;
return - V_23 ;
}
switch ( V_80 ) {
case 0x00000001 :
V_49 = F_38 ( V_60 , V_60 -> V_68 + 2 ) ;
V_75 = F_40 ( V_60 , V_49 ) ;
if ( V_75 < 0 )
return V_75 ;
V_5 = & V_60 -> V_2 -> V_13 . V_74 [ V_75 ] ;
break;
case 0x00000002 :
break;
case 0x01000001 :
* V_5 = F_38 ( V_60 , V_60 -> V_68 + 8 ) *
F_38 ( V_60 , V_60 -> V_68 + 10 ) *
8 * 3 / 2 ;
break;
case 0x04000001 :
case 0x04000002 :
case 0x04000005 :
case 0x04000007 :
case 0x04000008 :
break;
case 0x03000001 :
V_12 = F_37 ( V_60 , V_60 -> V_68 + 10 , V_60 -> V_68 + 9 ,
* V_5 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_60 , V_60 -> V_68 + 12 , V_60 -> V_68 + 11 ,
* V_5 / 3 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x02000001 :
V_76 = true ;
break;
case 0x05000001 :
V_12 = F_37 ( V_60 , V_60 -> V_68 + 3 , V_60 -> V_68 + 2 ,
* V_5 * 2 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x05000004 :
V_77 = F_38 ( V_60 , V_60 -> V_68 + 4 ) ;
V_12 = F_37 ( V_60 , V_60 -> V_68 + 3 , V_60 -> V_68 + 2 ,
V_77 ) ;
if ( V_12 )
return V_12 ;
break;
case 0x05000005 :
V_12 = F_37 ( V_60 , V_60 -> V_68 + 3 , V_60 -> V_68 + 2 ,
4096 ) ;
if ( V_12 )
return V_12 ;
break;
default:
F_30 ( L_20 , V_80 ) ;
return - V_23 ;
}
if ( V_75 == - 1 ) {
F_30 ( L_21 ) ;
return - V_23 ;
}
V_60 -> V_68 += V_79 / 4 ;
}
if ( V_76 ) {
for ( V_11 = 0 ; V_11 < V_33 ; ++ V_11 )
F_41 ( & V_60 -> V_2 -> V_13 . V_34 [ V_11 ] , V_49 , 0 ) ;
}
return 0 ;
}
bool F_43 ( struct V_1 * V_2 ,
struct V_81 * V_50 ,
struct V_82 * V_83 ,
bool V_84 )
{
T_3 V_85 = V_83 -> V_32 ;
F_44 ( V_50 , V_86 ) ;
F_44 ( V_50 , ( V_85 >> 3 ) & 0x000FFFFF ) ;
F_44 ( V_50 , ( V_85 >> 23 ) & 0x000FFFFF ) ;
F_44 ( V_50 , 0x01003000 | ( V_84 ? 1 : 0 ) ) ;
if ( ! V_84 )
F_44 ( V_50 , V_87 ) ;
return true ;
}
void F_45 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_81 * V_50 = & V_2 -> V_50 [ V_55 -> V_50 ] ;
F_44 ( V_50 , V_88 ) ;
F_44 ( V_50 , V_55 -> V_32 ) ;
F_44 ( V_50 , F_33 ( V_55 -> V_32 ) ) ;
F_44 ( V_50 , V_55 -> V_57 ) ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_81 * V_50 = & V_2 -> V_50 [ V_52 -> V_50 ] ;
T_3 V_85 = V_2 -> V_89 [ V_52 -> V_50 ] . V_32 ;
F_44 ( V_50 , V_90 ) ;
F_44 ( V_50 , V_85 ) ;
F_44 ( V_50 , F_33 ( V_85 ) ) ;
F_44 ( V_50 , V_52 -> V_91 ) ;
F_44 ( V_50 , V_92 ) ;
F_44 ( V_50 , V_87 ) ;
}
int F_47 ( struct V_1 * V_2 , struct V_81 * V_50 )
{
T_2 V_93 = F_48 ( V_2 , V_50 ) ;
unsigned V_11 ;
int V_12 ;
V_12 = F_49 ( V_2 , V_50 , 16 ) ;
if ( V_12 ) {
F_30 ( L_22 ,
V_50 -> V_68 , V_12 ) ;
return V_12 ;
}
F_44 ( V_50 , V_87 ) ;
F_50 ( V_2 , V_50 , false ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_94 ; V_11 ++ ) {
if ( F_48 ( V_2 , V_50 ) != V_93 )
break;
F_51 ( 1 ) ;
}
if ( V_11 < V_2 -> V_94 ) {
F_5 ( L_23 ,
V_50 -> V_68 , V_11 ) ;
} else {
F_30 ( L_24 ,
V_50 -> V_68 ) ;
V_12 = - V_95 ;
}
return V_12 ;
}
int F_52 ( struct V_1 * V_2 , struct V_81 * V_50 )
{
struct V_51 * V_52 = NULL ;
int V_12 ;
V_12 = F_31 ( V_2 , V_50 -> V_68 , 1 , NULL ) ;
if ( V_12 ) {
F_30 ( L_25 , V_12 ) ;
goto error;
}
V_12 = F_29 ( V_2 , V_50 -> V_68 , 1 , & V_52 ) ;
if ( V_12 ) {
F_30 ( L_26 , V_12 ) ;
goto error;
}
V_12 = F_53 ( V_52 , false ) ;
if ( V_12 ) {
F_30 ( L_27 , V_12 ) ;
} else {
F_5 ( L_28 , V_50 -> V_68 ) ;
}
error:
F_54 ( & V_52 ) ;
return V_12 ;
}
