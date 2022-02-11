static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_4 ,
V_7 -> V_8 [ 0 ] . V_9 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 , V_11 = F_5 ( V_7 -> V_12 -> V_13 ) ;
F_6 ( L_1 , V_2 -> V_14 . V_15 , V_2 ) ;
F_7 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
if ( V_16 -> V_9 )
F_8 ( V_16 -> V_9 ) ;
}
F_9 ( V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_17 , unsigned V_18 ,
struct V_19 * V_20 , unsigned V_21 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
F_11 ( V_2 , V_20 [ V_10 ] . V_22 , V_20 [ V_10 ] . y1 ,
V_20 [ V_10 ] . V_23 - V_20 [ V_10 ] . V_22 ,
V_20 [ V_10 ] . V_24 - V_20 [ V_10 ] . y1 ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_25 , V_10 , V_11 = F_5 ( V_7 -> V_12 -> V_13 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
V_25 = F_13 ( V_16 -> V_9 , & V_16 -> V_26 , true ) ;
if ( V_25 )
goto V_27;
}
return 0 ;
V_27:
while ( -- V_10 > 0 ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_14 ( V_16 -> V_9 ) ;
}
return V_25 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 , V_11 = F_5 ( V_7 -> V_12 -> V_13 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_14 ( V_16 -> V_9 ) ;
}
}
void F_16 ( struct V_1 * V_2 , int V_28 , int V_29 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_12 * V_12 = V_7 -> V_12 ;
struct V_16 * V_16 = & V_7 -> V_8 [ 0 ] ;
unsigned int V_32 ;
V_32 = V_16 -> V_32 +
( V_28 * V_12 -> V_8 [ 0 ] . V_33 ) +
( V_29 * V_16 -> V_34 / V_12 -> V_8 [ 0 ] . V_35 ) ;
V_31 -> V_36 = V_12 -> V_37 ;
V_31 -> V_26 = V_16 -> V_26 + V_32 ;
V_31 -> V_38 = V_16 -> V_34 / V_12 -> V_8 [ 0 ] . V_33 ;
if ( V_12 -> V_37 == V_39 ) {
V_16 = & V_7 -> V_8 [ 1 ] ;
V_32 = V_16 -> V_32 +
( V_28 * V_12 -> V_8 [ 1 ] . V_33 ) +
( V_29 * V_16 -> V_34 / V_12 -> V_8 [ 1 ] . V_35 ) ;
V_31 -> V_40 = V_16 -> V_26 + V_32 ;
} else {
V_31 -> V_40 = 0 ;
}
}
struct V_41 * F_17 ( struct V_1 * V_2 , int V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_42 >= F_5 ( V_7 -> V_12 -> V_13 ) )
return NULL ;
return V_7 -> V_8 [ V_42 ] . V_9 ;
}
struct V_43 * F_18 (
struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_47 * V_48 = & V_46 -> V_49 . V_48 ;
struct V_43 * V_50 = V_44 ;
if ( ! V_44 ) {
return F_19 ( V_48 , F_20 ( * V_44 ) , V_51 ) ;
}
F_21 (connector, connector_list, head) {
if ( V_50 != V_44 ) {
struct V_52 * V_53 = V_50 -> V_53 ;
struct V_54 * V_55 = V_53 ? V_53 -> V_55 : NULL ;
if ( V_55 && V_55 -> V_2 == V_2 ) {
return V_50 ;
}
}
}
return NULL ;
}
void F_11 ( struct V_1 * V_2 ,
int V_28 , int V_29 , int V_56 , int V_57 )
{
struct V_43 * V_50 = NULL ;
F_22 ( L_2 , V_28 , V_29 , V_56 , V_57 , V_2 ) ;
while ( ( V_50 = F_18 ( V_2 , V_50 ) ) ) {
if ( V_50 -> V_53 && V_50 -> V_53 -> V_55 ) {
struct V_54 * V_55 = V_50 -> V_53 -> V_55 ;
int V_58 = F_23 ( 0 , V_28 - V_55 -> V_28 ) ;
int V_59 = F_23 ( 0 , V_29 - V_55 -> V_29 ) ;
int V_60 = V_56 + ( V_28 - V_55 -> V_28 ) - V_58 ;
int V_61 = V_57 + ( V_29 - V_55 -> V_29 ) - V_59 ;
F_24 ( V_50 , V_58 , V_59 , V_60 , V_61 ) ;
}
}
}
struct V_1 * F_25 ( struct V_45 * V_46 ,
struct V_3 * V_62 , struct V_63 * V_64 )
{
struct V_41 * V_65 [ 4 ] ;
struct V_1 * V_2 ;
int V_25 ;
V_25 = F_26 ( V_46 , V_62 , V_64 -> V_13 ,
V_65 , V_64 -> V_66 ) ;
if ( V_25 )
return F_27 ( V_25 ) ;
V_2 = F_28 ( V_46 , V_64 , V_65 ) ;
if ( F_29 ( V_2 ) ) {
int V_10 , V_11 = F_5 ( V_64 -> V_13 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_8 ( V_65 [ V_10 ] ) ;
return V_2 ;
}
return V_2 ;
}
struct V_1 * F_28 ( struct V_45 * V_46 ,
struct V_63 * V_64 , struct V_41 * * V_65 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = NULL ;
const struct V_12 * V_12 = NULL ;
int V_25 , V_10 , V_11 = F_5 ( V_64 -> V_13 ) ;
F_6 ( L_3 ,
V_46 , V_64 , V_64 -> V_67 , V_64 -> V_68 ,
( char * ) & V_64 -> V_13 ) ;
for ( V_10 = 0 ; V_10 < F_30 ( V_69 ) ; V_10 ++ ) {
if ( V_69 [ V_10 ] . V_13 == V_64 -> V_13 ) {
V_12 = & V_69 [ V_10 ] ;
break;
}
}
if ( ! V_12 ) {
F_31 ( V_46 -> V_46 , L_4 ,
( char * ) & V_64 -> V_13 ) ;
V_25 = - V_70 ;
goto V_27;
}
V_7 = F_32 ( sizeof( * V_7 ) , V_71 ) ;
if ( ! V_7 ) {
F_31 ( V_46 -> V_46 , L_5 ) ;
V_25 = - V_72 ;
goto V_27;
}
V_2 = & V_7 -> V_14 ;
V_25 = F_33 ( V_46 , V_2 , & V_73 ) ;
if ( V_25 ) {
F_31 ( V_46 -> V_46 , L_6 , V_25 ) ;
goto V_27;
}
F_6 ( L_7 , V_2 -> V_14 . V_15 , V_2 ) ;
V_7 -> V_12 = V_12 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
int V_74 , V_34 = V_64 -> V_75 [ V_10 ] ;
if ( V_34 < ( V_64 -> V_67 * V_12 -> V_8 [ V_10 ] . V_33 ) ) {
F_31 ( V_46 -> V_46 , L_8 ,
V_34 , V_64 -> V_67 * V_12 -> V_8 [ V_10 ] . V_33 ) ;
V_25 = - V_70 ;
goto V_27;
}
V_74 = V_34 * V_64 -> V_68 / V_12 -> V_8 [ V_10 ] . V_35 ;
if ( V_74 > ( V_65 [ V_10 ] -> V_74 - V_64 -> V_76 [ V_10 ] ) ) {
F_31 ( V_46 -> V_46 , L_9 ,
V_65 [ V_10 ] -> V_74 - V_64 -> V_76 [ V_10 ] , V_74 ) ;
V_25 = - V_70 ;
goto V_27;
}
V_16 -> V_9 = V_65 [ V_10 ] ;
V_16 -> V_32 = V_64 -> V_76 [ V_10 ] ;
V_16 -> V_34 = V_64 -> V_75 [ V_10 ] ;
V_16 -> V_26 = V_34 ;
}
F_34 ( V_2 , V_64 ) ;
return V_2 ;
V_27:
if ( V_2 ) {
F_4 ( V_2 ) ;
}
return F_27 ( V_25 ) ;
}
