static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = ! ! V_3 ;
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_9 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_10 = ! ! V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_11 ,
T_1 V_12 )
{
#ifdef F_5
int V_4 ;
if ( V_11 && ( V_12 & V_7 ) ) {
F_6 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_10 ) {
V_4 = F_1 ( V_2 ,
V_7 ) ;
if ( V_4 < 0 )
goto V_14;
} else {
V_2 -> V_15 = true ;
}
F_7 ( & V_2 -> V_13 ) ;
}
if ( V_11 && ( V_12 & V_9 ) ) {
F_6 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_8 ) {
V_4 = F_3 ( V_2 , V_9 ) ;
if ( V_4 < 0 )
goto V_14;
} else {
V_2 -> V_16 = true ;
}
F_7 ( & V_2 -> V_13 ) ;
}
if ( V_11 ) {
V_4 = F_8 ( & V_2 -> V_17 -> V_18 ) ;
if ( V_4 < 0 )
F_9 ( & V_2 -> V_17 -> V_18 ) ;
} else {
F_10 ( & V_2 -> V_17 -> V_18 ) ;
V_4 = F_11 ( & V_2 -> V_17 -> V_18 ) ;
}
return V_4 ;
V_14:
F_7 ( & V_2 -> V_13 ) ;
return V_4 ;
#endif
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_21 const * V_22 , int * V_23 ,
int * V_24 , long V_12 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
int V_4 ;
T_1 V_25 ;
unsigned int V_26 ;
T_2 V_27 ;
switch ( V_12 ) {
case V_28 :
switch ( V_22 -> type ) {
case V_29 :
V_25 = V_7 ;
V_4 = F_4 ( V_2 , true , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_14 ( V_2 -> V_5 , V_30 ,
& V_27 , 2 ) ;
if ( V_4 < 0 )
goto V_31;
* V_23 = F_15 ( V_27 ) ;
V_4 = F_4 ( V_2 , false , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_32 :
V_25 = V_9 ;
V_4 = F_4 ( V_2 , true , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_16 ( V_2 -> V_5 , V_33 ,
& V_26 ) ;
if ( V_4 < 0 )
goto V_31;
* V_23 = V_26 ;
V_4 = F_4 ( V_2 , false , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
default:
return - V_34 ;
}
return V_35 ;
case V_36 :
V_4 = F_16 ( V_2 -> V_5 , V_6 , & V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_23 = 0 ;
V_26 = ( V_26 & V_37 ) ;
* V_24 = V_38 [ V_26 >> 4 ] ;
return V_39 ;
default:
return - V_34 ;
}
V_31:
F_4 ( V_2 , false , V_25 ) ;
return V_4 ;
}
static int F_17 ( struct V_19 * V_20 ,
struct V_21 const * V_22 , int V_23 ,
int V_24 , long V_12 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
int V_40 , V_4 , V_41 ;
unsigned int V_26 ;
switch ( V_12 ) {
case V_36 :
V_4 = F_16 ( V_2 -> V_5 , V_6 , & V_26 ) ;
if ( V_23 != 0 || V_4 < 0 )
return - V_34 ;
for ( V_40 = 0 ; V_40 < F_18 ( V_38 ) ; V_40 ++ ) {
if ( V_24 == V_38 [ V_40 ] ) {
V_41 = V_40 << V_42 ;
return F_2 ( V_2 -> V_5 ,
V_6 ,
V_37 ,
V_41 ) ;
}
}
break;
default:
break;
}
return - V_34 ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
int V_40 , V_4 ;
for ( V_40 = 0 ; V_40 < F_18 ( V_43 ) ; V_40 ++ ) {
V_4 = F_20 ( V_2 -> V_5 , V_43 [ V_40 ] . V_44 , V_43 [ V_40 ] . V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , T_1 V_45 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
int V_4 ;
F_6 ( & V_2 -> V_13 ) ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 < 0 )
goto V_46;
V_4 = F_3 ( V_2 , V_45 ) ;
V_46:
F_7 ( & V_2 -> V_13 ) ;
return V_4 ;
}
static int F_22 ( struct V_47 * V_17 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_4 ;
V_20 = F_23 ( & V_17 -> V_18 ,
sizeof( struct V_1 ) ) ;
if ( ! V_20 )
return - V_50 ;
V_2 = F_13 ( V_20 ) ;
F_24 ( V_17 , V_20 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = F_25 ( V_17 , & V_51 ) ;
if ( F_26 ( V_2 -> V_5 ) )
return F_27 ( V_2 -> V_5 ) ;
F_28 ( & V_2 -> V_13 ) ;
V_20 -> V_18 . V_52 = & V_17 -> V_18 ;
V_20 -> V_53 = & V_54 ;
V_20 -> V_55 = V_56 ;
V_20 -> V_57 = V_58 ;
V_20 -> V_59 = F_18 ( V_58 ) ;
V_20 -> V_60 = V_61 ;
V_4 = F_19 ( V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_21 ( V_20 , V_62 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_29 ( & V_17 -> V_18 ) ;
if ( V_4 < 0 )
goto V_63;
F_30 ( & V_17 -> V_18 ) ;
F_31 ( & V_17 -> V_18 ,
V_64 ) ;
F_32 ( & V_17 -> V_18 ) ;
V_4 = F_33 ( V_20 ) ;
if ( V_4 < 0 )
goto V_63;
return 0 ;
V_63:
F_21 ( V_20 , V_65 ) ;
return V_4 ;
}
static int F_34 ( struct V_47 * V_17 )
{
struct V_19 * V_20 = F_35 ( V_17 ) ;
F_36 ( V_20 ) ;
F_37 ( & V_17 -> V_18 ) ;
F_38 ( & V_17 -> V_18 ) ;
return F_21 ( V_20 , V_65 ) ;
}
static int F_39 ( struct V_66 * V_18 )
{
struct V_19 * V_20 = F_35 ( F_40 ( V_18 ) ) ;
return F_21 ( V_20 , V_65 ) ;
}
static int F_41 ( struct V_66 * V_18 )
{
struct V_19 * V_20 = F_35 ( F_40 ( V_18 ) ) ;
return F_21 ( V_20 , V_62 ) ;
}
static int F_42 ( struct V_66 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_35 ( F_40 ( V_18 ) ) ) ;
F_6 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_15 ) {
F_1 ( V_2 , V_7 ) ;
V_2 -> V_15 = false ;
}
if ( V_2 -> V_16 ) {
F_3 ( V_2 , V_9 ) ;
V_2 -> V_16 = false ;
}
F_7 ( & V_2 -> V_13 ) ;
return 0 ;
}
