void F_1 ( bool V_1 )
{
struct V_2 * V_3 = F_2 ( & V_2 ) ;
T_1 V_4 ;
if ( ! F_3 ( V_5 ) )
return;
if ( ! V_1 && F_4 ( V_6 , V_3 -> V_7 ) )
return;
V_3 -> V_7 = V_6 + V_8 ;
F_5 ( V_9 , V_4 ) ;
if ( V_3 -> V_10 == V_4 )
return;
F_6 ( V_9 , V_3 -> V_10 ) ;
if ( ! V_3 -> V_11 || V_1 ) {
F_7 ( V_12 L_1 ,
F_8 () , V_3 -> V_10 , V_4 ) ;
V_3 -> V_11 = true ;
}
}
static void F_9 ( struct V_2 * V_13 , T_1 V_14 ,
unsigned int V_15 , bool V_16 )
{
if ( ( V_16 && V_14 != 0 ) || ( ! V_16 && V_14 < 0 ) ||
( V_14 > 0x7FFFFFFF ) ) {
F_7 ( V_12 L_2 , V_15 ,
V_14 ) ;
F_6 ( V_9 , 0 ) ;
V_14 = 0 ;
}
V_13 -> V_10 = V_14 ;
}
bool T_2 F_10 ( bool V_16 )
{
struct V_2 * V_13 = F_2 ( & V_2 ) ;
T_1 V_14 ;
if ( ! F_3 ( V_5 ) )
return false ;
F_5 ( V_9 , V_14 ) ;
V_13 -> V_14 = V_14 ;
V_13 -> V_7 = V_6 + V_8 ;
F_9 ( V_13 , V_14 , F_8 () , V_16 ) ;
return false ;
}
bool F_10 ( bool V_16 )
{
struct V_2 * V_17 , * V_13 = F_2 ( & V_2 ) ;
unsigned int V_18 , V_15 = F_8 () ;
struct V_19 * V_20 ;
T_1 V_14 ;
if ( ! F_3 ( V_5 ) )
return false ;
F_5 ( V_9 , V_14 ) ;
V_13 -> V_14 = V_14 ;
V_13 -> V_7 = V_6 + V_8 ;
V_13 -> V_11 = false ;
V_20 = F_11 ( V_15 ) ;
V_18 = V_20 ? F_12 ( V_20 , V_15 ) : V_21 ;
if ( V_18 >= V_21 ) {
F_9 ( V_13 , V_14 , F_8 () ,
V_16 ) ;
return false ;
}
V_17 = F_13 ( & V_2 , V_18 ) ;
if ( V_14 != V_17 -> V_14 ) {
F_7 ( V_12 L_3 ,
V_18 , V_17 -> V_14 , V_15 , V_14 ) ;
}
if ( V_14 != V_17 -> V_10 ) {
F_7 ( L_4 ,
V_18 , V_17 -> V_10 , V_15 , V_14 ) ;
V_13 -> V_10 = V_17 -> V_10 ;
F_6 ( V_9 , V_17 -> V_10 ) ;
}
return true ;
}
static T_3 F_14 ( unsigned int V_22 )
{
T_3 V_23 , V_24 , V_25 , V_26 , V_27 = 0 ;
int V_28 , V_29 = 0 ;
V_23 = F_15 () ;
V_26 = V_23 + ( T_3 ) V_30 * V_22 ;
V_24 = V_23 ;
for ( V_28 = 0 ; ; V_28 ++ ) {
F_16 ( & V_31 ) ;
V_25 = V_32 ;
V_24 = F_15 () ;
V_32 = V_24 ;
F_17 ( & V_31 ) ;
if ( F_18 ( ! ( V_28 & 7 ) ) ) {
if ( V_24 > V_26 || V_28 > 10000000 )
break;
F_19 () ;
F_20 () ;
}
if ( F_18 ( V_25 > V_24 ) ) {
F_16 ( & V_31 ) ;
V_33 = F_21 ( V_33 , V_25 - V_24 ) ;
V_27 = V_33 ;
if ( V_29 != V_34 )
V_35 ++ ;
V_34 ++ ;
V_29 = V_34 ;
F_17 ( & V_31 ) ;
}
}
F_22 ( ! ( V_24 - V_23 ) ,
L_5 ,
V_24 - V_23 , V_26 - V_23 ) ;
return V_27 ;
}
static inline unsigned int F_23 ( int V_15 )
{
return ( F_24 ( F_11 ( V_15 ) ) > 1 ) ? 2 : 20 ;
}
void F_25 ( int V_15 )
{
int V_36 = 2 ;
if ( F_26 () )
return;
if ( ! F_3 ( V_5 ) )
F_27 ( & V_37 , 1 ) ;
else
F_27 ( & V_37 , 3 ) ;
V_38:
while ( F_28 ( & V_39 ) != V_36 - 1 ) {
if ( F_28 ( & V_40 ) > 0 ) {
F_27 ( & V_40 , 0 ) ;
return;
}
F_19 () ;
}
F_29 ( & V_39 ) ;
F_14 ( F_23 ( V_15 ) ) ;
while ( F_28 ( & V_41 ) != V_36 - 1 )
F_19 () ;
if ( ! V_34 ) {
F_27 ( & V_37 , 0 ) ;
F_30 ( L_6 ,
F_8 () , V_15 ) ;
} else if ( F_31 ( & V_37 ) || V_35 ) {
F_27 ( & V_37 , 0 ) ;
F_32 ( L_7 ,
F_8 () , V_15 ) ;
F_32 ( L_8
L_9 , V_33 ) ;
if ( V_35 )
F_32 ( L_10 ) ;
F_33 ( L_11 ) ;
}
F_27 ( & V_39 , 0 ) ;
V_35 = 0 ;
V_34 = 0 ;
V_33 = 0 ;
V_32 = 0 ;
F_29 ( & V_41 ) ;
if ( F_28 ( & V_37 ) > 0 )
goto V_38;
}
void F_34 ( void )
{
struct V_2 * V_13 = F_2 ( & V_2 ) ;
unsigned int V_15 = F_8 () ;
T_3 V_27 , V_42 ;
int V_36 = 2 ;
if ( F_26 () )
return;
if ( F_10 ( false ) || V_43 ) {
F_29 ( & V_40 ) ;
return;
}
V_38:
F_29 ( & V_39 ) ;
while ( F_28 ( & V_39 ) != V_36 )
F_19 () ;
V_27 = F_14 ( F_23 ( V_15 ) ) ;
V_42 = V_33 ;
F_29 ( & V_41 ) ;
while ( F_28 ( & V_41 ) != V_36 )
F_19 () ;
F_27 ( & V_41 , 0 ) ;
if ( ! F_28 ( & V_37 ) )
return;
if ( ! V_27 )
V_27 = - V_42 ;
V_13 -> V_10 += V_27 ;
if ( V_13 -> V_10 < 0 )
V_13 -> V_10 = 0 ;
if ( V_13 -> V_10 > 0x7FFFFFFF )
V_13 -> V_10 = 0x7FFFFFFF ;
F_7 ( L_12 ,
V_15 , V_27 , V_13 -> V_10 ) ;
F_6 ( V_9 , V_13 -> V_10 ) ;
goto V_38;
}
