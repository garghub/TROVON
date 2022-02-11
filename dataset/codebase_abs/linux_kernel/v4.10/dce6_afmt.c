T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
F_3 ( V_8 + V_3 , V_4 ) ;
V_6 = F_4 ( V_9 + V_3 ) ;
F_5 ( & V_2 -> V_7 , V_5 ) ;
return V_6 ;
}
void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_10 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
if ( F_7 ( V_2 ) )
F_3 ( V_8 + V_3 , V_4 ) ;
else
F_3 ( V_8 + V_3 ,
V_11 | F_8 ( V_4 ) ) ;
F_3 ( V_9 + V_3 , V_10 ) ;
F_5 ( & V_2 -> V_7 , V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_12 ;
T_1 V_13 , V_14 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ ) {
V_13 = V_2 -> V_15 . V_17 [ V_12 ] . V_13 ;
V_14 = F_10 ( V_13 ,
V_18 ) ;
if ( ( ( V_14 & V_19 ) >> V_20 ) == 1 )
V_2 -> V_15 . V_17 [ V_12 ] . V_21 = false ;
else
V_2 -> V_15 . V_17 [ V_12 ] . V_21 = true ;
}
}
struct V_22 * F_11 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_25 * V_25 ;
struct V_26 * V_27 ;
struct V_22 * V_17 = NULL ;
int V_12 , V_28 ;
F_9 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ ) {
if ( V_2 -> V_15 . V_17 [ V_12 ] . V_21 ) {
V_17 = & V_2 -> V_15 . V_17 [ V_12 ] ;
V_28 = 0 ;
F_12 (encoder, &rdev->ddev->mode_config.encoder_list, head) {
if ( F_13 ( V_24 ) ) {
V_25 = F_14 ( V_24 ) ;
V_27 = V_25 -> V_29 ;
if ( V_27 -> V_17 == V_17 )
V_28 ++ ;
}
}
if ( V_28 == 0 )
return V_17 ;
}
}
if ( ! V_17 )
F_15 ( L_1 ) ;
return V_17 ;
}
void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_30 -> V_31 ;
struct V_25 * V_25 = F_14 ( V_24 ) ;
struct V_26 * V_27 = V_25 -> V_29 ;
if ( ! V_27 || ! V_27 -> V_32 || ! V_27 -> V_17 )
return;
F_3 ( V_33 + V_27 -> V_32 -> V_13 ,
F_17 ( V_27 -> V_17 -> V_34 ) ) ;
}
void F_18 ( struct V_23 * V_24 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_24 -> V_30 -> V_31 ;
struct V_25 * V_25 = F_14 ( V_24 ) ;
struct V_26 * V_27 = V_25 -> V_29 ;
T_1 V_14 = 0 ;
if ( ! V_27 || ! V_27 -> V_32 || ! V_27 -> V_17 )
return;
if ( V_38 -> V_5 & V_39 ) {
if ( V_36 -> V_40 [ 1 ] )
V_14 = F_19 ( V_36 -> V_41 [ 1 ] ) |
F_20 ( V_36 -> V_42 [ 1 ] ) ;
else
V_14 = F_19 ( 0 ) | F_20 ( 0 ) ;
} else {
if ( V_36 -> V_40 [ 0 ] )
V_14 = F_19 ( V_36 -> V_41 [ 0 ] ) |
F_20 ( V_36 -> V_42 [ 0 ] ) ;
else
V_14 = F_19 ( 0 ) | F_20 ( 0 ) ;
}
F_21 ( V_27 -> V_17 -> V_13 ,
V_43 , V_14 ) ;
}
void F_22 ( struct V_23 * V_24 ,
T_2 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_24 -> V_30 -> V_31 ;
struct V_25 * V_25 = F_14 ( V_24 ) ;
struct V_26 * V_27 = V_25 -> V_29 ;
T_1 V_14 ;
if ( ! V_27 || ! V_27 -> V_32 || ! V_27 -> V_17 )
return;
V_14 = F_10 ( V_27 -> V_17 -> V_13 ,
V_46 ) ;
V_14 &= ~ ( V_47 | V_48 ) ;
V_14 |= V_49 ;
if ( V_45 )
V_14 |= F_23 ( V_44 [ 0 ] ) ;
else
V_14 |= F_23 ( 5 ) ;
F_21 ( V_27 -> V_17 -> V_13 ,
V_46 , V_14 ) ;
}
void F_24 ( struct V_23 * V_24 ,
T_2 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_24 -> V_30 -> V_31 ;
struct V_25 * V_25 = F_14 ( V_24 ) ;
struct V_26 * V_27 = V_25 -> V_29 ;
T_1 V_14 ;
if ( ! V_27 || ! V_27 -> V_32 || ! V_27 -> V_17 )
return;
V_14 = F_10 ( V_27 -> V_17 -> V_13 ,
V_46 ) ;
V_14 &= ~ ( V_49 | V_48 ) ;
V_14 |= V_47 ;
if ( V_45 )
V_14 |= F_23 ( V_44 [ 0 ] ) ;
else
V_14 |= F_23 ( 5 ) ;
F_21 ( V_27 -> V_17 -> V_13 ,
V_46 , V_14 ) ;
}
void F_25 ( struct V_23 * V_24 ,
struct V_50 * V_51 , int V_45 )
{
int V_12 ;
struct V_25 * V_25 = F_14 ( V_24 ) ;
struct V_26 * V_27 = V_25 -> V_29 ;
struct V_1 * V_2 = V_24 -> V_30 -> V_31 ;
static const T_3 V_52 [] [ 2 ] = {
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ V_57 , V_58 } ,
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ V_69 , V_70 } ,
{ V_71 , V_72 } ,
{ V_73 , V_74 } ,
{ V_75 , V_76 } ,
} ;
if ( ! V_27 || ! V_27 -> V_32 || ! V_27 -> V_17 )
return;
for ( V_12 = 0 ; V_12 < F_26 ( V_52 ) ; V_12 ++ ) {
T_1 V_77 = 0 ;
T_2 V_78 = 0 ;
int V_79 = - 1 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_45 ; V_80 ++ ) {
struct V_50 * V_81 = & V_51 [ V_80 ] ;
if ( V_81 -> V_82 == V_52 [ V_12 ] [ 1 ] ) {
if ( V_81 -> V_83 > V_79 ) {
V_77 = F_27 ( V_81 -> V_83 ) |
F_28 ( V_81 -> V_84 ) |
F_29 ( V_81 -> V_85 ) ;
V_79 = V_81 -> V_83 ;
}
if ( V_81 -> V_82 == V_54 )
V_78 |= V_81 -> V_85 ;
else
break;
}
}
V_77 |= F_30 ( V_78 ) ;
F_21 ( V_27 -> V_17 -> V_13 , V_52 [ V_12 ] [ 0 ] , V_77 ) ;
}
}
void F_31 ( struct V_1 * V_2 ,
struct V_22 * V_17 ,
T_2 V_86 )
{
if ( ! V_17 )
return;
F_21 ( V_17 -> V_13 , V_87 ,
V_86 ? V_88 : 0 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_89 * V_90 , unsigned int clock )
{
T_1 V_77 = 0 ;
if ( V_90 )
V_77 |= F_33 ( V_90 -> V_91 ) ;
F_3 ( V_92 , V_77 ) ;
F_3 ( V_93 , 24000 ) ;
F_3 ( V_94 , clock ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_89 * V_90 , unsigned int clock )
{
T_1 V_77 = 0 ;
V_77 |= V_95 ;
if ( V_90 )
V_77 |= F_33 ( V_90 -> V_91 ) ;
F_3 ( V_92 , V_77 ) ;
if ( F_7 ( V_2 ) ) {
unsigned int div = ( F_4 ( V_96 ) &
V_97 ) >>
V_98 ;
div = F_35 ( div ) ;
if ( div )
clock = clock * 100 / div ;
F_3 ( V_99 , 24000 ) ;
F_3 ( V_100 , clock ) ;
} else {
F_3 ( V_101 , 24000 ) ;
F_3 ( V_102 , clock ) ;
}
}
