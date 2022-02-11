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
int V_8 ;
F_6 ( V_6 ) ;
V_7 = F_7 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
V_8 = F_10 () ;
while ( V_8 < V_9 . V_10 ) {
F_11 ( F_12 ( V_8 ) ) ;
F_13 ( V_8 ) ;
F_14 () ;
F_15 () ;
V_8 ++ ;
}
F_16 () ;
F_11 ( V_7 ) ;
F_1 () ;
F_17 ( V_6 ) ;
}
void F_18 ( struct V_11 * V_12 )
{
int V_13 ;
F_19 () ;
V_13 = F_20 () ;
if ( F_21 ( V_13 , V_12 ) != 0 ) {
F_22 ( V_12 , V_13 ) ;
}
F_23 () ;
}
void F_24 ( struct V_2 * V_3 , unsigned long V_14 ,
unsigned long V_15 )
{
struct V_11 * V_12 = V_3 -> V_16 ;
int V_13 = F_20 () ;
if ( F_21 ( V_13 , V_12 ) != 0 ) {
unsigned long V_17 , V_6 ;
F_6 ( V_6 ) ;
V_14 = F_25 ( V_14 , V_18 << 1 ) ;
V_15 = F_26 ( V_15 , V_18 << 1 ) ;
V_17 = ( V_15 - V_14 ) >> ( V_19 + 1 ) ;
if ( V_17 <= V_9 . V_10 / 2 ) {
int V_20 = F_7 () ;
int V_21 = F_27 ( V_13 , V_12 ) ;
while ( V_14 < V_15 ) {
int V_22 ;
F_11 ( V_14 | V_21 ) ;
V_14 += ( V_18 << 1 ) ;
F_14 () ;
F_28 () ;
F_29 () ;
V_22 = F_30 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_22 < 0 )
continue;
F_11 ( F_12 ( V_22 ) ) ;
F_14 () ;
F_15 () ;
}
F_16 () ;
F_11 ( V_20 ) ;
} else {
F_22 ( V_12 , V_13 ) ;
}
F_1 () ;
F_17 ( V_6 ) ;
}
}
void F_31 ( unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_17 , V_6 ;
F_6 ( V_6 ) ;
V_17 = ( V_15 - V_14 + ( V_18 - 1 ) ) >> V_19 ;
V_17 = ( V_17 + 1 ) >> 1 ;
if ( V_17 <= V_9 . V_10 / 2 ) {
int V_23 = F_7 () ;
V_14 &= ( V_24 << 1 ) ;
V_15 += ( ( V_18 << 1 ) - 1 ) ;
V_15 &= ( V_24 << 1 ) ;
while ( V_14 < V_15 ) {
int V_22 ;
F_11 ( V_14 ) ;
V_14 += ( V_18 << 1 ) ;
F_14 () ;
F_28 () ;
F_29 () ;
V_22 = F_30 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_22 < 0 )
continue;
F_11 ( F_12 ( V_22 ) ) ;
F_14 () ;
F_15 () ;
}
F_16 () ;
F_11 ( V_23 ) ;
} else {
F_5 () ;
}
F_1 () ;
F_17 ( V_6 ) ;
}
void F_32 ( struct V_2 * V_3 , unsigned long V_25 )
{
int V_13 = F_20 () ;
if ( F_21 ( V_13 , V_3 -> V_16 ) != 0 ) {
unsigned long V_6 ;
int V_20 , V_21 , V_22 ;
V_21 = F_27 ( V_13 , V_3 -> V_16 ) ;
V_25 &= ( V_24 << 1 ) ;
F_6 ( V_6 ) ;
V_20 = F_7 () ;
F_11 ( V_25 | V_21 ) ;
F_14 () ;
F_28 () ;
F_29 () ;
V_22 = F_30 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_22 < 0 )
goto V_26;
F_11 ( F_12 ( V_22 ) ) ;
F_14 () ;
F_15 () ;
F_16 () ;
V_26:
F_11 ( V_20 ) ;
F_4 ( V_3 ) ;
F_17 ( V_6 ) ;
}
}
void F_33 ( unsigned long V_25 )
{
unsigned long V_6 ;
int V_20 , V_22 ;
F_6 ( V_6 ) ;
V_20 = F_7 () ;
V_25 &= ( V_24 << 1 ) ;
F_11 ( V_25 ) ;
F_14 () ;
F_28 () ;
F_29 () ;
V_22 = F_30 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_22 >= 0 ) {
F_11 ( F_12 ( V_22 ) ) ;
F_14 () ;
F_15 () ;
F_16 () ;
}
F_11 ( V_20 ) ;
F_1 () ;
F_17 ( V_6 ) ;
}
void F_34 ( struct V_2 * V_3 , unsigned long V_27 , T_1 V_28 )
{
unsigned long V_6 ;
T_2 * V_29 ;
T_3 * V_30 ;
T_4 * V_31 ;
T_1 * V_32 ;
int V_22 , V_23 ;
if ( V_33 -> V_34 != V_3 -> V_16 )
return;
F_6 ( V_6 ) ;
V_23 = F_7 () & V_35 ;
V_27 &= ( V_24 << 1 ) ;
F_11 ( V_27 | V_23 ) ;
V_29 = F_35 ( V_3 -> V_16 , V_27 ) ;
F_14 () ;
F_28 () ;
F_29 () ;
V_30 = F_36 ( V_29 , V_27 ) ;
V_31 = F_37 ( V_30 , V_27 ) ;
V_22 = F_30 () ;
#ifdef F_38
if ( F_39 ( * V_31 ) ) {
unsigned long V_36 ;
F_40 ( V_37 ) ;
V_32 = ( T_1 * ) V_31 ;
V_36 = F_41 ( F_42 ( * V_32 ) ) ;
F_8 ( V_36 ) ;
F_9 ( V_36 + ( V_38 >> 7 ) ) ;
F_14 () ;
if ( V_22 < 0 )
F_43 () ;
else
F_15 () ;
F_16 () ;
F_40 ( V_39 ) ;
} else
#endif
{
V_32 = F_44 ( V_31 , V_27 ) ;
#if F_45 ( V_40 ) && F_45 ( V_41 )
F_8 ( V_32 -> V_42 ) ;
V_32 ++ ;
F_9 ( V_32 -> V_42 ) ;
#else
F_8 ( F_41 ( F_42 ( * V_32 ++ ) ) ) ;
F_9 ( F_41 ( F_42 ( * V_32 ) ) ) ;
#endif
F_14 () ;
if ( V_22 < 0 )
F_43 () ;
else
F_15 () ;
}
F_16 () ;
F_4 ( V_3 ) ;
F_17 ( V_6 ) ;
}
void F_46 ( unsigned long V_43 , unsigned long V_44 ,
unsigned long V_45 , unsigned long V_46 )
{
unsigned long V_6 ;
unsigned long V_47 ;
unsigned long V_48 ;
unsigned long V_7 ;
F_6 ( V_6 ) ;
V_7 = F_7 () ;
V_48 = F_47 () ;
V_47 = F_10 () ;
F_48 ( V_47 + 1 ) ;
F_13 ( V_47 ) ;
F_16 () ;
F_40 ( V_46 ) ;
F_11 ( V_45 ) ;
F_8 ( V_43 ) ;
F_9 ( V_44 ) ;
F_14 () ;
F_15 () ;
F_16 () ;
F_11 ( V_7 ) ;
F_16 () ;
F_40 ( V_48 ) ;
F_5 () ;
F_17 ( V_6 ) ;
}
int T_5 F_49 ( void )
{
unsigned int V_49 ;
unsigned long V_6 ;
F_6 ( V_6 ) ;
F_40 ( V_37 ) ;
F_50 () ;
V_49 = F_47 () ;
F_40 ( V_39 ) ;
F_17 ( V_6 ) ;
return V_49 == V_37 ;
}
static int T_5 F_51 ( char * V_50 )
{
F_52 ( & V_50 , & V_51 ) ;
return 1 ;
}
void F_53 ( void )
{
F_40 ( V_39 ) ;
F_48 ( 0 ) ;
if ( F_2 () == V_52 ||
F_2 () == V_53 ||
F_2 () == V_54 )
F_54 ( 0 ) ;
if ( V_55 ) {
T_6 V_56 = V_57 | V_58 ;
#ifdef F_55
V_56 |= V_59 ;
#endif
F_56 ( V_56 ) ;
}
F_5 () ;
if ( V_51 ) {
if ( V_51 > 1 && V_51 <= V_9 . V_10 ) {
int V_47 = V_9 . V_10 - V_51 ;
F_48 ( V_47 ) ;
F_13 ( V_47 - 1 ) ;
F_57 ( L_1 , V_51 ) ;
} else
F_57 ( L_2 , V_51 ) ;
}
F_58 () ;
}
