static inline const
struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
return & V_3 -> V_5 -> V_6 [ V_4 ] ;
}
static void F_2 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
F_4 ( & V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 , V_13 ;
T_1 V_14 ;
if ( V_8 -> V_5 -> V_15 ) {
V_13 = F_6 ( V_11 -> V_16 ) ;
if ( V_13 < 0 )
F_7 ( V_11 -> V_16 , L_1 ,
V_13 ) ;
}
for ( V_12 = 0 ; V_12 < V_8 -> V_5 -> V_17 ; V_12 ++ ) {
V_14 = V_8 -> V_5 -> V_18 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_8 -> V_5 -> V_21 )
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] , ~ V_8 -> V_23 [ V_12 ] ) ;
else
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] , V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_16 , L_2 ,
V_14 ) ;
V_14 = V_8 -> V_5 -> V_24 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_8 -> V_25 ) {
if ( V_8 -> V_5 -> V_26 )
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] ,
~ V_8 -> V_25 [ V_12 ] ) ;
else
V_13 = F_8 ( V_8 -> V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] ,
V_8 -> V_25 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_16 ,
L_3 ,
V_14 , V_13 ) ;
}
if ( ! V_8 -> V_5 -> V_27 )
continue;
if ( V_8 -> V_23 [ V_12 ] && V_8 -> V_5 -> V_28 ) {
V_14 = V_8 -> V_5 -> V_28 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
V_13 = F_9 ( V_11 , V_14 , V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_8 -> V_11 -> V_16 , L_4 ,
V_14 , V_13 ) ;
}
}
if ( V_8 -> V_5 -> V_15 )
F_10 ( V_11 -> V_16 ) ;
if ( V_8 -> V_29 < 0 )
for ( V_12 = V_8 -> V_29 ; V_12 < 0 ; V_12 ++ )
F_11 ( V_8 -> V_4 , 0 ) ;
else if ( V_8 -> V_29 > 0 )
for ( V_12 = 0 ; V_12 < V_8 -> V_29 ; V_12 ++ )
F_11 ( V_8 -> V_4 , 1 ) ;
V_8 -> V_29 = 0 ;
F_12 ( & V_8 -> V_9 ) ;
}
static void F_13 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_30 ) ;
V_8 -> V_23 [ V_7 -> V_31 / V_11 -> V_19 ] &= ~ V_7 -> V_32 ;
}
static void F_14 ( struct V_7 * V_3 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_30 ) ;
V_8 -> V_23 [ V_7 -> V_31 / V_11 -> V_19 ] |= V_7 -> V_32 ;
}
static int F_15 ( struct V_7 * V_3 , unsigned int V_33 )
{
struct V_2 * V_8 = F_3 ( V_3 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
const struct V_1 * V_7 = F_1 ( V_8 , V_3 -> V_30 ) ;
if ( V_33 ) {
if ( V_8 -> V_25 )
V_8 -> V_25 [ V_7 -> V_31 / V_11 -> V_19 ]
&= ~ V_7 -> V_32 ;
V_8 -> V_29 ++ ;
} else {
if ( V_8 -> V_25 )
V_8 -> V_25 [ V_7 -> V_31 / V_11 -> V_19 ]
|= V_7 -> V_32 ;
V_8 -> V_29 -- ;
}
return 0 ;
}
static T_2 F_16 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
const struct V_34 * V_5 = V_3 -> V_5 ;
struct V_10 * V_11 = V_3 -> V_11 ;
int V_13 , V_12 ;
bool V_35 = false ;
T_1 V_14 ;
if ( V_5 -> V_15 ) {
V_13 = F_6 ( V_11 -> V_16 ) ;
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_16 , L_5 ,
V_13 ) ;
F_10 ( V_11 -> V_16 ) ;
return V_36 ;
}
}
if ( ! V_11 -> V_37 && V_11 -> V_19 == 1 &&
V_3 -> V_20 == 1 ) {
T_3 * V_38 = V_3 -> V_39 ;
T_4 * V_40 = V_3 -> V_39 ;
T_1 * V_41 = V_3 -> V_39 ;
F_17 ( ! V_3 -> V_39 ) ;
V_13 = F_18 ( V_11 , V_5 -> V_42 ,
V_3 -> V_39 ,
V_5 -> V_17 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_6 ,
V_13 ) ;
return V_36 ;
}
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_17 ; V_12 ++ ) {
switch ( V_11 -> V_43 . V_44 ) {
case 1 :
V_3 -> V_45 [ V_12 ] = V_38 [ V_12 ] ;
break;
case 2 :
V_3 -> V_45 [ V_12 ] = V_40 [ V_12 ] ;
break;
case 4 :
V_3 -> V_45 [ V_12 ] = V_41 [ V_12 ] ;
break;
default:
F_19 () ;
return V_36 ;
}
}
} else {
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_17 ; V_12 ++ ) {
V_13 = F_20 ( V_11 , V_5 -> V_42 +
( V_12 * V_11 -> V_19
* V_3 -> V_20 ) ,
& V_3 -> V_45 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 ,
L_6 ,
V_13 ) ;
if ( V_5 -> V_15 )
F_10 ( V_11 -> V_16 ) ;
return V_36 ;
}
}
}
for ( V_12 = 0 ; V_12 < V_3 -> V_5 -> V_17 ; V_12 ++ ) {
V_3 -> V_45 [ V_12 ] &= ~ V_3 -> V_23 [ V_12 ] ;
if ( V_3 -> V_45 [ V_12 ] && V_5 -> V_28 ) {
V_14 = V_5 -> V_28 +
( V_12 * V_11 -> V_19 * V_3 -> V_20 ) ;
V_13 = F_9 ( V_11 , V_14 , V_3 -> V_45 [ V_12 ] ) ;
if ( V_13 != 0 )
F_7 ( V_11 -> V_16 , L_4 ,
V_14 , V_13 ) ;
}
}
for ( V_12 = 0 ; V_12 < V_5 -> V_46 ; V_12 ++ ) {
if ( V_3 -> V_45 [ V_5 -> V_6 [ V_12 ] . V_31 /
V_11 -> V_19 ] & V_5 -> V_6 [ V_12 ] . V_32 ) {
F_21 ( F_22 ( V_3 -> V_47 , V_12 ) ) ;
V_35 = true ;
}
}
if ( V_5 -> V_15 )
F_10 ( V_11 -> V_16 ) ;
if ( V_35 )
return V_48 ;
else
return V_36 ;
}
static int F_23 ( struct V_49 * V_50 , unsigned int V_51 ,
T_5 V_52 )
{
struct V_2 * V_3 = V_50 -> V_53 ;
F_24 ( V_51 , V_3 ) ;
F_25 ( V_51 , & V_3 -> V_54 ) ;
F_26 ( V_51 , 1 ) ;
#ifdef F_27
F_28 ( V_51 , V_55 ) ;
#else
F_29 ( V_51 ) ;
#endif
return 0 ;
}
int F_30 ( struct V_10 * V_11 , int V_4 , int V_56 ,
int V_57 , const struct V_34 * V_5 ,
struct V_2 * * V_3 )
{
struct V_2 * V_8 ;
int V_12 ;
int V_13 = - V_58 ;
T_1 V_14 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_46 ; V_12 ++ ) {
if ( V_5 -> V_6 [ V_12 ] . V_31 % V_11 -> V_19 )
return - V_59 ;
if ( V_5 -> V_6 [ V_12 ] . V_31 / V_11 -> V_19 >=
V_5 -> V_17 )
return - V_59 ;
}
if ( V_57 ) {
V_57 = F_31 ( V_57 , 0 , V_5 -> V_46 , 0 ) ;
if ( V_57 < 0 ) {
F_32 ( V_11 -> V_16 , L_7 ,
V_57 ) ;
return V_57 ;
}
}
V_8 = F_33 ( sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_58 ;
* V_3 = V_8 ;
V_8 -> V_45 = F_33 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_60 ) ;
if ( ! V_8 -> V_45 )
goto V_61;
V_8 -> V_23 = F_33 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_60 ) ;
if ( ! V_8 -> V_23 )
goto V_61;
V_8 -> V_22 = F_33 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_60 ) ;
if ( ! V_8 -> V_22 )
goto V_61;
if ( V_5 -> V_24 ) {
V_8 -> V_25 = F_33 ( sizeof( unsigned int ) * V_5 -> V_17 ,
V_60 ) ;
if ( ! V_8 -> V_25 )
goto V_61;
}
V_8 -> V_54 = V_34 ;
V_8 -> V_54 . V_62 = V_5 -> V_62 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_57 = V_57 ;
if ( V_5 -> V_20 )
V_8 -> V_20 = V_5 -> V_20 ;
else
V_8 -> V_20 = 1 ;
if ( ! V_11 -> V_37 && V_11 -> V_19 == 1 &&
V_8 -> V_20 == 1 ) {
V_8 -> V_39 = F_34 ( V_11 -> V_43 . V_44 *
V_5 -> V_17 , V_60 ) ;
if ( ! V_8 -> V_39 )
goto V_61;
}
F_35 ( & V_8 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_46 ; V_12 ++ )
V_8 -> V_22 [ V_5 -> V_6 [ V_12 ] . V_31 / V_11 -> V_19 ]
|= V_5 -> V_6 [ V_12 ] . V_32 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_17 ; V_12 ++ ) {
V_8 -> V_23 [ V_12 ] = V_8 -> V_22 [ V_12 ] ;
V_14 = V_5 -> V_18 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_5 -> V_21 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , ~ V_8 -> V_23 [ V_12 ] ) ;
else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_23 [ V_12 ] , V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_8 ,
V_14 , V_13 ) ;
goto V_61;
}
if ( ! V_5 -> V_27 )
continue;
V_14 = V_5 -> V_42 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
V_13 = F_20 ( V_11 , V_14 , & V_8 -> V_45 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_6 ,
V_13 ) ;
goto V_61;
}
if ( V_8 -> V_45 [ V_12 ] && V_5 -> V_28 ) {
V_14 = V_5 -> V_28 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
V_13 = F_9 ( V_11 , V_14 ,
V_8 -> V_45 [ V_12 ] & V_8 -> V_23 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_4 ,
V_14 , V_13 ) ;
goto V_61;
}
}
}
if ( V_8 -> V_25 ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_17 ; V_12 ++ ) {
V_8 -> V_25 [ V_12 ] = V_8 -> V_22 [ V_12 ] ;
V_14 = V_5 -> V_24 +
( V_12 * V_11 -> V_19 * V_8 -> V_20 ) ;
if ( V_5 -> V_26 )
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] ,
0 ) ;
else
V_13 = F_8 ( V_11 , V_14 ,
V_8 -> V_22 [ V_12 ] ,
V_8 -> V_25 [ V_12 ] ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_8 ,
V_14 , V_13 ) ;
goto V_61;
}
}
}
if ( V_57 )
V_8 -> V_47 = F_36 ( V_11 -> V_16 -> V_63 ,
V_5 -> V_46 , V_57 , 0 ,
& V_64 , V_8 ) ;
else
V_8 -> V_47 = F_37 ( V_11 -> V_16 -> V_63 ,
V_5 -> V_46 ,
& V_64 , V_8 ) ;
if ( ! V_8 -> V_47 ) {
F_7 ( V_11 -> V_16 , L_9 ) ;
V_13 = - V_58 ;
goto V_61;
}
V_13 = F_38 ( V_4 , NULL , F_16 , V_56 ,
V_5 -> V_62 , V_8 ) ;
if ( V_13 != 0 ) {
F_7 ( V_11 -> V_16 , L_10 ,
V_4 , V_5 -> V_62 , V_13 ) ;
goto V_65;
}
return 0 ;
V_65:
V_61:
F_39 ( V_8 -> V_25 ) ;
F_39 ( V_8 -> V_22 ) ;
F_39 ( V_8 -> V_23 ) ;
F_39 ( V_8 -> V_45 ) ;
F_39 ( V_8 -> V_39 ) ;
F_39 ( V_8 ) ;
return V_13 ;
}
void F_40 ( int V_4 , struct V_2 * V_8 )
{
if ( ! V_8 )
return;
F_41 ( V_4 , V_8 ) ;
F_39 ( V_8 -> V_25 ) ;
F_39 ( V_8 -> V_22 ) ;
F_39 ( V_8 -> V_23 ) ;
F_39 ( V_8 -> V_39 ) ;
F_39 ( V_8 -> V_45 ) ;
F_39 ( V_8 ) ;
}
int F_42 ( struct V_2 * V_3 )
{
F_43 ( ! V_3 -> V_57 ) ;
return V_3 -> V_57 ;
}
int F_44 ( struct V_2 * V_3 , int V_4 )
{
if ( ! V_3 -> V_5 -> V_6 [ V_4 ] . V_32 )
return - V_59 ;
return F_45 ( V_3 -> V_47 , V_4 ) ;
}
struct V_49 * F_46 ( struct V_2 * V_3 )
{
if ( V_3 )
return V_3 -> V_47 ;
else
return NULL ;
}
