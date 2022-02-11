static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned char V_4 ,
unsigned long type ,
unsigned int V_5 )
{
struct V_1 * V_6 = F_2 ( V_3 , type , V_5 ) ;
if ( V_6 ) {
V_6 -> V_7 &= ~ V_8 ;
V_6 -> V_7 |= V_4 & V_8 ;
}
return V_6 ;
}
static int F_3 ( struct V_2 * V_3 , struct V_9 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_12 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_1
L_2 , V_10 , ( unsigned long long ) V_6 -> V_13 ,
( unsigned long long ) V_6 -> V_14 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = 0 ;
if ( ! V_4 -> V_16 ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_3 , V_10 ) ;
goto V_18;
}
V_6 -> V_13 = V_4 -> V_19 ;
V_6 -> V_14 = V_6 -> V_13 + V_4 -> V_16 - 1 ;
while ( ! F_5 ( V_3 , V_6 ) ) {
V_6 -> V_13 += V_4 -> V_20 ;
V_6 -> V_14 = V_6 -> V_13 + V_4 -> V_16 - 1 ;
if ( V_6 -> V_13 > V_4 -> V_21 || ! V_4 -> V_20 ) {
F_4 ( & V_3 -> V_3 , L_4
L_5 , V_10 ,
( unsigned long long ) V_4 -> V_19 ,
( unsigned long long ) V_4 -> V_21 ) ;
return - V_22 ;
}
}
V_18:
F_6 ( V_3 , V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_23 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_24 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_6
L_2 , V_10 , ( unsigned long long ) V_6 -> V_13 ,
( unsigned long long ) V_6 -> V_14 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = 0 ;
if ( ! ( V_4 -> V_7 & V_25 ) )
V_6 -> V_7 |= V_26 ;
if ( V_4 -> V_7 & V_27 )
V_6 -> V_7 |= V_28 ;
if ( V_4 -> V_7 & V_29 )
V_6 -> V_7 |= V_30 ;
if ( ! V_4 -> V_16 ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_7 , V_10 ) ;
goto V_18;
}
V_6 -> V_13 = V_4 -> V_19 ;
V_6 -> V_14 = V_6 -> V_13 + V_4 -> V_16 - 1 ;
while ( ! F_8 ( V_3 , V_6 ) ) {
V_6 -> V_13 += V_4 -> V_20 ;
V_6 -> V_14 = V_6 -> V_13 + V_4 -> V_16 - 1 ;
if ( V_6 -> V_13 > V_4 -> V_21 || ! V_4 -> V_20 ) {
F_4 ( & V_3 -> V_3 , L_8
L_5 , V_10 ,
( unsigned long long ) V_4 -> V_19 ,
( unsigned long long ) V_4 -> V_21 ) ;
return - V_22 ;
}
}
V_18:
F_9 ( V_3 , V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_31 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
int V_32 ;
static unsigned short V_33 [ 16 ] = {
5 , 10 , 11 , 12 , 9 , 14 , 15 , 7 , 3 , 4 , 13 , 0 , 1 , 6 , 8 , 2
} ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_34 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_9 ,
V_10 , ( int ) V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = - 1 ;
if ( F_11 ( V_4 -> V_35 . V_36 , V_37 ) ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_10 , V_10 ) ;
goto V_18;
}
V_6 -> V_13 = F_12 ( V_4 -> V_35 . V_36 , V_37 , 16 ) ;
if ( V_6 -> V_13 < V_37 ) {
V_6 -> V_14 = V_6 -> V_13 ;
goto V_18;
}
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
if ( F_13 ( V_33 [ V_32 ] , V_4 -> V_35 . V_36 ) ) {
V_6 -> V_13 = V_6 -> V_14 = V_33 [ V_32 ] ;
if ( F_14 ( V_3 , V_6 ) )
goto V_18;
}
}
if ( V_4 -> V_7 & V_38 ) {
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = - 1 ;
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_11 , V_10 ) ;
goto V_18;
}
F_4 ( & V_3 -> V_3 , L_12 , V_10 ) ;
return - V_22 ;
V_18:
F_15 ( V_3 , V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_39 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
int V_32 ;
static unsigned short V_33 [ 8 ] = {
1 , 3 , 5 , 6 , 7 , 0 , 2 , 4
} ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_40 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_13 ,
V_10 , ( int ) V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = - 1 ;
if ( ! V_4 -> V_35 ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_14 , V_10 ) ;
goto V_18;
}
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
if ( V_4 -> V_35 & ( 1 << V_33 [ V_32 ] ) ) {
V_6 -> V_13 = V_6 -> V_14 = V_33 [ V_32 ] ;
if ( F_17 ( V_3 , V_6 ) )
goto V_18;
}
}
F_4 ( & V_3 -> V_3 , L_15 , V_10 ) ;
return - V_22 ;
V_18:
F_18 ( V_3 , V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
void F_19 ( struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_41 * V_42 , * V_43 ;
F_22 (pnp_res, tmp, &dev->resources, list) {
if ( V_42 -> V_6 . V_7 & V_15 )
F_23 ( V_42 ) ;
}
}
static int F_24 ( struct V_2 * V_3 , int V_44 )
{
struct V_45 * V_46 ;
int V_47 = 0 , V_48 = 0 , V_49 = 0 ;
int T_1 V_50 = 0 ;
int V_51 = 0 ;
F_4 ( & V_3 -> V_3 , L_16 , V_44 ) ;
F_25 ( & V_52 ) ;
F_21 ( V_3 ) ;
F_26 (option, &dev->options, list) {
if ( F_27 ( V_46 ) &&
F_28 ( V_46 ) != V_44 )
continue;
switch ( V_46 -> type ) {
case V_12 :
V_51 = F_3 ( V_3 , & V_46 -> V_53 . V_54 , V_47 ++ ) ;
break;
case V_24 :
V_51 = F_7 ( V_3 , & V_46 -> V_53 . V_55 , V_48 ++ ) ;
break;
case V_34 :
V_51 = F_10 ( V_3 , & V_46 -> V_53 . V_56 , V_49 ++ ) ;
break;
#ifdef F_29
case V_40 :
V_51 = F_16 ( V_3 , & V_46 -> V_53 . V_57 , T_1 ++ ) ;
break;
#endif
default:
V_51 = - V_58 ;
break;
}
if ( V_51 < 0 )
break;
}
F_30 ( & V_52 ) ;
if ( V_51 < 0 ) {
F_4 ( & V_3 -> V_3 , L_17 , V_51 ) ;
F_21 ( V_3 ) ;
} else
F_31 ( V_3 , L_18 ) ;
return V_51 ;
}
int F_32 ( struct V_2 * V_3 )
{
int V_32 , V_51 ;
if ( ! F_33 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_19 ) ;
return - V_59 ;
}
V_51 = F_24 ( V_3 , 0 ) ;
if ( V_51 == 0 )
return 0 ;
for ( V_32 = 1 ; V_32 < V_3 -> V_60 ; V_32 ++ ) {
V_51 = F_24 ( V_3 , V_32 ) ;
if ( V_51 == 0 )
return 0 ;
}
F_34 ( & V_3 -> V_3 , L_20 ) ;
return V_51 ;
}
int F_35 ( struct V_2 * V_3 )
{
if ( ! F_36 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_21 ) ;
return - V_58 ;
}
F_31 ( V_3 , L_22 ) ;
if ( V_3 -> V_61 -> V_44 ( V_3 ) < 0 ) {
F_34 ( & V_3 -> V_3 , L_23 ) ;
return - V_62 ;
}
F_37 ( & V_3 -> V_3 , L_24 ) ;
return 0 ;
}
int F_38 ( struct V_2 * V_3 )
{
if ( ! F_39 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_25 ) ;
return - V_58 ;
}
if ( V_3 -> V_61 -> V_63 ( V_3 ) < 0 ) {
F_34 ( & V_3 -> V_3 , L_26 ) ;
return - V_62 ;
}
F_37 ( & V_3 -> V_3 , L_27 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 )
{
int error ;
if ( V_3 -> V_64 )
return 0 ;
if ( F_32 ( V_3 ) )
return - V_22 ;
error = F_35 ( V_3 ) ;
if ( error )
return error ;
V_3 -> V_64 = 1 ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 )
{
int error ;
if ( ! V_3 -> V_64 )
return 0 ;
error = F_38 ( V_3 ) ;
if ( error )
return error ;
V_3 -> V_64 = 0 ;
F_25 ( & V_52 ) ;
F_21 ( V_3 ) ;
F_30 ( & V_52 ) ;
return 0 ;
}
