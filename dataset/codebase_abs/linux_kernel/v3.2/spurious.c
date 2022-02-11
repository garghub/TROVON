bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 == F_3 () ,
L_1 ,
F_3 () , V_2 -> V_4 . V_5 ) )
return false ;
#ifdef F_4
do {
F_5 ( & V_2 -> V_6 ) ;
while ( F_6 ( & V_2 -> V_4 ) )
F_7 () ;
F_8 ( & V_2 -> V_6 ) ;
} while ( F_6 ( & V_2 -> V_4 ) );
return ! F_9 ( & V_2 -> V_4 ) && V_2 -> V_7 ;
#else
return false ;
#endif
}
static int F_10 ( int V_5 , struct V_1 * V_2 , bool V_8 )
{
T_1 V_9 = V_10 ;
struct V_11 * V_7 ;
F_8 ( & V_2 -> V_6 ) ;
if ( F_11 ( V_2 ) || F_12 ( V_2 ) )
goto V_12;
if ( F_9 ( & V_2 -> V_4 ) && ! V_8 )
goto V_12;
V_7 = V_2 -> V_7 ;
if ( ! V_7 || ! ( V_7 -> V_13 & V_14 ) ||
( V_7 -> V_13 & V_15 ) ||
( V_7 -> V_16 ( V_5 , V_7 -> V_17 ) == V_18 ) ||
! V_7 -> V_19 )
goto V_12;
if ( F_6 ( & V_2 -> V_4 ) ) {
V_2 -> V_20 |= V_21 ;
goto V_12;
}
V_2 -> V_20 |= V_22 ;
do {
if ( F_13 ( V_2 ) == V_18 )
V_9 = V_18 ;
V_7 = V_2 -> V_7 ;
} while ( ( V_2 -> V_20 & V_21 ) && V_7 );
V_2 -> V_20 &= ~ V_22 ;
V_12:
F_5 ( & V_2 -> V_6 ) ;
return V_9 == V_18 ;
}
static int F_14 ( int V_5 )
{
struct V_1 * V_2 ;
int V_23 , V_24 = 0 ;
if ( F_15 ( & V_25 ) != 1 )
goto V_12;
V_3 = F_3 () ;
F_16 (i, desc) {
if ( ! V_23 )
continue;
if ( V_23 == V_5 )
continue;
if ( F_10 ( V_23 , V_2 , false ) )
V_24 = 1 ;
}
V_12:
F_17 ( & V_25 ) ;
return V_24 ;
}
static void F_18 ( unsigned long V_26 )
{
struct V_1 * V_2 ;
int V_23 ;
if ( F_15 ( & V_25 ) != 1 )
goto V_12;
V_3 = F_3 () ;
F_16 (i, desc) {
unsigned int V_27 ;
if ( ! V_23 )
continue;
V_27 = V_2 -> V_20 ;
F_19 () ;
if ( ! ( V_27 & V_28 ) )
continue;
F_20 () ;
F_10 ( V_23 , V_2 , true ) ;
F_21 () ;
}
V_12:
F_17 ( & V_25 ) ;
F_22 ( & V_29 ,
V_30 + V_31 ) ;
}
static inline int F_23 ( T_1 V_32 )
{
if ( F_24 ( V_32 <= ( V_18 | V_33 ) ) )
return 0 ;
return 1 ;
}
static void
F_25 ( unsigned int V_5 , struct V_1 * V_2 ,
T_1 V_32 )
{
struct V_11 * V_7 ;
unsigned long V_13 ;
if ( F_23 ( V_32 ) ) {
F_26 ( V_34 L_2 ,
V_5 , V_32 ) ;
} else {
F_26 ( V_34 L_3
L_4 , V_5 ) ;
}
F_27 () ;
F_26 ( V_34 L_5 ) ;
F_28 ( & V_2 -> V_6 , V_13 ) ;
V_7 = V_2 -> V_7 ;
while ( V_7 ) {
F_26 ( V_34 L_6 , V_7 -> V_16 , V_7 -> V_16 ) ;
if ( V_7 -> V_35 )
F_26 ( V_36 L_7 ,
V_7 -> V_35 , V_7 -> V_35 ) ;
F_26 ( V_36 L_8 ) ;
V_7 = V_7 -> V_19 ;
}
F_29 ( & V_2 -> V_6 , V_13 ) ;
}
static void
F_30 ( unsigned int V_5 , struct V_1 * V_2 , T_1 V_32 )
{
static int V_37 = 100 ;
if ( V_37 > 0 ) {
V_37 -- ;
F_25 ( V_5 , V_2 , V_32 ) ;
}
}
static inline int
F_31 ( unsigned int V_5 , struct V_1 * V_2 ,
T_1 V_32 )
{
struct V_11 * V_7 ;
if ( ! V_38 )
return 0 ;
if ( V_32 == V_10 )
return 1 ;
if ( V_38 < 2 )
return 0 ;
if ( ! V_5 )
return 1 ;
V_7 = V_2 -> V_7 ;
F_19 () ;
return V_7 && ( V_7 -> V_13 & V_39 ) ;
}
void F_32 ( unsigned int V_5 , struct V_1 * V_2 ,
T_1 V_32 )
{
if ( V_2 -> V_20 & V_22 )
return;
if ( V_32 == V_33 )
return;
if ( F_23 ( V_32 ) ) {
F_30 ( V_5 , V_2 , V_32 ) ;
return;
}
if ( F_33 ( V_32 == V_10 ) ) {
if ( F_34 ( V_30 , V_2 -> V_40 + V_41 / 10 ) )
V_2 -> V_42 = 1 ;
else
V_2 -> V_42 ++ ;
V_2 -> V_40 = V_30 ;
}
if ( F_33 ( F_31 ( V_5 , V_2 , V_32 ) ) ) {
int V_24 = F_14 ( V_5 ) ;
if ( V_32 == V_10 )
V_2 -> V_42 -= V_24 ;
}
V_2 -> V_43 ++ ;
if ( F_24 ( V_2 -> V_43 < 100000 ) )
return;
V_2 -> V_43 = 0 ;
if ( F_33 ( V_2 -> V_42 > 99900 ) ) {
F_25 ( V_5 , V_2 , V_32 ) ;
F_26 ( V_44 L_9 , V_5 ) ;
V_2 -> V_20 |= V_28 ;
V_2 -> V_45 ++ ;
F_35 ( V_2 ) ;
F_22 ( & V_29 ,
V_30 + V_31 ) ;
}
V_2 -> V_42 = 0 ;
}
int F_36 ( char * V_46 )
{
V_47 = 1 ;
F_26 ( V_48 L_10 ) ;
return 1 ;
}
static int T_2 F_37 ( char * V_46 )
{
V_38 = 1 ;
F_26 ( V_49 L_11 ) ;
F_26 ( V_49 L_12 ) ;
return 1 ;
}
static int T_2 F_38 ( char * V_46 )
{
V_38 = 2 ;
F_26 ( V_49 L_13
L_14 ) ;
F_26 ( V_49 L_15
L_16 ) ;
return 1 ;
}
