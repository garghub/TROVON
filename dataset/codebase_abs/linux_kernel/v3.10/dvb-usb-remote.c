static unsigned int
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
unsigned int V_6 ;
unsigned int V_7 ;
if ( V_2 -> V_8 & V_9 ) {
V_6 = V_2 -> V_6 ;
} else {
if ( F_2 ( V_2 , & V_7 ) )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_7 == V_7 )
break;
if ( V_6 >= V_5 ) {
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_10 == V_11 ||
V_4 [ V_6 ] . V_10 == V_12 ) {
break;
}
}
}
}
return V_6 ;
}
static int F_3 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_3 * V_4 = V_16 -> V_17 . V_18 . V_19 . V_3 ;
unsigned int V_5 = V_16 -> V_17 . V_18 . V_19 . V_20 ;
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_6 >= V_5 )
return - V_21 ;
V_2 -> V_10 = V_4 [ V_6 ] . V_10 ;
if ( V_2 -> V_10 == V_12 )
V_2 -> V_10 = V_11 ;
V_2 -> V_22 = sizeof( V_4 [ V_6 ] . V_7 ) ;
memcpy ( & V_2 -> V_7 , & V_4 [ V_6 ] . V_7 , V_2 -> V_22 ) ;
V_2 -> V_6 = V_6 ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
const struct V_1 * V_2 ,
unsigned int * V_23 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_3 * V_4 = V_16 -> V_17 . V_18 . V_19 . V_3 ;
unsigned int V_5 = V_16 -> V_17 . V_18 . V_19 . V_20 ;
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_6 >= V_5 )
return - V_21 ;
* V_23 = V_4 [ V_6 ] . V_10 ;
V_4 -> V_10 = V_2 -> V_10 ;
F_6 ( V_2 -> V_10 , V_14 -> V_24 ) ;
if ( * V_23 != V_11 ) {
F_7 ( * V_23 , V_14 -> V_24 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_10 == * V_23 ) {
F_6 ( * V_23 , V_14 -> V_24 ) ;
break;
}
}
}
return 0 ;
}
static void F_8 ( struct V_25 * V_26 )
{
struct V_15 * V_16 =
F_9 ( V_26 , struct V_15 , V_27 . V_26 ) ;
T_1 V_28 ;
int V_29 ;
if ( V_30 )
return;
if ( V_16 -> V_17 . V_18 . V_19 . V_31 ( V_16 , & V_28 , & V_29 ) ) {
F_10 ( L_1 ) ;
goto V_32;
}
switch ( V_29 ) {
case V_33 :
break;
case V_34 :
F_11 ( L_2 ) ;
V_16 -> V_35 = V_28 ;
case V_36 :
F_11 ( L_3 ) ;
F_12 ( V_16 -> V_13 , V_37 , V_28 , 1 ) ;
F_13 ( V_16 -> V_13 ) ;
F_12 ( V_16 -> V_13 , V_37 , V_16 -> V_35 , 0 ) ;
F_13 ( V_16 -> V_13 ) ;
break;
default:
break;
}
V_32:
F_14 ( & V_16 -> V_27 , F_15 ( V_16 -> V_17 . V_18 . V_19 . V_38 ) ) ;
}
static int F_16 ( struct V_15 * V_16 )
{
int V_39 , F_10 , V_38 ;
struct V_13 * V_13 ;
V_13 = F_17 () ;
if ( ! V_13 )
return - V_40 ;
V_13 -> V_41 [ 0 ] = F_18 ( V_37 ) ;
V_13 -> V_42 = L_4 ;
V_13 -> V_43 = V_16 -> V_44 ;
F_19 ( V_16 -> V_45 , & V_13 -> V_46 ) ;
V_13 -> V_14 . V_47 = & V_16 -> V_45 -> V_14 ;
V_16 -> V_13 = V_13 ;
V_16 -> V_48 = NULL ;
V_13 -> V_49 = F_3 ;
V_13 -> V_50 = F_5 ;
F_11 ( L_5 , V_16 -> V_17 . V_18 . V_19 . V_20 ) ;
for ( V_39 = 0 ; V_39 < V_16 -> V_17 . V_18 . V_19 . V_20 ; V_39 ++ ) {
F_11 ( L_6 ,
V_16 -> V_17 . V_18 . V_19 . V_3 [ V_39 ] . V_10 , V_39 ) ;
F_20 ( V_16 -> V_17 . V_18 . V_19 . V_3 [ V_39 ] . V_10 , V_13 -> V_24 ) ;
}
V_13 -> V_51 [ V_52 ] = V_16 -> V_17 . V_18 . V_19 . V_38 ;
V_13 -> V_51 [ V_53 ] = V_16 -> V_17 . V_18 . V_19 . V_38 + 150 ;
F_21 ( V_13 , V_16 ) ;
F_10 = F_22 ( V_13 ) ;
if ( F_10 )
F_23 ( V_13 ) ;
V_38 = V_16 -> V_17 . V_18 . V_19 . V_38 ;
F_24 ( & V_16 -> V_27 , F_8 ) ;
F_25 ( L_7 , V_38 ) ;
F_14 ( & V_16 -> V_27 ,
F_15 ( V_38 ) ) ;
V_16 -> V_29 |= V_54 ;
return F_10 ;
}
static void F_26 ( struct V_25 * V_26 )
{
struct V_15 * V_16 =
F_9 ( V_26 , struct V_15 , V_27 . V_26 ) ;
int F_10 ;
if ( V_30 || V_16 -> V_17 . V_18 . V_55 . V_56 )
return;
F_10 = V_16 -> V_17 . V_18 . V_55 . V_31 ( V_16 ) ;
if ( F_10 )
F_10 ( L_8 , F_10 ) ;
F_14 ( & V_16 -> V_27 ,
F_15 ( V_16 -> V_17 . V_18 . V_55 . V_38 ) ) ;
}
static int F_27 ( struct V_15 * V_16 )
{
int F_10 , V_38 ;
struct V_48 * V_14 ;
V_14 = F_28 () ;
if ( ! V_14 )
return - V_40 ;
V_14 -> V_57 = V_16 -> V_17 . V_18 . V_55 . V_58 ;
V_14 -> V_59 = V_16 -> V_17 . V_18 . V_55 . V_60 ;
V_14 -> V_61 = V_16 -> V_17 . V_18 . V_55 . V_61 ;
V_14 -> V_62 = V_16 -> V_17 . V_18 . V_55 . V_62 ;
V_14 -> V_63 = V_16 -> V_17 . V_18 . V_55 . V_63 ;
F_19 ( V_16 -> V_45 , & V_14 -> V_64 ) ;
V_14 -> V_65 = L_4 ;
V_14 -> V_66 = V_16 -> V_44 ;
V_14 -> V_14 . V_47 = & V_16 -> V_45 -> V_14 ;
V_14 -> V_67 = V_16 ;
F_10 = F_29 ( V_14 ) ;
if ( F_10 < 0 ) {
F_30 ( V_14 ) ;
return F_10 ;
}
V_16 -> V_13 = NULL ;
V_16 -> V_48 = V_14 ;
if ( ! V_16 -> V_17 . V_18 . V_55 . V_31 || V_16 -> V_17 . V_18 . V_55 . V_56 )
return 0 ;
F_24 ( & V_16 -> V_27 , F_26 ) ;
V_38 = V_16 -> V_17 . V_18 . V_55 . V_38 ;
F_25 ( L_7 , V_38 ) ;
F_14 ( & V_16 -> V_27 ,
F_15 ( V_38 ) ) ;
return 0 ;
}
int F_31 ( struct V_15 * V_16 )
{
int F_10 ;
if ( V_30 )
return 0 ;
if ( V_16 -> V_17 . V_18 . V_19 . V_3 && V_16 -> V_17 . V_18 . V_19 . V_31 )
V_16 -> V_17 . V_18 . V_68 = V_69 ;
else if ( V_16 -> V_17 . V_18 . V_55 . V_60 )
V_16 -> V_17 . V_18 . V_68 = V_70 ;
else
return 0 ;
F_32 ( V_16 -> V_45 , V_16 -> V_44 , sizeof( V_16 -> V_44 ) ) ;
F_33 ( V_16 -> V_44 , L_9 , sizeof( V_16 -> V_44 ) ) ;
if ( V_16 -> V_17 . V_18 . V_19 . V_38 < 40 )
V_16 -> V_17 . V_18 . V_19 . V_38 = 100 ;
if ( V_16 -> V_17 . V_18 . V_68 == V_69 )
F_10 = F_16 ( V_16 ) ;
else
F_10 = F_27 ( V_16 ) ;
if ( F_10 )
return F_10 ;
V_16 -> V_29 |= V_54 ;
return 0 ;
}
int F_34 ( struct V_15 * V_16 )
{
if ( V_16 -> V_29 & V_54 ) {
F_35 ( & V_16 -> V_27 ) ;
if ( V_16 -> V_17 . V_18 . V_68 == V_69 )
F_36 ( V_16 -> V_13 ) ;
else
F_37 ( V_16 -> V_48 ) ;
}
V_16 -> V_29 &= ~ V_54 ;
return 0 ;
}
int F_38 ( struct V_15 * V_16 ,
T_2 V_71 [ 5 ] , T_1 * V_28 , int * V_29 )
{
int V_39 ;
struct V_3 * V_4 = V_16 -> V_17 . V_18 . V_19 . V_3 ;
* V_28 = 0 ;
* V_29 = V_33 ;
switch ( V_71 [ 0 ] ) {
case V_72 :
break;
case V_73 :
if ( ( T_2 ) ~ V_71 [ 1 ] != V_71 [ 2 ] ||
( T_2 ) ~ V_71 [ 3 ] != V_71 [ 4 ] ) {
F_39 ( L_10 ) ;
break;
}
for ( V_39 = 0 ; V_39 < V_16 -> V_17 . V_18 . V_19 . V_20 ; V_39 ++ )
if ( F_40 ( & V_4 [ V_39 ] ) == V_71 [ 1 ] &&
F_41 ( & V_4 [ V_39 ] ) == V_71 [ 3 ] ) {
* V_28 = V_4 [ V_39 ] . V_10 ;
* V_29 = V_34 ;
return 0 ;
}
F_39 ( L_11 ) ;
break;
case V_74 :
* V_29 = V_36 ;
break;
default:
F_39 ( L_12 , V_71 [ 0 ] ) ;
break;
}
return 0 ;
}
