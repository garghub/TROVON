static inline void F_1 ( void )
{
switch ( F_2 () ) {
case V_1 :
case V_2 :
F_3 ( 4 ) ;
break;
default:
break;
}
}
static inline void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 & V_6 )
F_1 () ;
}
void F_5 ( void )
{
unsigned long V_7 ;
unsigned long V_8 ;
int V_9 , V_10 ;
F_6 ( V_7 ) ;
V_8 = F_7 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
V_9 = F_10 () ;
if ( V_11 ) {
if ( V_12 . V_13 ) {
F_11 ( 0 ) ;
F_12 () ;
F_13 () ;
}
V_10 = V_12 . V_13 +
V_12 . V_14 ;
for ( V_9 = V_12 . V_13 ;
V_9 < V_10 ;
V_9 ++ ) {
F_11 ( V_9 ) ;
F_12 () ;
F_13 () ;
}
} else {
while ( V_9 < V_12 . V_15 ) {
F_14 ( F_15 ( V_9 ) ) ;
F_11 ( V_9 ) ;
F_12 () ;
F_16 () ;
V_9 ++ ;
}
}
F_17 () ;
F_14 ( V_8 ) ;
F_1 () ;
F_18 ( V_7 ) ;
}
void F_19 ( struct V_16 * V_17 )
{
int V_18 ;
F_20 () ;
V_18 = F_21 () ;
if ( F_22 ( V_18 , V_17 ) != 0 ) {
F_23 ( V_17 , V_18 ) ;
}
F_24 () ;
}
void F_25 ( struct V_3 * V_4 , unsigned long V_19 ,
unsigned long V_20 )
{
struct V_16 * V_17 = V_4 -> V_21 ;
int V_18 = F_21 () ;
if ( F_22 ( V_18 , V_17 ) != 0 ) {
unsigned long V_22 , V_7 ;
F_6 ( V_7 ) ;
V_19 = F_26 ( V_19 , V_23 << 1 ) ;
V_20 = F_27 ( V_20 , V_23 << 1 ) ;
V_22 = ( V_20 - V_19 ) >> ( V_24 + 1 ) ;
if ( V_22 <= ( V_12 . V_14 ?
V_12 . V_15 / 8 :
V_12 . V_15 / 2 ) ) {
int V_25 = F_7 () ;
int V_26 = F_28 ( V_18 , V_17 ) ;
while ( V_19 < V_20 ) {
int V_27 ;
F_14 ( V_19 | V_26 ) ;
V_19 += ( V_23 << 1 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_27 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_27 < 0 )
continue;
F_14 ( F_15 ( V_27 ) ) ;
F_12 () ;
F_16 () ;
}
F_17 () ;
F_14 ( V_25 ) ;
} else {
F_23 ( V_17 , V_18 ) ;
}
F_1 () ;
F_18 ( V_7 ) ;
}
}
void F_32 ( unsigned long V_19 , unsigned long V_20 )
{
unsigned long V_22 , V_7 ;
F_6 ( V_7 ) ;
V_22 = ( V_20 - V_19 + ( V_23 - 1 ) ) >> V_24 ;
V_22 = ( V_22 + 1 ) >> 1 ;
if ( V_22 <= ( V_12 . V_14 ?
V_12 . V_15 / 8 :
V_12 . V_15 / 2 ) ) {
int V_28 = F_7 () ;
V_19 &= ( V_29 << 1 ) ;
V_20 += ( ( V_23 << 1 ) - 1 ) ;
V_20 &= ( V_29 << 1 ) ;
while ( V_19 < V_20 ) {
int V_27 ;
F_14 ( V_19 ) ;
V_19 += ( V_23 << 1 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_27 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_27 < 0 )
continue;
F_14 ( F_15 ( V_27 ) ) ;
F_12 () ;
F_16 () ;
}
F_17 () ;
F_14 ( V_28 ) ;
} else {
F_5 () ;
}
F_1 () ;
F_18 ( V_7 ) ;
}
void F_33 ( struct V_3 * V_4 , unsigned long V_30 )
{
int V_18 = F_21 () ;
if ( F_22 ( V_18 , V_4 -> V_21 ) != 0 ) {
unsigned long V_7 ;
int V_25 , V_26 , V_27 ;
V_26 = F_28 ( V_18 , V_4 -> V_21 ) ;
V_30 &= ( V_29 << 1 ) ;
F_6 ( V_7 ) ;
V_25 = F_7 () ;
F_14 ( V_30 | V_26 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_27 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_27 < 0 )
goto V_31;
F_14 ( F_15 ( V_27 ) ) ;
F_12 () ;
F_16 () ;
F_17 () ;
V_31:
F_14 ( V_25 ) ;
F_4 ( V_4 ) ;
F_18 ( V_7 ) ;
}
}
void F_34 ( unsigned long V_30 )
{
unsigned long V_7 ;
int V_25 , V_27 ;
F_6 ( V_7 ) ;
V_25 = F_7 () ;
V_30 &= ( V_29 << 1 ) ;
F_14 ( V_30 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_27 = F_31 () ;
F_8 ( 0 ) ;
F_9 ( 0 ) ;
if ( V_27 >= 0 ) {
F_14 ( F_15 ( V_27 ) ) ;
F_12 () ;
F_16 () ;
F_17 () ;
}
F_14 ( V_25 ) ;
F_1 () ;
F_18 ( V_7 ) ;
}
void F_35 ( struct V_3 * V_4 , unsigned long V_32 , T_1 V_33 )
{
unsigned long V_7 ;
T_2 * V_34 ;
T_3 * V_35 ;
T_4 * V_36 ;
T_1 * V_37 ;
int V_27 , V_28 ;
if ( V_38 -> V_39 != V_4 -> V_21 )
return;
F_6 ( V_7 ) ;
V_28 = F_7 () & V_40 ;
V_32 &= ( V_29 << 1 ) ;
F_14 ( V_32 | V_28 ) ;
V_34 = F_36 ( V_4 -> V_21 , V_32 ) ;
F_12 () ;
F_29 () ;
F_30 () ;
V_35 = F_37 ( V_34 , V_32 ) ;
V_36 = F_38 ( V_35 , V_32 ) ;
V_27 = F_31 () ;
#ifdef F_39
if ( F_40 ( * V_36 ) ) {
unsigned long V_41 ;
F_41 ( V_42 ) ;
V_37 = ( T_1 * ) V_36 ;
V_41 = F_42 ( F_43 ( * V_37 ) ) ;
F_8 ( V_41 ) ;
F_9 ( V_41 + ( V_43 >> 7 ) ) ;
F_12 () ;
if ( V_27 < 0 )
F_44 () ;
else
F_16 () ;
F_17 () ;
F_41 ( V_44 ) ;
} else
#endif
{
V_37 = F_45 ( V_36 , V_32 ) ;
#if F_46 ( V_45 ) && F_46 ( V_46 )
F_8 ( V_37 -> V_47 ) ;
V_37 ++ ;
F_9 ( V_37 -> V_47 ) ;
#else
F_8 ( F_42 ( F_43 ( * V_37 ++ ) ) ) ;
F_9 ( F_42 ( F_43 ( * V_37 ) ) ) ;
#endif
F_12 () ;
if ( V_27 < 0 )
F_44 () ;
else
F_16 () ;
}
F_17 () ;
F_4 ( V_4 ) ;
F_18 ( V_7 ) ;
}
void F_47 ( unsigned long V_48 , unsigned long V_49 ,
unsigned long V_50 , unsigned long V_51 )
{
unsigned long V_7 ;
unsigned long V_52 ;
unsigned long V_53 ;
unsigned long V_8 ;
F_6 ( V_7 ) ;
V_8 = F_7 () ;
V_53 = F_48 () ;
V_52 = F_10 () ;
F_49 ( V_52 + 1 ) ;
F_11 ( V_52 ) ;
F_17 () ;
F_41 ( V_51 ) ;
F_14 ( V_50 ) ;
F_8 ( V_48 ) ;
F_9 ( V_49 ) ;
F_12 () ;
F_16 () ;
F_17 () ;
F_14 ( V_8 ) ;
F_17 () ;
F_41 ( V_53 ) ;
F_5 () ;
F_18 ( V_7 ) ;
}
int T_5 F_50 ( void )
{
unsigned int V_54 ;
unsigned long V_7 ;
F_6 ( V_7 ) ;
F_41 ( V_42 ) ;
F_51 () ;
V_54 = F_48 () ;
F_41 ( V_44 ) ;
F_18 ( V_7 ) ;
return V_54 == V_42 ;
}
static int T_5 F_52 ( char * V_55 )
{
F_53 ( & V_55 , & V_56 ) ;
return 1 ;
}
void F_54 ( void )
{
F_41 ( V_44 ) ;
F_49 ( 0 ) ;
if ( F_2 () == V_57 ||
F_2 () == V_58 ||
F_2 () == V_59 )
F_55 ( 0 ) ;
if ( V_60 ) {
T_6 V_61 = V_62 | V_63 ;
#ifdef F_56
V_61 |= V_64 ;
#endif
F_57 ( V_61 ) ;
}
F_5 () ;
if ( V_56 ) {
if ( V_56 > 1 && V_56 <= V_12 . V_15 ) {
int V_52 = V_12 . V_15 - V_56 ;
F_49 ( V_52 ) ;
F_11 ( V_52 - 1 ) ;
F_58 ( L_1 , V_56 ) ;
} else
F_58 ( L_2 , V_56 ) ;
}
F_59 () ;
}
