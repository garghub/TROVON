static void
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 )
F_2 ( V_5 -> V_6 ) ;
F_3 ( V_5 ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
F_2 ( V_5 -> V_6 ) ;
F_3 ( V_5 -> V_7 ) ;
F_3 ( V_5 ) ;
}
static void
F_5 ( struct V_8 * V_9 ,
struct V_4 * V_5 )
{
int V_10 ;
if ( ! V_5 )
return;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 ; V_10 ++ ) {
if ( ! V_5 -> V_12 [ V_10 ] )
break;
V_5 -> V_12 [ V_10 ] -> V_13 = 0 ;
V_5 -> V_12 [ V_10 ] = NULL ;
}
F_6 ( & V_9 -> V_14 , V_5 -> V_7 ) ;
F_7 ( & V_9 -> V_14 , V_9 -> V_15 ) ;
}
static void F_8 ( struct V_8 * V_9 ,
int V_16 )
{
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_20 * V_21 ;
if ( V_16 < 0 || V_16 > 1 )
return;
V_21 = & V_18 -> V_22 [ V_16 ] ;
F_9 ( V_21 -> V_23 , 0 , V_9 -> V_24 -> V_25 ) ;
memset ( V_21 -> V_26 , 0 ,
sizeof( * V_21 -> V_26 ) * V_9 -> V_24 -> V_25 ) ;
if ( V_21 -> V_27 ) {
F_5 ( V_9 , V_21 -> V_27 ) ;
V_21 -> V_27 = NULL ;
}
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
const struct V_30 * V_24 = V_9 -> V_24 ;
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_31 * V_31 = V_9 -> V_32 -> V_31 ;
struct V_20 * V_21 ;
struct V_4 * V_27 ;
struct V_33 * V_34 ;
unsigned int V_35 ;
T_1 V_36 = 0 ;
int V_10 = 0 ;
if ( V_18 -> V_37 < 0 || V_18 -> V_37 > 1 )
return;
V_21 = & V_18 -> V_22 [ V_18 -> V_37 ] ;
F_11 (cfg, slot->updated_configs, layer->desc->nconfigs) {
F_12 ( V_31 ,
V_24 -> V_38 +
F_13 ( V_9 , V_35 ) ,
V_21 -> V_26 [ V_35 ] ) ;
V_36 |= V_39 ;
}
V_27 = V_21 -> V_27 ;
if ( ! V_27 -> V_6 )
goto V_40;
if ( V_29 -> V_13 == V_41 ) {
for ( V_10 = 0 ; V_10 < V_27 -> V_42 ; V_10 ++ ) {
V_34 = V_27 -> V_12 [ V_10 ] ;
V_34 -> V_43 = V_44 |
V_45 |
V_46 |
V_47 ;
F_12 ( V_31 ,
V_24 -> V_38 +
F_14 ( V_10 ) ,
V_34 -> V_48 ) ;
F_12 ( V_31 ,
V_24 -> V_38 +
F_15 ( V_10 ) ,
V_34 -> V_43 ) ;
F_12 ( V_31 ,
V_24 -> V_38 +
F_16 ( V_10 ) ,
V_34 -> V_49 ) ;
}
V_36 |= V_50 ;
V_29 -> V_13 = V_51 ;
} else {
for ( V_10 = 0 ; V_10 < V_27 -> V_42 ; V_10 ++ ) {
V_34 = V_27 -> V_12 [ V_10 ] ;
V_34 -> V_43 = V_44 |
V_45 |
V_52 |
V_47 ;
F_12 ( V_31 ,
V_24 -> V_38 +
F_17 ( V_10 ) ,
V_34 -> V_49 ) ;
}
V_36 |= V_53 ;
}
for ( V_10 = V_27 -> V_42 ; V_10 < V_9 -> V_11 ; V_10 ++ ) {
V_27 -> V_12 [ V_10 ] -> V_13 = 0 ;
V_27 -> V_12 [ V_10 ] = NULL ;
}
V_29 -> V_54 = V_27 ;
V_21 -> V_27 = NULL ;
V_40:
if ( V_36 )
F_12 ( V_31 ,
V_24 -> V_38 + V_55 ,
V_36 ) ;
F_8 ( V_9 , V_18 -> V_37 ) ;
V_18 -> V_37 = - 1 ;
}
void F_18 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
const struct V_30 * V_24 = V_9 -> V_24 ;
struct V_31 * V_31 = V_9 -> V_32 -> V_31 ;
struct V_4 * V_5 ;
unsigned long V_56 ;
unsigned int V_57 , V_58 ;
unsigned int V_13 ;
unsigned int V_59 ;
T_1 V_60 ;
int V_10 ;
F_19 ( V_31 , V_24 -> V_38 + V_61 , & V_58 ) ;
F_19 ( V_31 , V_24 -> V_38 + V_62 , & V_57 ) ;
V_13 = V_58 & V_57 ;
if ( ! V_13 )
return;
F_20 ( & V_9 -> V_63 , V_56 ) ;
V_5 = V_29 -> V_54 ? V_29 -> V_54 : V_29 -> V_64 ;
if ( ! V_5 ) {
F_21 ( & V_9 -> V_63 , V_56 ) ;
return;
}
V_60 = V_65 |
V_66 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_42 ; V_10 ++ ) {
V_59 = ( V_13 >> ( 8 * V_10 ) ) ;
if ( V_59 &
( V_46 |
V_52 ) &
~ V_5 -> V_12 [ V_10 ] -> V_43 ) {
V_5 -> V_12 [ V_10 ] -> V_13 |=
V_65 ;
V_5 -> V_12 [ V_10 ] -> V_43 |=
V_46 |
V_52 ;
}
if ( V_59 &
V_47 &
~ V_5 -> V_12 [ V_10 ] -> V_43 ) {
V_5 -> V_12 [ V_10 ] -> V_13 |=
V_66 ;
V_5 -> V_12 [ V_10 ] -> V_43 |=
V_47 ;
}
if ( V_59 & V_67 )
V_5 -> V_12 [ V_10 ] -> V_13 |=
V_68 ;
if ( ! ( V_5 -> V_12 [ V_10 ] -> V_13 &
V_65 ) )
V_60 &= ~ V_65 ;
if ( ! ( V_5 -> V_12 [ V_10 ] -> V_13 &
V_66 ) )
V_60 &= ~ V_66 ;
V_60 |= V_5 -> V_12 [ V_10 ] -> V_13 &
V_68 ;
}
V_60 ^= V_5 -> V_13 ;
V_5 -> V_13 |= V_60 ;
if ( V_60 & V_65 ) {
F_5 ( V_9 , V_29 -> V_64 ) ;
V_29 -> V_64 = V_29 -> V_54 ;
V_29 -> V_54 = NULL ;
}
if ( V_60 & V_66 ) {
F_5 ( V_9 , V_29 -> V_64 ) ;
V_29 -> V_64 = NULL ;
}
if ( V_60 & V_68 ) {
F_12 ( V_31 ,
V_24 -> V_38 + V_69 ,
V_70 ) ;
if ( V_29 -> V_54 )
F_5 ( V_9 ,
V_29 -> V_54 ) ;
if ( V_29 -> V_64 )
F_5 ( V_9 ,
V_29 -> V_64 ) ;
V_29 -> V_64 = NULL ;
V_29 -> V_54 = NULL ;
}
if ( ! V_29 -> V_54 ) {
F_10 ( V_9 ) ;
if ( ! V_29 -> V_64 )
V_29 -> V_13 = V_41 ;
}
F_21 ( & V_9 -> V_63 , V_56 ) ;
}
void F_22 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_31 * V_31 = V_9 -> V_32 -> V_31 ;
const struct V_30 * V_24 = V_9 -> V_24 ;
unsigned long V_56 ;
unsigned int V_57 ;
F_20 ( & V_9 -> V_63 , V_56 ) ;
F_12 ( V_31 , V_24 -> V_38 + V_69 ,
V_70 | V_53 |
V_39 ) ;
F_19 ( V_31 , V_24 -> V_38 + V_62 , & V_57 ) ;
if ( V_29 -> V_64 ) {
F_5 ( V_9 , V_29 -> V_64 ) ;
V_29 -> V_64 = NULL ;
}
if ( V_29 -> V_54 ) {
F_5 ( V_9 , V_29 -> V_54 ) ;
V_29 -> V_54 = NULL ;
}
if ( V_18 -> V_37 >= 0 ) {
F_8 ( V_9 , V_18 -> V_37 ) ;
V_18 -> V_37 = - 1 ;
}
V_29 -> V_13 = V_41 ;
F_21 ( & V_9 -> V_63 , V_56 ) ;
}
int F_23 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_31 * V_31 = V_9 -> V_32 -> V_31 ;
struct V_4 * V_27 ;
struct V_20 * V_21 ;
unsigned long V_56 ;
int V_10 , V_71 = 0 ;
V_27 = F_24 ( sizeof( * V_27 ) , V_72 ) ;
if ( ! V_27 )
return - V_73 ;
V_27 -> V_7 = F_25 ( V_27 , V_72 ) ;
if ( ! V_27 -> V_7 ) {
F_3 ( V_27 ) ;
return - V_73 ;
}
F_20 ( & V_9 -> V_63 , V_56 ) ;
V_18 -> V_49 = V_18 -> V_37 ? 0 : 1 ;
V_21 = & V_18 -> V_22 [ V_18 -> V_49 ] ;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 * 4 ; V_10 ++ ) {
if ( ! V_29 -> V_12 [ V_10 ] . V_13 ) {
V_27 -> V_12 [ V_71 ++ ] = & V_29 -> V_12 [ V_10 ] ;
V_29 -> V_12 [ V_10 ] . V_13 =
V_74 ;
if ( V_71 == V_9 -> V_11 )
break;
}
}
if ( V_71 < V_9 -> V_11 ) {
for ( V_10 = 0 ; V_10 < V_71 ; V_10 ++ )
V_27 -> V_12 [ V_10 ] -> V_13 = 0 ;
}
if ( V_71 < V_9 -> V_11 ) {
F_21 ( & V_9 -> V_63 , V_56 ) ;
F_4 ( V_27 ) ;
return - V_75 ;
}
V_21 -> V_27 = V_27 ;
if ( V_18 -> V_37 >= 0 ) {
memcpy ( V_21 -> V_26 ,
V_18 -> V_22 [ V_18 -> V_37 ] . V_26 ,
V_9 -> V_24 -> V_25 * sizeof( T_1 ) ) ;
memcpy ( V_21 -> V_23 ,
V_18 -> V_22 [ V_18 -> V_37 ] . V_23 ,
F_26 ( V_9 -> V_24 -> V_25 ,
V_76 * sizeof( unsigned long ) ) *
sizeof( unsigned long ) ) ;
V_21 -> V_27 -> V_6 = V_18 -> V_22 [ V_18 -> V_37 ] . V_27 -> V_6 ;
if ( V_18 -> V_22 [ V_18 -> V_37 ] . V_27 -> V_6 ) {
V_21 -> V_27 -> V_6 =
V_18 -> V_22 [ V_18 -> V_37 ] . V_27 -> V_6 ;
V_21 -> V_27 -> V_42 =
V_18 -> V_22 [ V_18 -> V_37 ] . V_27 -> V_42 ;
F_27 ( V_21 -> V_27 -> V_6 ) ;
}
} else {
F_28 ( V_31 ,
V_9 -> V_24 -> V_38 +
F_13 ( V_9 , 0 ) ,
V_18 -> V_22 [ V_18 -> V_49 ] . V_26 ,
V_9 -> V_24 -> V_25 ) ;
}
F_21 ( & V_9 -> V_63 , V_56 ) ;
return 0 ;
}
void F_29 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = & V_9 -> V_19 ;
F_8 ( V_9 , V_18 -> V_49 ) ;
V_18 -> V_49 = - 1 ;
}
void F_30 ( struct V_8 * V_9 ,
struct V_77 * V_6 ,
unsigned int * V_78 )
{
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_4 * V_27 ;
struct V_20 * V_21 ;
struct V_33 * V_34 ;
struct V_77 * V_79 ;
int V_80 = 0 ;
int V_10 ;
if ( V_18 -> V_49 < 0 || V_18 -> V_49 > 1 )
return;
if ( V_6 )
V_80 = V_6 -> V_81 -> V_82 ;
if ( V_80 > V_9 -> V_11 )
return;
V_21 = & V_18 -> V_22 [ V_18 -> V_49 ] ;
V_27 = V_21 -> V_27 ;
V_79 = V_21 -> V_27 -> V_6 ;
for ( V_10 = 0 ; V_10 < V_80 ; V_10 ++ ) {
struct V_83 * V_84 ;
V_34 = V_21 -> V_27 -> V_12 [ V_10 ] ;
V_84 = F_31 ( V_6 , V_10 ) ;
V_34 -> V_48 = V_84 -> V_85 + V_78 [ V_10 ] ;
}
V_27 -> V_42 = V_80 ;
V_27 -> V_6 = V_6 ;
if ( V_6 )
F_27 ( V_6 ) ;
if ( V_79 )
F_2 ( V_79 ) ;
}
void F_32 ( struct V_8 * V_9 , int V_35 ,
T_1 V_86 , T_1 V_3 )
{
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_20 * V_21 ;
if ( V_18 -> V_49 < 0 || V_18 -> V_49 > 1 )
return;
if ( V_35 >= V_9 -> V_24 -> V_25 )
return;
V_21 = & V_18 -> V_22 [ V_18 -> V_49 ] ;
V_21 -> V_26 [ V_35 ] &= ~ V_86 ;
V_21 -> V_26 [ V_35 ] |= ( V_3 & V_86 ) ;
F_33 ( V_35 , V_21 -> V_23 ) ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
struct V_17 * V_18 = & V_9 -> V_19 ;
struct V_20 * V_21 ;
unsigned long V_56 ;
if ( V_18 -> V_49 < 0 || V_18 -> V_49 > 1 )
return;
V_21 = & V_18 -> V_22 [ V_18 -> V_49 ] ;
F_20 ( & V_9 -> V_63 , V_56 ) ;
if ( V_18 -> V_37 >= 0 )
F_8 ( V_9 , V_18 -> V_37 ) ;
V_18 -> V_37 = V_18 -> V_49 ;
V_18 -> V_49 = - 1 ;
if ( ! V_29 -> V_54 )
F_10 ( V_9 ) ;
F_21 ( & V_9 -> V_63 , V_56 ) ;
V_18 -> V_49 = - 1 ;
}
static int F_35 ( struct V_87 * V_88 ,
struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
T_2 V_89 ;
int V_10 ;
V_29 -> V_12 = F_36 ( V_88 -> V_88 ,
V_9 -> V_11 * 4 *
sizeof( * V_29 -> V_12 ) ,
& V_89 , V_72 ) ;
if ( ! V_29 -> V_12 )
return - V_73 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 * 4 ; V_10 ++ ) {
struct V_33 * V_34 = & V_29 -> V_12 [ V_10 ] ;
V_34 -> V_49 = V_89 + ( V_10 * sizeof( * V_34 ) ) ;
}
return 0 ;
}
static void F_37 ( struct V_87 * V_88 ,
struct V_8 * V_9 )
{
struct V_28 * V_29 = & V_9 -> V_29 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 * 4 ; V_10 ++ ) {
struct V_33 * V_34 = & V_29 -> V_12 [ V_10 ] ;
V_34 -> V_13 = 0 ;
}
F_38 ( V_88 -> V_88 , V_9 -> V_11 * 4 *
sizeof( * V_29 -> V_12 ) , V_29 -> V_12 ,
V_29 -> V_12 [ 0 ] . V_49 ) ;
}
static int F_39 ( struct V_87 * V_88 ,
struct V_8 * V_9 ,
const struct V_30 * V_24 )
{
struct V_17 * V_18 = & V_9 -> V_19 ;
int V_90 ;
void * V_91 ;
int V_10 ;
V_90 = F_26 ( V_24 -> V_25 ,
V_76 *
sizeof( unsigned long ) ) ;
V_91 = F_40 ( V_88 -> V_88 ,
( ( V_24 -> V_25 * sizeof( T_1 ) ) +
( V_90 * sizeof( unsigned long ) ) ) * 2 ,
V_72 ) ;
if ( ! V_91 )
return - V_73 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_18 -> V_22 [ V_10 ] . V_23 = V_91 ;
V_91 += V_90 * sizeof( unsigned long ) ;
V_18 -> V_22 [ V_10 ] . V_26 = V_91 ;
V_91 += V_24 -> V_25 * sizeof( T_1 ) ;
}
V_18 -> V_37 = - 1 ;
V_18 -> V_49 = - 1 ;
return 0 ;
}
int F_41 ( struct V_87 * V_88 ,
struct V_8 * V_9 ,
const struct V_30 * V_24 )
{
struct V_92 * V_93 = V_88 -> V_94 ;
struct V_31 * V_31 = V_93 -> V_32 -> V_31 ;
unsigned int V_95 ;
int V_96 ;
int V_10 ;
V_9 -> V_32 = V_93 -> V_32 ;
V_9 -> V_15 = V_93 -> V_15 ;
V_9 -> V_24 = V_24 ;
F_12 ( V_31 , V_24 -> V_38 + V_69 ,
V_70 ) ;
for ( V_10 = 0 ; V_10 < V_24 -> V_97 -> V_98 ; V_10 ++ ) {
int V_80 = F_42 ( V_24 -> V_97 -> V_97 [ V_10 ] ) ;
if ( V_80 > V_9 -> V_11 )
V_9 -> V_11 = V_80 ;
}
F_43 ( & V_9 -> V_63 ) ;
F_44 ( & V_9 -> V_14 , V_24 -> V_99 ,
F_1 ) ;
V_96 = F_35 ( V_88 , V_9 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_39 ( V_88 , V_9 , V_24 ) ;
if ( V_96 )
return V_96 ;
F_12 ( V_31 , V_24 -> V_38 + V_100 ,
0xffffffff ) ;
F_19 ( V_31 , V_24 -> V_38 + V_62 ,
& V_95 ) ;
V_95 = 0 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 ; V_10 ++ )
V_95 |= ( V_45 |
V_52 |
V_46 |
V_47 |
V_67 ) << ( 8 * V_10 ) ;
F_12 ( V_31 , V_24 -> V_38 + V_101 , V_95 ) ;
return 0 ;
}
void F_45 ( struct V_87 * V_88 ,
struct V_8 * V_9 )
{
const struct V_30 * V_24 = V_9 -> V_24 ;
struct V_31 * V_31 = V_9 -> V_32 -> V_31 ;
F_12 ( V_31 , V_24 -> V_38 + V_100 ,
0xffffffff ) ;
F_12 ( V_31 , V_24 -> V_38 + V_69 ,
V_70 ) ;
F_37 ( V_88 , V_9 ) ;
F_46 ( & V_9 -> V_14 ) ;
}
