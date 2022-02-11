static T_1 F_1 ( struct V_1 * V_2 ,
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
static void F_6 ( struct V_1 * V_2 ,
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
int V_12 ;
F_9 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ ) {
if ( V_2 -> V_15 . V_17 [ V_12 ] . V_21 )
return & V_2 -> V_15 . V_17 [ V_12 ] ;
}
F_12 ( L_1 ) ;
return NULL ;
}
void F_13 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
T_1 V_13 ;
if ( ! V_29 || ! V_29 -> V_31 || ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_13 ;
F_3 ( V_32 + V_13 ,
F_15 ( V_29 -> V_31 -> V_17 -> V_33 ) ) ;
}
void F_16 ( struct V_23 * V_24 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_36 * V_37 ;
struct V_38 * V_38 = NULL ;
T_1 V_14 = 0 , V_13 ;
if ( ! V_29 || ! V_29 -> V_31 || ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_17 -> V_13 ;
F_17 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_37 -> V_24 == V_24 ) {
V_38 = F_18 ( V_37 ) ;
break;
}
}
if ( ! V_38 ) {
F_12 ( L_2 ) ;
return;
}
if ( V_35 -> V_5 & V_39 ) {
if ( V_37 -> V_40 [ 1 ] )
V_14 = F_19 ( V_37 -> V_41 [ 1 ] ) |
F_20 ( V_37 -> V_42 [ 1 ] ) ;
else
V_14 = F_19 ( 255 ) | F_20 ( 255 ) ;
} else {
if ( V_37 -> V_40 [ 0 ] )
V_14 = F_19 ( V_37 -> V_41 [ 0 ] ) |
F_20 ( V_37 -> V_42 [ 0 ] ) ;
else
V_14 = F_19 ( 255 ) | F_20 ( 255 ) ;
}
F_21 ( V_13 , V_43 , V_14 ) ;
}
void F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_36 * V_37 ;
struct V_38 * V_38 = NULL ;
T_1 V_13 , V_14 ;
T_2 * V_44 ;
int V_45 ;
if ( ! V_29 || ! V_29 -> V_31 || ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_17 -> V_13 ;
F_17 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_37 -> V_24 == V_24 )
V_38 = F_18 ( V_37 ) ;
}
if ( ! V_38 ) {
F_12 ( L_2 ) ;
return;
}
V_45 = F_23 ( V_38 -> V_46 , & V_44 ) ;
if ( V_45 <= 0 ) {
F_12 ( L_3 , V_45 ) ;
return;
}
V_14 = F_10 ( V_13 , V_47 ) ;
V_14 &= ~ ( V_48 | V_49 ) ;
V_14 |= V_50 ;
if ( V_45 )
V_14 |= F_24 ( V_44 [ 0 ] ) ;
else
V_14 |= F_24 ( 5 ) ;
F_21 ( V_13 , V_47 , V_14 ) ;
F_25 ( V_44 ) ;
}
void F_26 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
T_1 V_13 ;
struct V_36 * V_37 ;
struct V_38 * V_38 = NULL ;
struct V_51 * V_52 ;
int V_12 , V_45 ;
static const T_3 V_53 [] [ 2 ] = {
{ V_54 , V_55 } ,
{ V_56 , V_57 } ,
{ V_58 , V_59 } ,
{ V_60 , V_61 } ,
{ V_62 , V_63 } ,
{ V_64 , V_65 } ,
{ V_66 , V_67 } ,
{ V_68 , V_69 } ,
{ V_70 , V_71 } ,
{ V_72 , V_73 } ,
{ V_74 , V_75 } ,
{ V_76 , V_77 } ,
} ;
if ( ! V_29 || ! V_29 -> V_31 || ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_17 -> V_13 ;
F_17 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_37 -> V_24 == V_24 )
V_38 = F_18 ( V_37 ) ;
}
if ( ! V_38 ) {
F_12 ( L_2 ) ;
return;
}
V_45 = F_27 ( V_38 -> V_46 , & V_52 ) ;
if ( V_45 <= 0 ) {
F_12 ( L_4 , V_45 ) ;
return;
}
F_28 ( ! V_52 ) ;
for ( V_12 = 0 ; V_12 < F_29 ( V_53 ) ; V_12 ++ ) {
T_1 V_78 = 0 ;
T_2 V_79 = 0 ;
int V_80 = - 1 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_45 ; V_81 ++ ) {
struct V_51 * V_82 = & V_52 [ V_81 ] ;
if ( V_82 -> V_83 == V_53 [ V_12 ] [ 1 ] ) {
if ( V_82 -> V_84 > V_80 ) {
V_78 = F_30 ( V_82 -> V_84 ) |
F_31 ( V_82 -> V_85 ) |
F_32 ( V_82 -> V_86 ) ;
V_80 = V_82 -> V_84 ;
}
if ( V_82 -> V_83 == V_55 )
V_79 |= V_82 -> V_86 ;
else
break;
}
}
V_78 |= F_33 ( V_79 ) ;
F_21 ( V_13 , V_53 [ V_12 ] [ 0 ] , V_78 ) ;
}
F_25 ( V_52 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
return ! F_35 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_22 * V_17 ,
bool V_87 )
{
if ( ! V_17 )
return;
F_21 ( V_17 -> V_13 , V_88 ,
V_87 ? V_89 : 0 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_90 || ! F_34 ( V_2 ) )
return 0 ;
V_2 -> V_15 . V_91 = true ;
if ( F_38 ( V_2 ) )
V_2 -> V_15 . V_16 = 7 ;
else if ( F_39 ( V_2 ) )
V_2 -> V_15 . V_16 = 3 ;
else if ( F_7 ( V_2 ) )
V_2 -> V_15 . V_16 = 7 ;
else if ( F_40 ( V_2 ) )
V_2 -> V_15 . V_16 = 6 ;
else if ( F_41 ( V_2 ) )
V_2 -> V_15 . V_16 = 2 ;
else
V_2 -> V_15 . V_16 = 6 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ ) {
V_2 -> V_15 . V_17 [ V_12 ] . V_84 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_92 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_93 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_94 = 0 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_95 = 0 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_21 = false ;
V_2 -> V_15 . V_17 [ V_12 ] . V_13 = V_96 [ V_12 ] ;
V_2 -> V_15 . V_17 [ V_12 ] . V_33 = V_12 ;
F_36 ( V_2 , & V_2 -> V_15 . V_17 [ V_12 ] , false ) ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_15 . V_91 )
return;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ )
F_36 ( V_2 , & V_2 -> V_15 . V_17 [ V_12 ] , false ) ;
V_2 -> V_15 . V_91 = false ;
}
