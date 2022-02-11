static inline void F_1 ( void )
{
switch ( F_2 () ) {
case V_1 :
F_3 ( 4 ) ;
break;
default:
break;
}
}
static inline void F_4 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 & V_5 )
F_1 () ;
}
void F_5 ( void )
{
unsigned long V_6 ;
unsigned long V_7 ;
int V_8 , V_9 ;
F_6 ( V_6 ) ;
V_7 = F_7 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
V_8 = F_10 () ;
if ( V_10 ) {
if ( V_11 . V_12 ) {
F_11 ( 0 ) ;
F_12 () ;
F_13 () ;
}
V_9 = V_11 . V_12 +
V_11 . V_13 ;
for ( V_8 = V_11 . V_12 ;
V_8 < V_9 ;
V_8 ++ ) {
F_11 ( V_8 ) ;
F_12 () ;
F_13 () ;
}
} else {
while ( V_8 < V_11 . V_14 ) {
F_14 ( F_15 ( V_8 ) ) ;
F_11 ( V_8 ) ;
F_12 () ;
F_16 () ;
V_8 ++ ;
}
}
F_17 () ;
F_14 ( V_7 ) ;
F_1 () ;
F_18 ( V_6 ) ;
}
void F_19 ( struct V_15 * V_16 )
{
int V_17 ;
F_20 () ;
V_17 = F_21 () ;
if ( F_22 ( V_17 , V_16 ) != 0 ) {
F_23 ( V_16 , V_17 ) ;
}
F_24 () ;
}
void F_25 ( struct V_2 * V_3 , unsigned long V_18 ,
unsigned long V_19 )
{
struct V_15 * V_16 = V_3 -> V_20 ;
int V_17 = F_21 () ;
if ( F_22 ( V_17 , V_16 ) != 0 ) {
unsigned long V_21 , V_6 ;
F_6 ( V_6 ) ;
V_18 = F_26 ( V_18 , V_22 << 1 ) ;
V_19 = F_27 ( V_19 , V_22 << 1 ) ;
V_21 = ( V_19 - V_18 ) >> ( V_23 + 1 ) ;
if ( V_21 <= ( V_11 . V_13 ?
V_11 . V_14 / 8 :
V_11 . V_14 / 2 ) ) {
int V_24 = F_7 () ;
int V_25 = F_28 ( V_17 , V_16 ) ;
while ( V_18 < V_19 ) {
int V_26 ;
F_14 ( V_18 | V_25 ) ;
V_18 += ( V_22 << 1 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_26 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_26 < 0 )
continue;
F_14 ( F_15 ( V_26 ) ) ;
F_12 () ;
F_16 () ;
}
F_17 () ;
F_14 ( V_24 ) ;
} else {
F_23 ( V_16 , V_17 ) ;
}
F_1 () ;
F_18 ( V_6 ) ;
}
}
void F_32 ( unsigned long V_18 , unsigned long V_19 )
{
unsigned long V_21 , V_6 ;
F_6 ( V_6 ) ;
V_21 = ( V_19 - V_18 + ( V_22 - 1 ) ) >> V_23 ;
V_21 = ( V_21 + 1 ) >> 1 ;
if ( V_21 <= ( V_11 . V_13 ?
V_11 . V_14 / 8 :
V_11 . V_14 / 2 ) ) {
int V_27 = F_7 () ;
V_18 &= ( V_28 << 1 ) ;
V_19 += ( ( V_22 << 1 ) - 1 ) ;
V_19 &= ( V_28 << 1 ) ;
while ( V_18 < V_19 ) {
int V_26 ;
F_14 ( V_18 ) ;
V_18 += ( V_22 << 1 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_26 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_26 < 0 )
continue;
F_14 ( F_15 ( V_26 ) ) ;
F_12 () ;
F_16 () ;
}
F_17 () ;
F_14 ( V_27 ) ;
} else {
F_5 () ;
}
F_1 () ;
F_18 ( V_6 ) ;
}
void F_33 ( struct V_2 * V_3 , unsigned long V_29 )
{
int V_17 = F_21 () ;
if ( F_22 ( V_17 , V_3 -> V_20 ) != 0 ) {
unsigned long V_6 ;
int V_24 , V_25 , V_26 ;
V_25 = F_28 ( V_17 , V_3 -> V_20 ) ;
V_29 &= ( V_28 << 1 ) ;
F_6 ( V_6 ) ;
V_24 = F_7 () ;
F_14 ( V_29 | V_25 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_26 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_26 < 0 )
goto V_30;
F_14 ( F_15 ( V_26 ) ) ;
F_12 () ;
F_16 () ;
F_17 () ;
V_30:
F_14 ( V_24 ) ;
F_4 ( V_3 ) ;
F_18 ( V_6 ) ;
}
}
void F_34 ( unsigned long V_29 )
{
unsigned long V_6 ;
int V_24 , V_26 ;
F_6 ( V_6 ) ;
V_24 = F_7 () ;
V_29 &= ( V_28 << 1 ) ;
F_14 ( V_29 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_26 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_26 >= 0 ) {
F_14 ( F_15 ( V_26 ) ) ;
F_12 () ;
F_16 () ;
F_17 () ;
}
F_14 ( V_24 ) ;
F_1 () ;
F_18 ( V_6 ) ;
}
void F_35 ( struct V_2 * V_3 , unsigned long V_31 , T_1 V_32 )
{
unsigned long V_6 ;
T_2 * V_33 ;
T_3 * V_34 ;
T_4 * V_35 ;
T_1 * V_36 ;
int V_26 , V_27 ;
if ( V_37 -> V_38 != V_3 -> V_20 )
return;
F_6 ( V_6 ) ;
V_27 = F_7 () & V_39 ;
V_31 &= ( V_28 << 1 ) ;
F_14 ( V_31 | V_27 ) ;
V_33 = F_36 ( V_3 -> V_20 , V_31 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_34 = F_37 ( V_33 , V_31 ) ;
V_35 = F_38 ( V_34 , V_31 ) ;
V_26 = F_31 () ;
#ifdef F_39
if ( F_40 ( * V_35 ) ) {
unsigned long V_40 ;
F_41 ( V_41 ) ;
V_36 = ( T_1 * ) V_35 ;
V_40 = F_42 ( F_43 ( * V_36 ) ) ;
F_8 ( V_40 ) ;
F_9 ( V_40 + ( V_42 >> 7 ) ) ;
F_12 () ;
if ( V_26 < 0 )
F_44 () ;
else
F_16 () ;
F_17 () ;
F_41 ( V_43 ) ;
} else
#endif
{
V_36 = F_45 ( V_35 , V_31 ) ;
#if F_46 ( V_44 ) && F_46 ( V_45 )
F_8 ( V_36 -> V_46 ) ;
V_36 ++ ;
F_9 ( V_36 -> V_46 ) ;
#else
F_8 ( F_42 ( F_43 ( * V_36 ++ ) ) ) ;
F_9 ( F_42 ( F_43 ( * V_36 ) ) ) ;
#endif
F_12 () ;
if ( V_26 < 0 )
F_44 () ;
else
F_16 () ;
}
F_17 () ;
F_4 ( V_3 ) ;
F_18 ( V_6 ) ;
}
void F_47 ( unsigned long V_47 , unsigned long V_48 ,
unsigned long V_49 , unsigned long V_50 )
{
unsigned long V_6 ;
unsigned long V_51 ;
unsigned long V_52 ;
unsigned long V_7 ;
F_6 ( V_6 ) ;
V_7 = F_7 () ;
V_52 = F_48 () ;
V_51 = F_10 () ;
F_49 ( V_51 + 1 ) ;
F_11 ( V_51 ) ;
F_17 () ;
F_41 ( V_50 ) ;
F_14 ( V_49 ) ;
F_8 ( V_47 ) ;
F_9 ( V_48 ) ;
F_12 () ;
F_16 () ;
F_17 () ;
F_14 ( V_7 ) ;
F_17 () ;
F_41 ( V_52 ) ;
F_5 () ;
F_18 ( V_6 ) ;
}
int T_5 F_50 ( void )
{
unsigned int V_53 ;
unsigned long V_6 ;
F_6 ( V_6 ) ;
F_41 ( V_41 ) ;
F_51 () ;
V_53 = F_48 () ;
F_41 ( V_43 ) ;
F_18 ( V_6 ) ;
return V_53 == V_41 ;
}
static int T_5 F_52 ( char * V_54 )
{
F_53 ( & V_54 , & V_55 ) ;
return 1 ;
}
void F_54 ( void )
{
F_41 ( V_43 ) ;
F_49 ( 0 ) ;
if ( F_2 () == V_56 ||
F_2 () == V_57 ||
F_2 () == V_58 )
F_55 ( 0 ) ;
if ( V_59 ) {
T_6 V_60 = V_61 | V_62 ;
#ifdef F_56
V_60 |= V_63 ;
#endif
F_57 ( V_60 ) ;
}
F_5 () ;
if ( V_55 ) {
if ( V_55 > 1 && V_55 <= V_11 . V_14 ) {
int V_51 = V_11 . V_14 - V_55 ;
F_49 ( V_51 ) ;
F_11 ( V_51 - 1 ) ;
F_58 ( L_1 , V_55 ) ;
} else
F_58 ( L_2 , V_55 ) ;
}
F_59 () ;
}
