static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_1 ,
V_8 [ 0 ] . V_9 * V_7 -> V_10 ,
V_8 [ 1 ] . V_9 * V_7 -> V_10 ,
V_8 [ 2 ] . V_9 * V_7 -> V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_8 [ 0 ] . V_11 ,
V_8 [ 3 ] . V_11 ) ;
}
static int F_5 ( struct V_12 * V_13 , unsigned int V_14 ,
unsigned int V_15 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
T_2 V_16 ;
V_16 = F_6 ( V_14 ) | V_17 | V_15 ;
V_16 <<= V_18 ;
V_7 -> V_19 [ 0 ] . V_20 = F_7 ( V_16 ) ;
return F_8 ( V_7 -> V_21 , & V_7 -> V_19 [ 0 ] . V_22 [ 1 ] , 3 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
T_2 V_16 ;
V_16 = F_10 ( V_23 ) ;
V_16 <<= V_24 ;
V_7 -> V_19 [ 0 ] . V_20 = F_7 ( V_16 ) ;
return F_8 ( V_7 -> V_21 , & V_7 -> V_19 [ 0 ] . V_22 [ 0 ] , 4 ) ;
}
static int F_11 ( struct V_12 * V_13 , unsigned int V_25 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
int V_26 ;
T_2 V_16 ;
struct V_27 V_28 [] = {
{
. V_29 = & V_7 -> V_19 [ 0 ] . V_22 [ 0 ] ,
. V_30 = 4 ,
. V_31 = 1 ,
} , {
. V_29 = & V_7 -> V_19 [ 1 ] . V_22 [ 0 ] ,
. V_32 = & V_7 -> V_19 [ 1 ] . V_22 [ 0 ] ,
. V_30 = 4 ,
} ,
} ;
V_16 = F_10 ( F_12 ( V_25 ) ) ;
V_16 <<= V_24 ;
V_7 -> V_19 [ 0 ] . V_20 = F_7 ( V_16 ) ;
V_16 = F_10 ( V_33 ) ;
V_16 <<= V_24 ;
V_7 -> V_19 [ 1 ] . V_20 = F_7 ( V_16 ) ;
V_26 = F_13 ( V_7 -> V_21 , V_28 , F_14 ( V_28 ) ) ;
if ( V_26 < 0 )
return V_26 ;
return F_15 ( V_7 -> V_19 [ 1 ] . V_20 ) & 0xffff ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_34 const * V_25 ,
int * V_15 , int * V_35 , long V_36 )
{
int V_26 , V_11 ;
unsigned long V_37 ;
struct V_6 * V_7 = F_2 ( V_13 ) ;
F_17 ( & V_7 -> V_38 ) ;
switch ( V_36 ) {
case V_39 :
V_26 = F_11 ( V_13 , V_25 -> V_40 ) ;
F_18 ( & V_7 -> V_38 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_15 = V_26 ;
return V_41 ;
case V_42 :
V_37 = V_7 -> V_10 ;
V_37 *= V_8 [ V_7 -> V_43 [ V_25 -> V_40 ] ] . V_9 ;
* V_15 = 0 ;
* V_35 = V_37 ;
F_18 ( & V_7 -> V_38 ) ;
return V_44 ;
case V_45 :
V_11 = V_8 [ V_7 -> V_43 [ V_25 -> V_40 ] ] . V_11 ;
* V_15 = V_11 ;
F_18 ( & V_7 -> V_38 ) ;
return V_41 ;
}
F_18 ( & V_7 -> V_38 ) ;
return - V_46 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_34 const * V_25 ,
enum V_47 V_43 )
{
unsigned int V_16 ;
int V_26 ;
V_16 = F_20 ( V_25 -> V_40 ) ;
V_26 = F_5 ( V_13 , V_16 , V_43 ) ;
return V_26 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_34 const * V_25 ,
int V_15 , int V_35 , long V_48 )
{
struct V_6 * V_7 = F_2 ( V_13 ) ;
unsigned int V_9 = 0 ;
int V_26 = - V_46 , V_49 , V_11 = 0 ;
F_17 ( & V_7 -> V_38 ) ;
switch ( V_48 ) {
case V_42 :
V_11 = V_8 [ V_7 -> V_43 [ V_25 -> V_40 ] ] . V_11 ;
if ( V_11 == 0 && V_35 == V_8 [ 0 ] . V_9 * V_7 -> V_10 ) {
F_18 ( & V_7 -> V_38 ) ;
return - V_46 ;
}
for ( V_49 = 0 ; V_49 < F_14 ( V_8 ) ; V_49 ++ )
if ( V_35 == V_8 [ V_49 ] . V_9 * V_7 -> V_10 &&
V_11 == V_8 [ V_49 ] . V_11 ) {
V_26 = F_19 ( V_13 , V_25 ,
V_8 [ V_49 ] . V_50 ) ;
break;
}
break;
case V_45 :
if ( ! ( V_8 [ 0 ] . V_11 == V_15 ||
V_8 [ 3 ] . V_11 == V_15 ) ) {
F_18 ( & V_7 -> V_38 ) ;
return - V_46 ;
}
if ( V_15 == 0 &&
V_7 -> V_43 [ V_25 -> V_40 ] == V_51 ) {
F_18 ( & V_7 -> V_38 ) ;
return - V_46 ;
}
V_9 = V_8 [ V_7 -> V_43 [ V_25 -> V_40 ] ] . V_9 ;
for ( V_49 = 0 ; V_49 < F_14 ( V_8 ) ; V_49 ++ )
if ( V_15 == V_8 [ V_49 ] . V_11 &&
V_9 == V_8 [ V_49 ] . V_9 ) {
V_26 = F_19 ( V_13 , V_25 ,
V_8 [ V_49 ] . V_50 ) ;
break;
}
break;
}
if ( ! V_26 )
V_7 -> V_43 [ V_25 -> V_40 ] = V_8 [ V_49 ] . V_43 ;
F_18 ( & V_7 -> V_38 ) ;
return V_26 ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_34 const * V_25 ,
long V_48 )
{
switch ( V_48 ) {
case V_42 :
return V_44 ;
case V_45 :
return V_41 ;
}
return - V_46 ;
}
static int F_23 ( struct V_52 * V_21 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_26 ;
V_13 = F_24 ( & V_21 -> V_2 , sizeof( * V_7 ) ) ;
if ( V_13 == NULL )
return - V_53 ;
V_7 = F_2 ( V_13 ) ;
V_7 -> V_50 = F_25 ( & V_21 -> V_2 , L_3 ) ;
if ( ! F_26 ( V_7 -> V_50 ) ) {
V_26 = F_27 ( V_7 -> V_50 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_28 ( V_7 -> V_50 ) ;
if ( V_26 < 0 )
goto V_54;
V_7 -> V_10 = V_26 / 1000 ;
} else {
V_7 -> V_10 = V_55 ;
}
V_7 -> V_56 = & V_57 [ F_29 ( V_21 ) -> V_58 ] ;
V_21 -> V_59 = V_60 ;
F_30 ( V_21 , V_13 ) ;
V_7 -> V_21 = V_21 ;
V_13 -> V_61 = F_29 ( V_21 ) -> V_61 ;
V_13 -> V_2 . V_62 = & V_21 -> V_2 ;
V_13 -> V_2 . V_63 = V_21 -> V_2 . V_63 ;
V_13 -> V_64 = V_65 ;
V_13 -> V_66 = V_7 -> V_56 -> V_66 ;
V_13 -> V_67 = V_7 -> V_56 -> V_67 ;
V_13 -> V_68 = & V_69 ;
F_9 ( V_13 ) ;
F_31 ( & V_7 -> V_38 ) ;
V_26 = F_32 ( V_13 ) ;
if ( V_26 )
goto V_54;
return 0 ;
V_54:
if ( ! F_26 ( V_7 -> V_50 ) )
F_33 ( V_7 -> V_50 ) ;
return V_26 ;
}
static int F_34 ( struct V_52 * V_21 )
{
struct V_12 * V_13 = F_35 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_13 ) ;
F_36 ( V_13 ) ;
if ( ! F_26 ( V_7 -> V_50 ) )
F_33 ( V_7 -> V_50 ) ;
return 0 ;
}
