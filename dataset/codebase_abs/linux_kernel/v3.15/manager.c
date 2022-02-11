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
if ( V_4 -> V_7 & V_31 )
V_6 -> V_7 |= V_32 ;
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
static int F_10 ( struct V_2 * V_3 , struct V_33 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
int V_34 ;
static unsigned short V_35 [ 16 ] = {
5 , 10 , 11 , 12 , 9 , 14 , 15 , 7 , 3 , 4 , 13 , 0 , 1 , 6 , 8 , 2
} ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_36 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_9 ,
V_10 , ( int ) V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = - 1 ;
if ( F_11 ( V_4 -> V_37 . V_38 , V_39 ) ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_10 , V_10 ) ;
goto V_18;
}
V_6 -> V_13 = F_12 ( V_4 -> V_37 . V_38 , V_39 , 16 ) ;
if ( V_6 -> V_13 < V_39 ) {
V_6 -> V_14 = V_6 -> V_13 ;
goto V_18;
}
for ( V_34 = 0 ; V_34 < 16 ; V_34 ++ ) {
if ( F_13 ( V_35 [ V_34 ] , V_4 -> V_37 . V_38 ) ) {
V_6 -> V_13 = V_6 -> V_14 = V_35 [ V_34 ] ;
if ( F_14 ( V_3 , V_6 ) )
goto V_18;
}
}
if ( V_4 -> V_7 & V_40 ) {
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
static int F_16 ( struct V_2 * V_3 , struct V_41 * V_4 , int V_10 )
{
struct V_1 * V_6 , V_11 ;
int V_34 ;
static unsigned short V_35 [ 8 ] = {
1 , 3 , 5 , 6 , 7 , 0 , 2 , 4
} ;
V_6 = F_1 ( V_3 , V_4 -> V_7 , V_42 , V_10 ) ;
if ( V_6 ) {
F_4 ( & V_3 -> V_3 , L_13 ,
V_10 , ( int ) V_6 -> V_13 , V_6 -> V_7 ) ;
return 0 ;
}
V_6 = & V_11 ;
V_6 -> V_7 = V_4 -> V_7 | V_15 ;
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = - 1 ;
if ( ! V_4 -> V_37 ) {
V_6 -> V_7 |= V_17 ;
F_4 ( & V_3 -> V_3 , L_14 , V_10 ) ;
goto V_18;
}
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
if ( V_4 -> V_37 & ( 1 << V_35 [ V_34 ] ) ) {
V_6 -> V_13 = V_6 -> V_14 = V_35 [ V_34 ] ;
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
struct V_43 * V_44 , * V_45 ;
F_22 (pnp_res, tmp, &dev->resources, list) {
if ( V_44 -> V_6 . V_7 & V_15 )
F_23 ( V_44 ) ;
}
}
static int F_24 ( struct V_2 * V_3 , int V_46 )
{
struct V_47 * V_48 ;
int V_49 = 0 , V_50 = 0 , V_51 = 0 ;
int T_1 V_52 = 0 ;
int V_53 = 0 ;
F_4 ( & V_3 -> V_3 , L_16 , V_46 ) ;
F_25 ( & V_54 ) ;
F_21 ( V_3 ) ;
F_26 (option, &dev->options, list) {
if ( F_27 ( V_48 ) &&
F_28 ( V_48 ) != V_46 )
continue;
switch ( V_48 -> type ) {
case V_12 :
V_53 = F_3 ( V_3 , & V_48 -> V_55 . V_56 , V_49 ++ ) ;
break;
case V_24 :
V_53 = F_7 ( V_3 , & V_48 -> V_55 . V_57 , V_50 ++ ) ;
break;
case V_36 :
V_53 = F_10 ( V_3 , & V_48 -> V_55 . V_58 , V_51 ++ ) ;
break;
#ifdef F_29
case V_42 :
V_53 = F_16 ( V_3 , & V_48 -> V_55 . V_59 , T_1 ++ ) ;
break;
#endif
default:
V_53 = - V_60 ;
break;
}
if ( V_53 < 0 )
break;
}
F_30 ( & V_54 ) ;
if ( V_53 < 0 ) {
F_4 ( & V_3 -> V_3 , L_17 , V_53 ) ;
F_21 ( V_3 ) ;
} else
F_31 ( V_3 , L_18 ) ;
return V_53 ;
}
int F_32 ( struct V_2 * V_3 )
{
int V_34 , V_53 ;
if ( ! F_33 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_19 ) ;
return - V_61 ;
}
V_53 = F_24 ( V_3 , 0 ) ;
if ( V_53 == 0 )
return 0 ;
for ( V_34 = 1 ; V_34 < V_3 -> V_62 ; V_34 ++ ) {
V_53 = F_24 ( V_3 , V_34 ) ;
if ( V_53 == 0 )
return 0 ;
}
F_34 ( & V_3 -> V_3 , L_20 ) ;
return V_53 ;
}
int F_35 ( struct V_2 * V_3 )
{
if ( ! F_36 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_21 ) ;
return - V_60 ;
}
F_31 ( V_3 , L_22 ) ;
if ( V_3 -> V_63 -> V_46 ( V_3 ) < 0 ) {
F_34 ( & V_3 -> V_3 , L_23 ) ;
return - V_64 ;
}
F_37 ( & V_3 -> V_3 , L_24 ) ;
return 0 ;
}
int F_38 ( struct V_2 * V_3 )
{
if ( ! F_39 ( V_3 ) ) {
F_4 ( & V_3 -> V_3 , L_25 ) ;
return - V_60 ;
}
if ( V_3 -> V_63 -> V_65 ( V_3 ) < 0 ) {
F_34 ( & V_3 -> V_3 , L_26 ) ;
return - V_64 ;
}
F_37 ( & V_3 -> V_3 , L_27 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 )
{
int error ;
if ( V_3 -> V_66 )
return 0 ;
if ( F_32 ( V_3 ) )
return - V_22 ;
error = F_35 ( V_3 ) ;
if ( error )
return error ;
V_3 -> V_66 = 1 ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 )
{
int error ;
if ( ! V_3 -> V_66 )
return 0 ;
error = F_38 ( V_3 ) ;
if ( error )
return error ;
V_3 -> V_66 = 0 ;
F_25 ( & V_54 ) ;
F_21 ( V_3 ) ;
F_30 ( & V_54 ) ;
return 0 ;
}
