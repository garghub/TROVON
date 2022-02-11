void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = 1 << V_2 -> V_11 . V_12 ;
V_4 -> V_13 = 0 ;
}
void F_3 ( struct V_1 * V_2 , struct V_14 * V_4 )
{
int V_5 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 -> V_8 [ V_5 ] = 0 ;
V_4 -> V_9 [ V_5 ] = 0 ;
}
V_4 -> V_10 = ( 1 << V_2 -> V_11 . V_16 ) - V_17 ;
V_4 -> V_13 = 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 , int * V_20 )
{
struct V_21 V_22 ;
T_1 V_23 [ 16 ] = { 0 } ;
T_3 V_24 ;
int V_25 ;
V_22 . V_20 = * V_20 ;
V_19 &= 0xffffffffffffULL ;
V_24 = F_5 ( V_19 << 16 ) ;
memcpy ( & V_23 [ 10 ] , & V_24 , V_26 ) ;
V_23 [ 5 ] = V_18 ;
V_25 = F_6 ( V_2 , & V_22 , V_23 , 0 , V_27 ) ;
if ( V_25 )
F_7 ( V_2 , L_1 ) ;
return V_25 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 , int V_20 )
{
struct V_21 V_22 ;
T_1 V_23 [ 16 ] = { 0 } ;
T_3 V_24 ;
V_22 . V_20 = V_20 ;
V_19 &= 0xffffffffffffULL ;
V_24 = F_5 ( V_19 << 16 ) ;
memcpy ( & V_23 [ 10 ] , & V_24 , V_26 ) ;
V_23 [ 5 ] = V_18 ;
F_9 ( V_2 , & V_22 , V_23 , V_27 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_28 )
{
int V_25 = 0 ;
if ( V_28 < 0 || V_28 >= V_4 -> V_10 || ! V_4 -> V_8 [ V_28 ] ) {
F_7 ( V_2 , L_2 ) ;
V_25 = - V_29 ;
}
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_19 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( ( V_19 & V_30 ) ==
( V_30 & F_12 ( V_4 -> V_8 [ V_5 ] ) ) )
return V_5 ;
}
return - V_29 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 , int * V_20 )
{
struct V_31 * V_32 = & F_14 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_33 * V_34 ;
int V_28 = 0 ;
int V_25 = 0 ;
F_15 ( V_2 , L_3 ,
( unsigned long long ) V_19 ) ;
V_28 = F_16 ( V_2 , V_18 , V_19 ) ;
if ( V_28 < 0 ) {
V_25 = V_28 ;
F_17 ( V_2 , L_4 ,
( unsigned long long ) V_19 ) ;
return V_25 ;
}
if ( ! ( V_2 -> V_11 . V_35 & V_36 ) ) {
* V_20 = V_32 -> V_37 + V_28 ;
return 0 ;
}
V_25 = F_18 ( V_2 , 1 , 1 , V_20 ) ;
F_15 ( V_2 , L_5 , * V_20 ) ;
if ( V_25 ) {
F_17 ( V_2 , L_6 ) ;
goto V_38;
}
V_25 = F_4 ( V_2 , V_18 , V_19 , V_20 ) ;
if ( V_25 )
goto V_39;
V_34 = F_19 ( sizeof *V_34 , V_40 ) ;
if ( ! V_34 ) {
V_25 = - V_41 ;
goto V_42;
}
V_34 -> V_19 = V_19 ;
V_25 = F_20 ( & V_32 -> V_43 , * V_20 , V_34 ) ;
if ( V_25 )
goto V_44;
return 0 ;
V_44:
F_21 ( V_34 ) ;
V_42:
F_8 ( V_2 , V_18 , V_19 , * V_20 ) ;
V_39:
F_22 ( V_2 , * V_20 , 1 ) ;
V_38:
F_23 ( V_2 , V_18 , V_19 ) ;
return V_25 ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 , int V_20 )
{
struct V_31 * V_32 = & F_14 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_33 * V_34 ;
F_15 ( V_2 , L_7 ,
( unsigned long long ) V_19 ) ;
F_23 ( V_2 , V_18 , V_19 ) ;
if ( V_2 -> V_11 . V_35 & V_36 ) {
V_34 = F_25 ( & V_32 -> V_43 , V_20 ) ;
if ( V_34 ) {
F_15 ( V_2 , L_8
L_9 , V_18 ,
( unsigned long long ) V_19 , V_20 ) ;
F_8 ( V_2 , V_18 , V_34 -> V_19 , V_20 ) ;
F_22 ( V_2 , V_20 , 1 ) ;
F_26 ( & V_32 -> V_43 , V_20 ) ;
F_21 ( V_34 ) ;
}
}
}
static int F_27 ( struct V_1 * V_2 , T_1 V_18 ,
T_3 * V_8 )
{
struct V_45 * V_46 ;
T_4 V_47 ;
int V_25 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
memcpy ( V_46 -> V_48 , V_8 , V_49 ) ;
V_47 = V_50 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_54 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
struct V_31 * V_32 = & F_14 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_32 -> V_55 ;
int V_5 , V_25 = 0 ;
int free = - 1 ;
F_15 ( V_2 , L_10 ,
( unsigned long long ) V_19 , V_18 ) ;
F_34 ( & V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( free < 0 && ! V_4 -> V_8 [ V_5 ] ) {
free = V_5 ;
continue;
}
if ( V_19 == ( V_30 & F_12 ( V_4 -> V_8 [ V_5 ] ) ) ) {
V_25 = - V_56 ;
goto V_57;
}
}
F_15 ( V_2 , L_11 , free ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_25 = - V_58 ;
goto V_57;
}
V_4 -> V_8 [ free ] = F_5 ( V_19 | V_59 ) ;
V_25 = F_27 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_35 ( V_25 ) ) {
F_17 ( V_2 , L_4 ,
( unsigned long long ) V_19 ) ;
V_4 -> V_8 [ free ] = 0 ;
goto V_57;
}
V_25 = free ;
++ V_4 -> V_13 ;
V_57:
F_36 ( & V_4 -> V_6 ) ;
return V_25 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
T_2 V_60 ;
int V_25 ;
if ( F_37 ( V_2 ) ) {
F_38 ( & V_60 , V_18 ) ;
V_25 = F_39 ( V_2 , V_19 , & V_60 , V_61 ,
V_62 , V_63 ,
V_64 , V_65 ) ;
if ( V_25 )
return V_25 ;
return F_40 ( & V_60 ) ;
}
return F_33 ( V_2 , V_18 , V_19 ) ;
}
void F_41 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
struct V_31 * V_32 = & F_14 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_32 -> V_55 ;
int V_28 ;
V_28 = F_11 ( V_2 , V_4 , V_19 ) ;
F_34 ( & V_4 -> V_6 ) ;
if ( F_10 ( V_2 , V_4 , V_28 ) )
goto V_57;
V_4 -> V_8 [ V_28 ] = 0 ;
F_27 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
V_57:
F_36 ( & V_4 -> V_6 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
T_2 V_60 ;
if ( F_37 ( V_2 ) ) {
F_38 ( & V_60 , V_18 ) ;
( void ) F_39 ( V_2 , V_19 , & V_60 , V_61 ,
V_62 , V_66 ,
V_64 , V_65 ) ;
return;
}
F_41 ( V_2 , V_18 , V_19 ) ;
return;
}
int F_42 ( struct V_1 * V_2 , T_1 V_18 , int V_20 , T_2 V_67 )
{
struct V_31 * V_32 = & F_14 ( V_2 ) -> V_18 [ V_18 ] ;
struct V_3 * V_4 = & V_32 -> V_55 ;
struct V_33 * V_34 ;
int V_28 = V_20 - V_32 -> V_37 ;
int V_25 = 0 ;
if ( V_2 -> V_11 . V_35 & V_36 ) {
V_34 = F_25 ( & V_32 -> V_43 , V_20 ) ;
if ( ! V_34 )
return - V_29 ;
F_8 ( V_2 , V_18 , V_34 -> V_19 , V_20 ) ;
F_23 ( V_2 , V_18 , V_34 -> V_19 ) ;
V_34 -> V_19 = V_67 ;
F_16 ( V_2 , V_18 , V_67 ) ;
V_25 = F_4 ( V_2 , V_18 , V_34 -> V_19 , & V_20 ) ;
return V_25 ;
}
F_34 ( & V_4 -> V_6 ) ;
V_25 = F_10 ( V_2 , V_4 , V_28 ) ;
if ( V_25 )
goto V_57;
V_4 -> V_8 [ V_28 ] = F_5 ( V_67 | V_59 ) ;
V_25 = F_27 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_35 ( V_25 ) ) {
F_17 ( V_2 , L_4 ,
( unsigned long long ) V_67 ) ;
V_4 -> V_8 [ V_28 ] = 0 ;
}
V_57:
F_36 ( & V_4 -> V_6 ) ;
return V_25 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_18 ,
T_5 * V_8 )
{
struct V_45 * V_46 ;
T_4 V_47 ;
int V_25 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
memcpy ( V_46 -> V_48 , V_8 , V_68 ) ;
V_47 = V_69 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_65 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_70 , int * V_71 )
{
struct V_14 * V_4 = & F_14 ( V_2 ) -> V_18 [ V_18 ] . V_72 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_15 ; ++ V_5 ) {
if ( V_4 -> V_9 [ V_5 ] &&
( V_70 == ( V_73 &
F_45 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_71 = V_5 ;
return 0 ;
}
}
return - V_74 ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_75 ,
int * V_28 )
{
struct V_14 * V_4 = & F_14 ( V_2 ) -> V_18 [ V_18 ] . V_72 ;
int V_5 , V_25 = 0 ;
int free = - 1 ;
F_34 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_13 == V_4 -> V_10 ) {
V_25 = - V_58 ;
goto V_57;
}
for ( V_5 = V_17 ; V_5 < V_15 ; V_5 ++ ) {
if ( free < 0 && ( V_4 -> V_9 [ V_5 ] == 0 ) ) {
free = V_5 ;
continue;
}
if ( V_4 -> V_9 [ V_5 ] &&
( V_75 == ( V_73 &
F_45 ( V_4 -> V_8 [ V_5 ] ) ) ) ) {
* V_28 = V_5 ;
++ V_4 -> V_9 [ V_5 ] ;
goto V_57;
}
}
if ( free < 0 ) {
V_25 = - V_41 ;
goto V_57;
}
V_4 -> V_9 [ free ] = 1 ;
V_4 -> V_8 [ free ] = F_47 ( V_75 | V_76 ) ;
V_25 = F_43 ( V_2 , V_18 , V_4 -> V_8 ) ;
if ( F_35 ( V_25 ) ) {
F_7 ( V_2 , L_12 , V_75 ) ;
V_4 -> V_9 [ free ] = 0 ;
V_4 -> V_8 [ free ] = 0 ;
goto V_57;
}
* V_28 = free ;
++ V_4 -> V_13 ;
V_57:
F_36 ( & V_4 -> V_6 ) ;
return V_25 ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_18 , T_6 V_75 , int * V_28 )
{
T_2 V_60 ;
int V_25 ;
if ( F_37 ( V_2 ) ) {
F_38 ( & V_60 , V_18 ) ;
V_25 = F_39 ( V_2 , V_75 , & V_60 , V_77 ,
V_62 , V_63 ,
V_64 , V_65 ) ;
if ( ! V_25 )
* V_28 = F_40 ( & V_60 ) ;
return V_25 ;
}
return F_46 ( V_2 , V_18 , V_75 , V_28 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_18 , int V_28 )
{
struct V_14 * V_4 = & F_14 ( V_2 ) -> V_18 [ V_18 ] . V_72 ;
if ( V_28 < V_17 ) {
F_7 ( V_2 , L_13 , V_28 ) ;
return;
}
F_34 ( & V_4 -> V_6 ) ;
if ( ! V_4 -> V_9 [ V_28 ] ) {
F_7 ( V_2 , L_14 , V_28 ) ;
goto V_57;
}
if ( -- V_4 -> V_9 [ V_28 ] ) {
F_15 ( V_2 , L_15
L_16 , V_28 ) ;
goto V_57;
}
V_4 -> V_8 [ V_28 ] = 0 ;
F_43 ( V_2 , V_18 , V_4 -> V_8 ) ;
-- V_4 -> V_13 ;
V_57:
F_36 ( & V_4 -> V_6 ) ;
}
void F_50 ( struct V_1 * V_2 , T_1 V_18 , int V_28 )
{
T_2 V_78 ;
int V_25 ;
if ( F_37 ( V_2 ) ) {
F_38 ( & V_78 , V_18 ) ;
V_25 = F_31 ( V_2 , V_78 , V_77 , V_62 ,
V_66 , V_64 ,
V_65 ) ;
if ( ! V_25 )
F_7 ( V_2 , L_17 ,
V_28 ) ;
return;
}
F_49 ( V_2 , V_18 , V_28 ) ;
}
int F_51 ( struct V_1 * V_2 , T_1 V_18 , T_5 * V_11 )
{
struct V_45 * V_79 , * V_80 ;
T_1 * V_81 , * V_82 ;
int V_25 ;
V_79 = F_28 ( V_2 ) ;
if ( F_29 ( V_79 ) )
return F_30 ( V_79 ) ;
V_80 = F_28 ( V_2 ) ;
if ( F_29 ( V_80 ) ) {
F_32 ( V_2 , V_79 ) ;
return F_30 ( V_80 ) ;
}
V_81 = V_79 -> V_48 ;
V_82 = V_80 -> V_48 ;
memset ( V_81 , 0 , 256 ) ;
memset ( V_82 , 0 , 256 ) ;
V_81 [ 0 ] = 1 ;
V_81 [ 1 ] = 1 ;
V_81 [ 2 ] = 1 ;
V_81 [ 3 ] = 1 ;
* ( V_83 * ) ( & V_81 [ 16 ] ) = F_52 ( 0x0015 ) ;
* ( T_5 * ) ( & V_81 [ 20 ] ) = F_47 ( V_18 ) ;
V_25 = F_53 ( V_2 , V_79 -> V_51 , V_80 -> V_51 , V_18 , 3 ,
V_84 , V_85 ,
V_54 ) ;
if ( ! V_25 )
* V_11 = * ( T_5 * ) ( V_82 + 84 ) ;
F_32 ( V_2 , V_79 ) ;
F_32 ( V_2 , V_80 ) ;
return V_25 ;
}
static int F_54 ( struct V_1 * V_2 , int V_86 , T_4 V_47 ,
T_1 V_87 , struct V_45 * V_88 )
{
struct F_14 * V_89 = F_14 ( V_2 ) ;
struct V_31 * V_90 ;
struct V_91 * V_92 = & V_89 -> V_93 . V_92 ;
struct V_94 * V_95 = & V_92 -> V_96 [ V_86 ] ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_101 ;
int V_18 ;
int V_102 ;
T_4 V_103 ;
T_4 V_104 ;
T_6 V_105 , V_106 ;
int V_25 ;
int V_5 ;
T_5 V_107 ;
T_5 V_108 ;
T_5 V_109 ;
V_18 = V_47 & 0xff ;
V_103 = V_47 >> 8 ;
V_102 = V_87 ;
V_90 = & V_89 -> V_18 [ V_18 ] ;
if ( V_102 ) {
if ( V_86 != V_2 -> V_11 . V_110 &&
V_103 != V_111 ) {
F_7 ( V_2 , L_18 ,
V_86 ) ;
return - V_29 ;
}
switch ( V_103 ) {
case V_112 :
V_98 = V_88 -> V_48 ;
V_98 -> V_37 =
F_47 ( V_90 -> V_37 ) ;
V_98 -> V_113 = 0x7 ;
V_104 = F_45 ( V_98 -> V_104 ) >>
V_114 ;
V_98 -> V_104 = F_47 (
V_104 << V_114 |
V_90 -> V_37 ) ;
V_104 = F_45 ( V_98 -> V_115 ) >>
V_116 ;
V_98 -> V_115 = F_47 (
V_104 << V_116 |
V_90 -> V_37 ) ;
break;
case V_111 :
V_100 = V_88 -> V_48 ;
V_105 = F_55 ( V_100 -> V_105 ) ;
V_105 = F_56 ( int , V_105 , V_2 -> V_11 . V_117 [ V_18 ] ) ;
V_106 = V_95 -> V_105 [ V_18 ] ;
V_95 -> V_105 [ V_18 ] = V_105 ;
if ( V_105 > V_92 -> V_118 [ V_18 ] )
V_92 -> V_118 [ V_18 ] = V_105 ;
if ( V_105 < V_106 && V_106 ==
V_92 -> V_118 [ V_18 ] ) {
V_95 -> V_105 [ V_18 ] = V_105 ;
V_92 -> V_118 [ V_18 ] = V_105 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_119 ; V_5 ++ ) {
V_92 -> V_118 [ V_18 ] =
V_10 ( V_92 -> V_118 [ V_18 ] ,
V_92 -> V_96 [ V_5 ] . V_105 [ V_18 ] ) ;
}
}
V_100 -> V_105 = F_52 ( V_92 -> V_118 [ V_18 ] ) ;
break;
}
return F_31 ( V_2 , V_88 -> V_51 , V_47 , V_87 ,
V_52 , V_53 ,
V_54 ) ;
}
if ( V_2 -> V_35 & V_120 ) {
V_101 = ( * ( T_1 * ) V_88 -> V_48 ) & 0x40 ;
V_109 = ( ( T_5 * ) V_88 -> V_48 ) [ 2 ] ;
} else {
V_101 = ( ( T_1 * ) V_88 -> V_48 ) [ 3 ] & 0x1 ;
V_109 = ( ( T_5 * ) V_88 -> V_48 ) [ 1 ] ;
}
V_107 = 0 ;
V_108 =
V_89 -> V_93 . V_92 . V_96 [ V_86 ] . V_121 [ V_18 ] ;
V_89 -> V_93 . V_92 . V_96 [ V_86 ] . V_121 [ V_18 ] = V_109 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_119 ; V_5 ++ )
V_107 |=
V_89 -> V_93 . V_92 . V_96 [ V_5 ] . V_121 [ V_18 ] ;
if ( V_86 != V_2 -> V_11 . V_110 )
memset ( V_88 -> V_48 , 0 , 256 ) ;
if ( V_2 -> V_35 & V_120 ) {
* ( T_1 * ) V_88 -> V_48 |= ! ! V_101 << 6 ;
( ( T_5 * ) V_88 -> V_48 ) [ 2 ] = V_107 ;
} else {
( ( T_1 * ) V_88 -> V_48 ) [ 3 ] |= ! ! V_101 ;
( ( T_5 * ) V_88 -> V_48 ) [ 1 ] = V_107 ;
}
V_25 = F_31 ( V_2 , V_88 -> V_51 , V_18 , V_102 , V_52 ,
V_53 , V_54 ) ;
if ( V_25 )
V_89 -> V_93 . V_92 . V_96 [ V_86 ] . V_121 [ V_18 ] =
V_108 ;
return V_25 ;
}
int F_57 ( struct V_1 * V_2 , int V_86 ,
struct V_122 * V_123 ,
struct V_45 * V_88 ,
struct V_45 * V_124 ,
struct V_125 * V_126 )
{
return F_54 ( V_2 , V_86 , V_123 -> V_103 ,
V_123 -> V_127 , V_88 ) ;
}
int F_58 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_45 * V_46 ;
int V_25 , V_128 ;
if ( V_2 -> V_11 . V_129 [ V_18 ] == V_130 )
return 0 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
memset ( V_46 -> V_48 , 0 , 256 ) ;
( ( T_5 * ) V_46 -> V_48 ) [ 1 ] = V_2 -> V_11 . V_131 [ V_18 ] ;
for ( V_128 = 8 ; V_128 >= 1 ; V_128 >>= 1 ) {
( ( T_5 * ) V_46 -> V_48 ) [ 0 ] = F_47 (
( 1 << V_132 ) |
( 1 << V_133 ) |
( V_2 -> V_11 . V_134 [ V_18 ] << V_135 ) |
( V_128 << V_136 ) ) ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_18 , 0 , V_52 ,
V_53 , V_65 ) ;
if ( V_25 != - V_41 )
break;
}
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_18 , int V_105 ,
T_1 V_137 , T_1 V_138 , T_1 V_139 , T_1 V_140 )
{
struct V_45 * V_46 ;
struct V_99 * V_141 ;
int V_25 ;
T_4 V_47 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
V_141 = V_46 -> V_48 ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
V_141 -> V_35 = V_142 ;
V_141 -> V_105 = F_52 ( V_105 ) ;
V_141 -> V_137 = ( V_137 * ( ! V_138 ) ) << 7 ;
V_141 -> V_138 = V_138 ;
V_141 -> V_139 = ( V_139 * ( ! V_140 ) ) << 7 ;
V_141 -> V_140 = V_140 ;
V_47 = V_111 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_65 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_60 ( struct V_1 * V_2 , T_1 V_18 , T_4 V_37 ,
T_1 V_104 )
{
struct V_45 * V_46 ;
struct V_97 * V_141 ;
int V_25 ;
T_4 V_47 ;
T_4 V_143 = ( V_2 -> V_11 . V_35 & V_144 ) ?
V_145 : V_146 ;
if ( V_2 -> V_11 . V_35 & V_144 &&
V_2 -> V_11 . V_35 & V_36 )
return 0 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
V_141 = V_46 -> V_48 ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
V_141 -> V_37 = F_47 ( V_37 ) ;
V_141 -> V_113 = V_2 -> V_11 . V_12 ;
V_141 -> V_104 = F_47 ( V_104 << V_114 |
V_37 ) ;
V_141 -> V_115 = F_47 ( V_143 << V_116 |
V_37 ) ;
V_141 -> V_147 = 0 ;
V_141 -> V_148 = V_149 ;
V_141 -> V_150 = 0 ;
V_141 -> V_151 = V_152 ;
V_47 = V_112 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_65 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_153 )
{
struct V_45 * V_46 ;
struct V_154 * V_141 ;
int V_25 ;
T_4 V_47 ;
int V_5 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
V_141 = V_46 -> V_48 ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
for ( V_5 = 0 ; V_5 < V_155 ; V_5 += 2 )
V_141 -> V_153 [ V_5 >> 1 ] = V_153 [ V_5 ] << 4 | V_153 [ V_5 + 1 ] ;
V_47 = V_156 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_54 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_62 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_157 ,
T_1 * V_158 , T_6 * V_159 )
{
struct V_45 * V_46 ;
struct V_160 * V_141 ;
int V_25 ;
T_4 V_47 ;
int V_5 ;
V_46 = F_28 ( V_2 ) ;
if ( F_29 ( V_46 ) )
return F_30 ( V_46 ) ;
V_141 = V_46 -> V_48 ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
for ( V_5 = 0 ; V_5 < V_161 ; V_5 ++ ) {
struct V_162 * V_163 = & V_141 -> V_163 [ V_5 ] ;
T_6 V_164 = V_159 && V_159 [ V_5 ] ? V_159 [ V_5 ] :
V_165 ;
V_163 -> V_158 = F_63 ( V_158 [ V_5 ] ) ;
V_163 -> V_166 = F_63 ( V_157 [ V_5 ] ) ;
V_163 -> V_167 = F_63 ( V_168 ) ;
V_163 -> V_169 = F_63 ( V_164 ) ;
}
V_47 = V_170 << 8 | V_18 ;
V_25 = F_31 ( V_2 , V_46 -> V_51 , V_47 , 1 , V_52 ,
V_53 , V_54 ) ;
F_32 ( V_2 , V_46 ) ;
return V_25 ;
}
int F_64 ( struct V_1 * V_2 , int V_86 ,
struct V_122 * V_123 ,
struct V_45 * V_88 ,
struct V_45 * V_124 ,
struct V_125 * V_126 )
{
int V_25 = 0 ;
return V_25 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 , T_2 V_171 , T_1 V_172 )
{
return F_31 ( V_2 , ( V_19 | ( V_171 << 63 ) ) , V_18 , V_172 ,
V_173 , V_53 ,
V_65 ) ;
}
int F_66 ( struct V_1 * V_2 , int V_86 ,
struct V_122 * V_123 ,
struct V_45 * V_88 ,
struct V_45 * V_124 ,
struct V_125 * V_126 )
{
int V_25 = 0 ;
return V_25 ;
}
int F_67 ( struct V_1 * V_2 , int V_86 ,
T_4 V_47 , struct V_45 * V_124 )
{
return F_53 ( V_2 , 0 , V_124 -> V_51 , V_47 , 0 ,
V_174 , V_53 ,
V_54 ) ;
}
int F_68 ( struct V_1 * V_2 , int V_86 ,
struct V_122 * V_123 ,
struct V_45 * V_88 ,
struct V_45 * V_124 ,
struct V_125 * V_126 )
{
if ( V_86 != V_2 -> V_11 . V_110 )
return 0 ;
return F_67 ( V_2 , V_86 ,
V_123 -> V_103 , V_124 ) ;
}
void F_69 ( struct V_1 * V_2 , T_2 * V_175 )
{
if ( ! F_37 ( V_2 ) ) {
* V_175 = 0 ;
return;
}
* V_175 = ( V_176 |
V_177 |
V_178 ) ;
if ( F_70 ( V_2 ) )
* V_175 |= V_179 ;
}
