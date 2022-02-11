static inline T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
return V_1 & ( 1 << V_2 ) ;
}
static inline void F_2 ( T_1 * V_1 , T_2 V_2 )
{
* V_1 |= ( 1 << V_2 ) ;
}
static inline void F_3 ( T_1 * V_1 , T_2 V_2 )
{
* V_1 &= ~ ( 1 << V_2 ) ;
}
static T_3 F_4 ( T_2 V_2 )
{
T_3 type ;
if ( V_2 == V_3 )
type = V_4 ;
else if ( V_2 <= V_5 )
type = V_6 ;
else if ( V_2 == V_7 )
type = V_8 ;
else if ( V_2 <= V_9 )
type = V_10 ;
else if ( V_2 == V_11 )
type = V_12 ;
else
type = - 1 ;
return type ;
}
void F_5 ( void )
{
int V_13 ;
F_6 ( V_14 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
F_7 ( V_16 [ V_13 ] ) ;
F_8 ( V_17 ) ;
F_9 ( V_17 ) ;
F_8 ( V_18 . V_19 ) ;
F_9 ( V_18 . V_19 ) ;
F_8 ( V_18 . V_20 ) ;
F_9 ( V_18 . V_20 ) ;
F_8 ( V_18 . V_21 ) ;
F_9 ( V_18 . V_21 ) ;
}
void F_10 ( void )
{
static struct V_22 V_23 ;
int V_13 , V_2 ;
V_23 . V_24 . V_25 = & V_26 ;
for ( V_13 = 0 , V_2 = 5 ; V_13 < V_15 ; V_13 ++ , V_2 ++ )
V_16 [ V_13 ] = F_11 ( V_2 ) ;
V_17 = F_12 ( & V_23 . V_24 , L_1 ) ;
if ( F_13 ( V_17 ) )
F_14 ( V_27 , L_2 , V_17 ) ;
else
F_15 ( V_17 ) ;
V_18 . V_19 = F_12 ( & V_23 . V_24 , L_3 ) ;
V_18 . V_20 = F_12 ( & V_23 . V_24 , L_4 ) ;
V_18 . V_21 = F_12 ( & V_23 . V_24 , L_5 ) ;
if ( F_13 ( V_18 . V_19 ) || F_13 ( V_18 . V_20 ) || F_13 ( V_18 . V_21 ) ) {
F_14 ( V_27 , L_6 ,
V_18 . V_19 , V_18 . V_20 , V_18 . V_21 ) ;
} else {
F_15 ( V_18 . V_19 ) ;
F_15 ( V_18 . V_20 ) ;
F_15 ( V_18 . V_21 ) ;
}
}
void F_16 ( short int V_28 , unsigned int V_29 )
{
struct V_30 * V_31 = V_16 [ V_28 - 1 ] ;
unsigned long V_32 ;
if ( ! V_31 )
return;
F_17 ( V_31 , V_33 ) ;
F_18 ( V_31 , 0 , V_29 ) ;
F_19 ( 80 ) ;
V_32 = F_20 ( 5 ) ;
while ( ! ( F_21 ( V_31 ) & V_33 ) ) {
if ( F_22 ( V_32 ) ) {
F_23 ( L_7 , V_34 ) ;
break;
}
}
}
int F_24 ( enum V_35 V_28 )
{
int V_36 = 0 ;
if ( F_1 ( V_14 , V_28 ) ) {
F_14 ( V_27 , L_8 , V_28 ) ;
goto V_37;
}
switch ( F_4 ( V_28 ) ) {
case V_4 :
F_25 ( V_17 ) ;
break;
case V_6 :
V_36 = F_26 ( V_16 [ V_28 - 1 ] ) ;
break;
#ifdef F_27
case V_10 :
F_28 ( F_29 ( V_28 ) ) ;
F_30 ( F_29 ( V_28 ) , V_38 ) ;
break;
#endif
case V_8 :
F_14 ( V_27 , L_9 ) ;
break;
case V_12 :
F_25 ( V_18 . V_19 ) ;
F_25 ( V_18 . V_20 ) ;
F_25 ( V_18 . V_21 ) ;
F_31 ( true ) ;
break;
default:
F_14 ( V_27 , L_10 ) ;
V_36 = - V_39 ;
}
if ( ! V_36 )
F_2 ( & V_14 , V_28 ) ;
V_37:
return V_36 ;
}
T_1 F_32 ( T_1 V_40 )
{
T_1 V_28 ;
T_1 V_36 = - V_39 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
if ( F_1 ( V_40 , V_28 ) )
V_36 = F_24 ( V_28 ) ;
}
return V_36 ;
}
int F_33 ( enum V_35 V_28 )
{
int V_36 = 0 ;
if ( ! F_1 ( V_14 , V_28 ) ) {
F_14 ( V_27 , L_11 , V_28 ) ;
goto V_37;
}
switch ( F_4 ( V_28 ) ) {
case V_4 :
F_34 ( V_17 ) ;
break;
case V_6 :
V_36 = F_35 ( V_16 [ V_28 - 1 ] ) ;
break;
#ifdef F_27
case V_10 :
F_30 ( F_29 ( V_28 ) , V_42 ) ;
F_36 ( F_29 ( V_28 ) ) ;
break;
#endif
case V_8 :
F_14 ( V_27 , L_12 ) ;
break;
case V_12 :
F_31 ( false ) ;
F_31 ( false ) ;
F_34 ( V_18 . V_19 ) ;
F_34 ( V_18 . V_20 ) ;
F_34 ( V_18 . V_21 ) ;
break;
default:
F_14 ( V_27 , L_13 ) ;
V_36 = - V_39 ;
}
if ( ! V_36 )
F_3 ( & V_14 , V_28 ) ;
V_37:
return V_36 ;
}
T_1 F_6 ( T_1 V_40 )
{
T_1 V_28 ;
T_1 V_36 = - V_39 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
if ( F_1 ( V_40 , V_28 ) )
V_36 = F_33 ( V_28 ) ;
}
return V_36 ;
}
T_1 F_37 ( void )
{
T_1 V_43 ;
V_43 = F_38 ( V_17 ) ;
V_43 /= 1000 ;
F_39 ( V_27 , L_14 , V_34 , V_43 ) ;
return V_43 ;
}
void F_31 ( bool V_44 )
{
void T_4 * V_45 ;
unsigned int V_46 ;
V_45 = F_40 ( V_47 + V_48 , V_49 ) ;
if ( ! V_45 ) {
F_23 ( L_15 , V_34 ) ;
return;
}
if ( V_44 ) {
V_46 = V_50 | V_51 | V_52 ;
} else {
V_46 = V_50 ;
}
F_41 ( V_46 , V_45 + V_53 ) ;
F_42 ( V_45 ) ;
}
