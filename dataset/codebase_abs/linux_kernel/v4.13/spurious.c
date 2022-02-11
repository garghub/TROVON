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
static int F_10 ( struct V_1 * V_2 , bool V_8 )
{
T_1 V_9 = V_10 ;
struct V_11 * V_7 ;
F_8 ( & V_2 -> V_6 ) ;
if ( F_11 ( V_2 ) ||
F_12 ( V_2 ) ||
F_13 ( V_2 ) )
goto V_12;
if ( F_9 ( & V_2 -> V_4 ) && ! V_8 )
goto V_12;
V_7 = V_2 -> V_7 ;
if ( ! V_7 || ! ( V_7 -> V_13 & V_14 ) ||
( V_7 -> V_13 & V_15 ) )
goto V_12;
if ( F_6 ( & V_2 -> V_4 ) ) {
V_2 -> V_16 |= V_17 ;
goto V_12;
}
V_2 -> V_16 |= V_18 ;
do {
if ( F_14 ( V_2 ) == V_19 )
V_9 = V_19 ;
V_7 = V_2 -> V_7 ;
} while ( ( V_2 -> V_16 & V_17 ) && V_7 );
V_2 -> V_16 &= ~ V_18 ;
V_12:
F_5 ( & V_2 -> V_6 ) ;
return V_9 == V_19 ;
}
static int F_15 ( int V_5 )
{
struct V_1 * V_2 ;
int V_20 , V_21 = 0 ;
if ( F_16 ( & V_22 ) != 1 )
goto V_12;
V_3 = F_3 () ;
F_17 (i, desc) {
if ( ! V_20 )
continue;
if ( V_20 == V_5 )
continue;
if ( F_10 ( V_2 , false ) )
V_21 = 1 ;
}
V_12:
F_18 ( & V_22 ) ;
return V_21 ;
}
static void F_19 ( unsigned long V_23 )
{
struct V_1 * V_2 ;
int V_20 ;
if ( F_16 ( & V_22 ) != 1 )
goto V_12;
V_3 = F_3 () ;
F_17 (i, desc) {
unsigned int V_24 ;
if ( ! V_20 )
continue;
V_24 = V_2 -> V_16 ;
F_20 () ;
if ( ! ( V_24 & V_25 ) )
continue;
F_21 () ;
F_10 ( V_2 , true ) ;
F_22 () ;
}
V_12:
F_18 ( & V_22 ) ;
F_23 ( & V_26 ,
V_27 + V_28 ) ;
}
static inline int F_24 ( T_1 V_29 )
{
unsigned int V_30 = V_29 ;
if ( F_25 ( V_30 <= ( V_19 | V_31 ) ) )
return 0 ;
return 1 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_29 )
{
unsigned int V_5 = F_27 ( V_2 ) ;
struct V_11 * V_7 ;
unsigned long V_13 ;
if ( F_24 ( V_29 ) ) {
F_28 ( V_32 L_2 ,
V_5 , V_29 ) ;
} else {
F_28 ( V_32 L_3
L_4 , V_5 ) ;
}
F_29 () ;
F_28 ( V_32 L_5 ) ;
F_30 ( & V_2 -> V_6 , V_13 ) ;
F_31 (desc, action) {
F_28 ( V_32 L_6 , V_7 -> V_33 , V_7 -> V_33 ) ;
if ( V_7 -> V_34 )
F_28 ( V_35 L_7 ,
V_7 -> V_34 , V_7 -> V_34 ) ;
F_28 ( V_35 L_8 ) ;
}
F_32 ( & V_2 -> V_6 , V_13 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_1 V_29 )
{
static int V_36 = 100 ;
if ( V_36 > 0 ) {
V_36 -- ;
F_26 ( V_2 , V_29 ) ;
}
}
static inline int
F_34 ( unsigned int V_5 , struct V_1 * V_2 ,
T_1 V_29 )
{
struct V_11 * V_7 ;
if ( ! V_37 )
return 0 ;
if ( V_29 == V_10 )
return 1 ;
if ( V_37 < 2 )
return 0 ;
if ( ! V_5 )
return 1 ;
V_7 = V_2 -> V_7 ;
F_20 () ;
return V_7 && ( V_7 -> V_13 & V_38 ) ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_29 )
{
unsigned int V_5 ;
if ( V_2 -> V_16 & V_18 ||
F_13 ( V_2 ) )
return;
if ( F_24 ( V_29 ) ) {
F_33 ( V_2 , V_29 ) ;
return;
}
if ( V_29 & V_31 ) {
if ( V_29 == V_31 ) {
int V_39 ;
if ( ! ( V_2 -> V_40 & V_41 ) ) {
V_2 -> V_40 |= V_41 ;
return;
}
V_39 = F_36 ( & V_2 -> V_42 ) ;
V_39 |= V_41 ;
if ( V_39 != V_2 -> V_40 ) {
V_29 = V_19 ;
V_2 -> V_40 = V_39 ;
} else {
V_29 = V_10 ;
}
} else {
V_2 -> V_40 &= ~ V_41 ;
}
}
if ( F_37 ( V_29 == V_10 ) ) {
if ( F_38 ( V_27 , V_2 -> V_43 + V_44 / 10 ) )
V_2 -> V_45 = 1 ;
else
V_2 -> V_45 ++ ;
V_2 -> V_43 = V_27 ;
}
V_5 = F_27 ( V_2 ) ;
if ( F_37 ( F_34 ( V_5 , V_2 , V_29 ) ) ) {
int V_21 = F_15 ( V_5 ) ;
if ( V_29 == V_10 )
V_2 -> V_45 -= V_21 ;
}
V_2 -> V_46 ++ ;
if ( F_25 ( V_2 -> V_46 < 100000 ) )
return;
V_2 -> V_46 = 0 ;
if ( F_37 ( V_2 -> V_45 > 99900 ) ) {
F_26 ( V_2 , V_29 ) ;
F_28 ( V_47 L_9 , V_5 ) ;
V_2 -> V_16 |= V_25 ;
V_2 -> V_48 ++ ;
F_39 ( V_2 ) ;
F_23 ( & V_26 ,
V_27 + V_28 ) ;
}
V_2 -> V_45 = 0 ;
}
int F_40 ( char * V_49 )
{
V_50 = 1 ;
F_28 ( V_51 L_10 ) ;
return 1 ;
}
static int T_2 F_41 ( char * V_49 )
{
V_37 = 1 ;
F_28 ( V_52 L_11 ) ;
F_28 ( V_52 L_12 ) ;
return 1 ;
}
static int T_2 F_42 ( char * V_49 )
{
V_37 = 2 ;
F_28 ( V_52 L_13
L_14 ) ;
F_28 ( V_52 L_15
L_16 ) ;
return 1 ;
}
