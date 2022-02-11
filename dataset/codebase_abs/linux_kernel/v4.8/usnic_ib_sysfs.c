static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
unsigned short V_9 ;
F_3 ( & V_6 -> V_10 ) ;
V_9 = V_6 -> V_11 -> V_12 ;
F_4 ( & V_6 -> V_10 ) ;
return F_5 ( V_4 , V_13 , L_1 , V_9 ) ;
}
static T_1
F_6 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 ;
char * V_14 ;
unsigned V_15 ;
unsigned V_16 ;
enum V_17 V_18 ;
V_6 = F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
V_14 = V_4 ;
V_15 = V_13 ;
F_3 ( & V_6 -> V_10 ) ;
if ( F_7 ( & V_6 -> V_19 . V_20 ) > 0 ) {
char * V_21 ;
V_21 = V_6 -> V_11 -> V_22 -> V_23 ;
if ( strncmp ( V_21 , L_2 , 8 ) == 0 )
V_21 += 8 ;
V_16 = F_5 ( V_14 , V_15 ,
L_3 ,
V_6 -> V_7 . V_23 ,
V_21 ,
F_8 ( V_6 -> V_11 -> V_24 ) ,
F_9 ( V_6 -> V_11 -> V_24 ) ,
F_10 ( V_6 -> V_25 ) ,
V_6 -> V_26 -> V_27 ,
F_7 ( & V_6 -> V_19 . V_20 ) ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
for ( V_18 = V_28 ;
V_18 < V_29 ;
V_18 ++ ) {
if ( V_6 -> V_30 [ V_18 ] == 0 )
continue;
V_16 = F_5 ( V_14 , V_15 , L_4 ,
V_6 -> V_30 [ V_18 ] ,
F_12 ( V_18 ) ,
( V_18 < ( V_29 - 1 ) ) ?
L_5 : L_6 ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
}
V_16 = F_5 ( V_14 , V_15 , L_7 ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
} else {
V_16 = F_5 ( V_14 , V_15 , L_8 ,
V_6 -> V_7 . V_23 ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
}
F_4 ( & V_6 -> V_10 ) ;
return V_14 - V_4 ;
}
static T_1
F_13 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
return F_5 ( V_4 , V_13 , L_9 ,
F_10 ( V_6 -> V_25 ) ) ;
}
static T_1
F_14 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
return F_5 ( V_4 , V_13 , L_10 ,
F_7 ( & V_6 -> V_19 . V_20 ) ) ;
}
static T_1
F_15 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 ;
int V_31 ;
V_6 = F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
V_31 = F_16 ( V_6 -> V_30 [ V_32 ] ,
V_6 -> V_30 [ V_33 ] ) ;
return F_5 ( V_4 , V_13 ,
L_11 , V_31 ) ;
}
static T_1
F_17 ( struct V_1 * V_1 , struct V_2 * V_3 ,
char * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_1 , struct V_5 , V_7 . V_8 ) ;
return F_5 ( V_4 , V_13 , L_11 ,
V_6 -> V_30 [ V_34 ] ) ;
}
static T_1
F_18 ( struct V_35 * V_36 , struct V_37 * V_3 , char * V_4 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_39 = F_2 ( V_36 , struct V_38 , V_36 ) ;
V_41 = F_2 ( V_3 , struct V_40 , V_3 ) ;
return V_41 -> V_42 ( V_39 , V_4 ) ;
}
static T_1 F_19 ( struct V_38 * V_39 , char * V_4 )
{
return F_5 ( V_4 , V_13 , L_12 , V_39 -> V_43 ) ;
}
static T_1 F_20 ( struct V_38 * V_39 , char * V_4 )
{
int V_44 , V_45 , V_16 ;
int V_15 ;
char * V_14 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_15 = V_13 ;
V_14 = V_4 ;
V_16 = F_5 ( V_14 , V_15 ,
L_13 ,
V_39 -> V_50 . V_51 ,
F_21 ( V_39 -> V_52 ) ,
V_39 -> V_53 ,
F_22 ( V_39 -> V_54 -> V_55 ) ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
for ( V_44 = 0 ; V_39 -> V_56 [ V_44 ] ; V_44 ++ ) {
V_47 = V_39 -> V_56 [ V_44 ] ;
for ( V_45 = 0 ; V_45 < V_47 -> V_57 ; V_45 ++ ) {
V_49 = V_47 -> V_58 [ V_45 ] ;
V_16 = F_5 ( V_14 , V_15 , L_14 ,
F_12 ( V_49 -> type ) ,
V_49 -> V_59 ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
}
}
V_16 = F_5 ( V_14 , V_15 , L_7 ) ;
F_11 ( V_16 , V_14 , V_15 ) ;
return V_14 - V_4 ;
}
int F_23 ( struct V_5 * V_6 )
{
int V_44 ;
int V_60 ;
for ( V_44 = 0 ; V_44 < F_24 ( V_61 ) ; ++ V_44 ) {
V_60 = F_25 ( & V_6 -> V_7 . V_8 ,
V_61 [ V_44 ] ) ;
if ( V_60 ) {
F_26 ( L_15 ,
V_44 , V_6 -> V_7 . V_23 , V_60 ) ;
return - V_62 ;
}
}
F_27 ( & V_6 -> V_7 . V_8 . V_36 ) ;
V_6 -> V_63 = F_28 ( L_16 ,
& V_6 -> V_7 . V_8 . V_36 ) ;
if ( V_6 -> V_63 == NULL ) {
F_29 ( & V_6 -> V_7 . V_8 . V_36 ) ;
return - V_64 ;
}
return 0 ;
}
void F_30 ( struct V_5 * V_6 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_24 ( V_61 ) ; ++ V_44 ) {
F_31 ( & V_6 -> V_7 . V_8 ,
V_61 [ V_44 ] ) ;
}
F_29 ( V_6 -> V_63 ) ;
}
void F_32 ( struct V_38 * V_39 )
{
struct V_5 * V_6 ;
int V_60 ;
V_6 = V_39 -> V_54 -> V_65 ;
V_60 = F_33 ( & V_39 -> V_36 , & V_66 ,
F_27 ( V_6 -> V_63 ) ,
L_17 , V_39 -> V_67 ) ;
if ( V_60 ) {
F_29 ( V_6 -> V_63 ) ;
return;
}
}
void F_34 ( struct V_38 * V_39 )
{
struct V_5 * V_6 ;
V_6 = V_39 -> V_54 -> V_65 ;
F_29 ( & V_39 -> V_36 ) ;
F_29 ( V_6 -> V_63 ) ;
}
