static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 | V_4 ) ;
}
static T_2 F_3 ( int V_5 , void * V_6 )
{
int V_7 ;
struct V_8 * V_9 = V_6 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_1 ;
F_5 ( & V_13 -> V_14 ) ;
V_13 -> V_15 [ 0 ] = V_16 | V_4 ;
V_7 = F_6 ( V_2 , V_13 -> V_15 , 1 , V_13 -> V_17 ,
F_7 ( V_18 ) - 1 ) ;
if ( V_7 < 0 )
goto V_19;
F_8 ( V_11 , V_13 -> V_17 ,
V_9 -> V_20 ) ;
V_19:
F_9 ( & V_13 -> V_14 ) ;
F_10 ( V_11 -> V_21 ) ;
return V_22 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_23 const * V_24 ,
int * V_25 , int * V_26 , long V_27 )
{
int V_7 ;
T_1 V_28 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
switch ( V_27 ) {
case V_29 :
V_7 = F_1 ( V_13 -> V_1 , V_24 -> V_30 ) ;
if ( V_7 < 0 )
return - V_31 ;
* V_25 = F_12 ( V_7 >> V_32 , 5 ) ;
return V_33 ;
case V_34 :
V_7 = F_1 ( V_13 -> V_1 , V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
V_28 = V_7 & V_36 ;
* V_25 = V_37 [ V_28 ] [ 0 ] ;
* V_26 = V_37 [ V_28 ] [ 1 ] ;
return V_38 ;
}
return - V_31 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_23 const * V_24 ,
int V_25 , int V_26 , long V_27 )
{
int V_39 ;
int V_7 ;
int V_40 = - 1 ;
struct V_12 * V_13 = F_4 ( V_11 ) ;
switch ( V_27 ) {
case V_34 :
for ( V_39 = 0 ; V_39 < F_7 ( V_37 ) ; V_39 ++ )
if ( V_25 == V_37 [ V_39 ] [ 0 ] &&
V_26 == V_37 [ V_39 ] [ 1 ] ) {
V_40 = V_39 ;
break;
}
if ( V_40 < 0 )
return - V_31 ;
F_5 ( & V_13 -> V_14 ) ;
V_13 -> V_15 [ 0 ] = V_35 ;
V_13 -> V_15 [ 1 ] = V_40 ;
V_7 = F_14 ( V_13 -> V_1 , V_13 -> V_15 ,
sizeof( V_13 -> V_15 ) ) ;
if ( V_7 < 0 )
F_15 ( & V_13 -> V_1 -> V_41 ,
L_1 ) ;
F_9 ( & V_13 -> V_14 ) ;
return 0 ;
}
return - V_31 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , V_42 ) ;
if ( V_7 != V_43 )
return - V_44 ;
V_7 = F_1 ( V_2 , V_45 ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 == V_46 )
return F_1 ( V_2 , V_45 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , V_45 ) ;
if ( V_7 < 0 )
return V_7 ;
else if ( V_7 == V_47 )
return F_1 ( V_2 , V_45 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_19 ( & V_2 -> V_41 , sizeof( * V_13 ) ) ;
if ( ! V_11 ) {
F_15 ( & V_2 -> V_41 , L_2 ) ;
return - V_48 ;
}
V_13 = F_4 ( V_11 ) ;
V_13 -> V_1 = V_2 ;
F_20 ( V_2 , V_11 ) ;
F_21 ( & V_13 -> V_14 ) ;
V_11 -> V_41 . V_49 = & V_2 -> V_41 ;
V_11 -> V_50 = & V_51 ;
V_11 -> V_52 = V_53 ;
V_11 -> V_54 = V_55 ;
V_11 -> V_56 = V_18 ;
V_11 -> V_57 = F_7 ( V_18 ) ;
V_11 -> V_58 = V_59 ;
V_7 = F_16 ( V_13 -> V_1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_22 ( V_11 , V_60 ,
F_3 , NULL ) ;
if ( V_7 < 0 ) {
F_15 ( & V_2 -> V_41 , L_3 ) ;
goto V_61;
}
V_7 = F_23 ( V_11 ) ;
if ( V_7 < 0 ) {
F_15 ( & V_2 -> V_41 , L_4 ) ;
F_24 ( V_11 ) ;
goto V_61;
}
return 0 ;
V_61:
return F_17 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_26 ( V_2 ) ;
F_27 ( V_11 ) ;
F_24 ( V_11 ) ;
return F_17 ( V_2 ) ;
}
static int F_28 ( struct V_62 * V_41 )
{
struct V_12 * V_13 =
F_4 ( F_26 ( F_29 ( V_41 ) ) ) ;
return F_1 ( V_13 -> V_1 , V_45 ) ;
}
static int F_30 ( struct V_62 * V_41 )
{
struct V_12 * V_13 =
F_4 ( F_26 ( F_29 ( V_41 ) ) ) ;
return F_1 ( V_13 -> V_1 , V_45 ) ;
}
