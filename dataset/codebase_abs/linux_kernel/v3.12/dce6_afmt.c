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
T_1 V_13 = V_29 -> V_31 -> V_13 ;
if ( ! V_29 -> V_31 -> V_17 )
return;
F_3 ( V_32 + V_13 ,
F_15 ( V_29 -> V_31 -> V_17 -> V_33 ) ) ;
}
void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_34 * V_35 ;
struct V_36 * V_36 = NULL ;
T_1 V_13 , V_14 ;
T_2 * V_37 ;
int V_38 ;
return;
if ( ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_17 -> V_13 ;
F_17 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_35 -> V_24 == V_24 )
V_36 = F_18 ( V_35 ) ;
}
if ( ! V_36 ) {
F_12 ( L_2 ) ;
return;
}
V_38 = F_19 ( V_36 -> V_39 , & V_37 ) ;
if ( V_38 < 0 ) {
F_12 ( L_3 , V_38 ) ;
return;
}
V_14 = F_10 ( V_13 , V_40 ) ;
V_14 &= ~ ( V_41 | V_42 ) ;
V_14 |= V_43 ;
if ( V_38 )
V_14 |= F_20 ( V_37 [ 0 ] ) ;
else
V_14 |= F_20 ( 5 ) ;
F_21 ( V_13 , V_40 , V_14 ) ;
F_22 ( V_37 ) ;
}
void F_23 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 -> V_26 ;
struct V_27 * V_27 = F_14 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
T_1 V_13 ;
struct V_34 * V_35 ;
struct V_36 * V_36 = NULL ;
struct V_44 * V_45 ;
int V_12 , V_38 ;
static const T_3 V_46 [] [ 2 ] = {
{ V_47 , V_48 } ,
{ V_49 , V_50 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ V_57 , V_58 } ,
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
{ V_67 , V_68 } ,
{ V_69 , V_70 } ,
} ;
if ( ! V_29 -> V_31 -> V_17 )
return;
V_13 = V_29 -> V_31 -> V_17 -> V_13 ;
F_17 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_35 -> V_24 == V_24 )
V_36 = F_18 ( V_35 ) ;
}
if ( ! V_36 ) {
F_12 ( L_2 ) ;
return;
}
V_38 = F_24 ( V_36 -> V_39 , & V_45 ) ;
if ( V_38 < 0 ) {
F_12 ( L_4 , V_38 ) ;
return;
}
F_25 ( ! V_45 ) ;
for ( V_12 = 0 ; V_12 < F_26 ( V_46 ) ; V_12 ++ ) {
T_1 V_71 = 0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_38 ; V_72 ++ ) {
struct V_44 * V_73 = & V_45 [ V_72 ] ;
if ( V_73 -> V_74 == V_46 [ V_12 ] [ 1 ] ) {
V_71 = F_27 ( V_73 -> V_75 ) |
F_28 ( V_73 -> V_76 ) |
F_29 ( V_73 -> V_77 ) ;
if ( V_73 -> V_74 == V_48 )
V_71 |= F_30 ( V_73 -> V_77 ) ;
break;
}
}
F_21 ( V_13 , V_46 [ V_12 ] [ 0 ] , V_71 ) ;
}
F_22 ( V_45 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
return ! F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_22 * V_17 ,
bool V_78 )
{
F_21 ( V_17 -> V_13 , V_79 ,
V_80 ) ;
F_34 ( L_5 , V_78 ? L_6 : L_7 , V_17 -> V_33 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_81 || ! F_31 ( V_2 ) )
return 0 ;
V_2 -> V_15 . V_82 = true ;
if ( F_7 ( V_2 ) )
V_2 -> V_15 . V_16 = 7 ;
else
V_2 -> V_15 . V_16 = 6 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ ) {
V_2 -> V_15 . V_17 [ V_12 ] . V_75 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_83 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_84 = - 1 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_85 = 0 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_86 = 0 ;
V_2 -> V_15 . V_17 [ V_12 ] . V_21 = false ;
V_2 -> V_15 . V_17 [ V_12 ] . V_13 = V_87 [ V_12 ] ;
V_2 -> V_15 . V_17 [ V_12 ] . V_33 = V_12 ;
F_33 ( V_2 , & V_2 -> V_15 . V_17 [ V_12 ] , true ) ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_15 . V_82 )
return;
for ( V_12 = 0 ; V_12 < V_2 -> V_15 . V_16 ; V_12 ++ )
F_33 ( V_2 , & V_2 -> V_15 . V_17 [ V_12 ] , false ) ;
V_2 -> V_15 . V_82 = false ;
}
