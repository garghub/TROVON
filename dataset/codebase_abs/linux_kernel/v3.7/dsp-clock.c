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
F_8 ( V_18 . V_19 ) ;
F_8 ( V_18 . V_20 ) ;
F_8 ( V_18 . V_21 ) ;
}
void F_9 ( void )
{
static struct V_22 V_23 ;
int V_13 , V_2 ;
V_23 . V_24 . V_25 = & V_26 ;
for ( V_13 = 0 , V_2 = 5 ; V_13 < V_15 ; V_13 ++ , V_2 ++ )
V_16 [ V_13 ] = F_10 ( V_2 ) ;
V_17 = F_11 ( & V_23 . V_24 , L_1 ) ;
if ( F_12 ( V_17 ) )
F_13 ( V_27 , L_2 , V_17 ) ;
V_18 . V_19 = F_11 ( & V_23 . V_24 , L_3 ) ;
V_18 . V_20 = F_11 ( & V_23 . V_24 , L_4 ) ;
V_18 . V_21 = F_11 ( & V_23 . V_24 , L_5 ) ;
if ( F_12 ( V_18 . V_19 ) || F_12 ( V_18 . V_20 ) || F_12 ( V_18 . V_21 ) )
F_13 ( V_27 , L_6 ,
V_18 . V_19 , V_18 . V_20 , V_18 . V_21 ) ;
}
void F_14 ( short int V_28 , unsigned int V_29 )
{
struct V_30 * V_31 = V_16 [ V_28 - 1 ] ;
unsigned long V_32 ;
if ( ! V_31 )
return;
F_15 ( V_31 , V_33 ) ;
F_16 ( V_31 , 0 , V_29 ) ;
F_17 ( 80 ) ;
V_32 = F_18 ( 5 ) ;
while ( ! ( F_19 ( V_31 ) & V_33 ) ) {
if ( F_20 ( V_32 ) ) {
F_21 ( L_7 , V_34 ) ;
break;
}
}
}
int F_22 ( enum V_35 V_28 )
{
int V_36 = 0 ;
if ( F_1 ( V_14 , V_28 ) ) {
F_13 ( V_27 , L_8 , V_28 ) ;
goto V_37;
}
switch ( F_4 ( V_28 ) ) {
case V_4 :
F_23 ( V_17 ) ;
break;
case V_6 :
V_36 = F_24 ( V_16 [ V_28 - 1 ] ) ;
break;
#ifdef F_25
case V_10 :
F_26 ( F_27 ( V_28 ) ) ;
F_28 ( F_27 ( V_28 ) , V_38 ) ;
break;
#endif
case V_8 :
F_13 ( V_27 , L_9 ) ;
break;
case V_12 :
F_23 ( V_18 . V_19 ) ;
F_23 ( V_18 . V_20 ) ;
F_23 ( V_18 . V_21 ) ;
F_29 ( true ) ;
break;
default:
F_13 ( V_27 , L_10 ) ;
V_36 = - V_39 ;
}
if ( ! V_36 )
F_2 ( & V_14 , V_28 ) ;
V_37:
return V_36 ;
}
T_1 F_30 ( T_1 V_40 )
{
T_1 V_28 ;
T_1 V_36 = - V_39 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
if ( F_1 ( V_40 , V_28 ) )
V_36 = F_22 ( V_28 ) ;
}
return V_36 ;
}
int F_31 ( enum V_35 V_28 )
{
int V_36 = 0 ;
if ( ! F_1 ( V_14 , V_28 ) ) {
F_13 ( V_27 , L_11 , V_28 ) ;
goto V_37;
}
switch ( F_4 ( V_28 ) ) {
case V_4 :
F_32 ( V_17 ) ;
break;
case V_6 :
V_36 = F_33 ( V_16 [ V_28 - 1 ] ) ;
break;
#ifdef F_25
case V_10 :
F_28 ( F_27 ( V_28 ) , V_42 ) ;
F_34 ( F_27 ( V_28 ) ) ;
break;
#endif
case V_8 :
F_13 ( V_27 , L_12 ) ;
break;
case V_12 :
F_29 ( false ) ;
F_29 ( false ) ;
F_32 ( V_18 . V_19 ) ;
F_32 ( V_18 . V_20 ) ;
F_32 ( V_18 . V_21 ) ;
break;
default:
F_13 ( V_27 , L_13 ) ;
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
V_36 = F_31 ( V_28 ) ;
}
return V_36 ;
}
T_1 F_35 ( void )
{
T_1 V_43 ;
V_43 = F_36 ( V_17 ) ;
V_43 /= 1000 ;
F_37 ( V_27 , L_14 , V_34 , V_43 ) ;
return V_43 ;
}
void F_29 ( bool V_44 )
{
void T_4 * V_45 ;
unsigned int V_46 ;
V_45 = F_38 ( V_47 + V_48 , V_49 ) ;
if ( ! V_45 ) {
F_21 ( L_15 , V_34 ) ;
return;
}
if ( V_44 ) {
V_46 = V_50 | V_51 | V_52 ;
} else {
V_46 = V_50 ;
}
F_39 ( V_46 , V_45 + V_53 ) ;
F_40 ( V_45 ) ;
}
