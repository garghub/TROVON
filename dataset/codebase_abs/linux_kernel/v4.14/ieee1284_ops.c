T_1 F_1 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 ,
int V_5 )
{
int V_6 = 1 ;
T_2 V_7 = 0 ;
const unsigned char * V_8 = V_3 ;
unsigned char V_9 ;
struct V_10 * V_11 = V_2 -> V_12 -> V_13 ;
unsigned char V_14 = ( V_15
| V_16 ) ;
if ( V_2 -> V_17 != V_18 ) {
F_2 ( V_2 ) ;
V_6 = 0 ;
}
V_2 -> V_12 -> V_19 . V_20 = V_21 ;
F_3 ( V_2 , V_14 ) ;
F_4 ( V_2 ) ;
while ( V_7 < V_4 ) {
unsigned long V_22 = V_23 + V_11 -> V_24 ;
long V_25 = F_5 ( 10 ) ;
unsigned char V_26 = ( V_27
| V_28 ) ;
unsigned char V_29 = ( V_27
| V_28 ) ;
do {
if ( ! F_6 ( V_2 , V_26 , V_29 ) )
goto V_30;
if ( ( F_7 ( V_2 ) &
( V_31 |
V_32 |
V_27 ) )
!= ( V_32 |
V_27 ) )
goto V_33;
if ( ! F_8 ( V_23 , V_22 ) )
break;
if ( V_7 && V_6 ) {
F_9 ( V_11 ) ;
F_10 ( V_25 ) ;
F_11 ( V_11 ) ;
}
else
F_12 ( V_2 , V_25 ) ;
if ( F_13 ( V_34 ) )
break;
V_25 *= 2 ;
} while ( F_8 ( V_23 , V_22 ) );
if ( F_13 ( V_34 ) )
break;
F_14 ( V_35 L_1 , V_2 -> V_36 ) ;
break;
V_30:
V_9 = * V_8 ++ ;
F_15 ( V_2 , V_9 ) ;
F_16 ( 1 ) ;
F_3 ( V_2 , V_14 | V_37 ) ;
F_16 ( 1 ) ;
F_3 ( V_2 , V_14 ) ;
F_16 ( 1 ) ;
V_7 ++ ;
if ( F_8 ( V_23 , V_22 ) )
if ( ! F_17 ( V_11 )
&& F_18 () )
F_19 () ;
}
V_33:
V_2 -> V_12 -> V_19 . V_20 = V_38 ;
return V_7 ;
}
T_1 F_20 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 ,
int V_5 )
{
#ifndef F_21
return 0 ;
#else
unsigned char * V_39 = V_3 ;
int V_40 ;
unsigned char V_9 = 0 ;
V_4 *= 2 ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ ) {
unsigned char V_41 ;
if ( ( ( V_40 & 1 ) == 0 ) &&
( F_7 ( V_2 ) & V_27 ) ) {
goto V_42;
}
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
V_2 -> V_19 . V_20 = V_44 ;
if ( F_6 ( V_2 ,
V_45 , 0 ) ) {
F_14 ( V_35
L_2 ,
V_2 -> V_36 , V_40 / 2 ) ;
F_22 ( V_2 , V_43 , 0 ) ;
break;
}
V_41 = F_7 ( V_2 ) >> 3 ;
V_41 &= ~ 8 ;
if ( ( V_41 & 0x10 ) == 0 )
V_41 |= 8 ;
V_41 &= 0xf ;
F_22 ( V_2 , V_43 , 0 ) ;
if ( F_6 ( V_2 ,
V_45 ,
V_45 ) ) {
F_14 ( V_35
L_3 ,
V_2 -> V_36 ) ;
break;
}
if ( V_40 & 1 ) {
V_9 |= V_41 << 4 ;
* V_39 ++ = V_9 ;
} else
V_9 = V_41 ;
}
if ( V_40 == V_4 ) {
if ( F_7 ( V_2 ) & V_27 ) {
V_42:
F_14 ( V_35
L_4 ,
V_2 -> V_36 , V_40 / 2 ) ;
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
V_2 -> V_12 -> V_19 . V_20 = V_46 ;
}
else
V_2 -> V_12 -> V_19 . V_20 = V_47 ;
}
return V_40 / 2 ;
#endif
}
T_1 F_23 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 ,
int V_5 )
{
#ifndef F_21
return 0 ;
#else
unsigned char * V_39 = V_3 ;
T_2 V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
unsigned char V_9 ;
if ( F_7 ( V_2 ) & V_27 ) {
goto V_42;
}
F_24 ( V_2 ) ;
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
V_2 -> V_12 -> V_19 . V_20 = V_44 ;
if ( F_6 ( V_2 ,
V_45 ,
0 ) ) {
F_22 ( V_2 , V_43 ,
0 ) ;
F_14 ( V_35 L_5 ,
V_2 -> V_36 ) ;
break;
}
V_9 = F_25 ( V_2 ) ;
* V_39 ++ = V_9 ;
F_22 ( V_2 , V_43 , 0 ) ;
if ( F_6 ( V_2 ,
V_45 ,
V_45 ) ) {
F_14 ( V_35 L_6 ,
V_2 -> V_36 ) ;
break;
}
F_22 ( V_2 ,
V_37 ,
V_37 ) ;
F_16 ( 5 ) ;
F_22 ( V_2 , V_37 , 0 ) ;
}
if ( V_7 == V_4 ) {
if ( F_7 ( V_2 ) & V_27 ) {
V_42:
F_14 ( V_35
L_7 ,
V_2 -> V_36 , V_7 ) ;
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
V_2 -> V_12 -> V_19 . V_20 = V_46 ;
}
else
V_2 -> V_12 -> V_19 . V_20 = V_47 ;
}
return V_7 ;
#endif
}
static inline
int F_26 ( struct V_1 * V_2 )
{
int V_48 ;
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
F_24 ( V_2 ) ;
F_16 ( 5 ) ;
F_22 ( V_2 ,
V_16 ,
0 ) ;
V_48 = F_6 ( V_2 ,
V_31 , 0 ) ;
if ( ! V_48 ) {
F_14 ( V_35 L_8 ,
V_2 -> V_36 ) ;
V_2 -> V_19 . V_20 = V_46 ;
} else {
F_14 ( V_35 L_9 ,
V_2 -> V_36 ) ;
V_2 -> V_19 . V_20 = V_49 ;
}
return V_48 ;
}
static inline
int F_27 ( struct V_1 * V_2 )
{
int V_48 ;
F_22 ( V_2 ,
V_16
| V_43 ,
V_16
| V_43 ) ;
V_48 = F_6 ( V_2 ,
V_31 ,
V_31 ) ;
if ( ! V_48 ) {
F_4 ( V_2 ) ;
F_14 ( V_35 L_10 ,
V_2 -> V_36 ) ;
V_2 -> V_19 . V_20 = V_38 ;
} else {
F_14 ( V_35
L_11 ,
V_2 -> V_36 ) ;
V_2 -> V_19 . V_20 = V_49 ;
}
return V_48 ;
}
T_1 F_28 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 ,
int V_5 )
{
#ifndef F_21
return 0 ;
#else
const unsigned char * V_39 = V_3 ;
T_1 V_50 ;
int V_51 ;
V_2 = V_2 -> V_12 ;
if ( V_2 -> V_19 . V_20 != V_38 )
if ( F_27 ( V_2 ) )
return 0 ;
V_2 -> V_19 . V_20 = V_21 ;
F_22 ( V_2 ,
V_43
| V_37
| V_16 ,
V_16 ) ;
for ( V_50 = 0 ; V_50 < V_4 ; V_50 ++ , V_39 ++ ) {
unsigned long V_22 = V_23 + V_2 -> V_13 -> V_24 ;
unsigned char V_9 ;
V_9 = * V_39 ;
V_52:
F_15 ( V_2 , V_9 ) ;
F_22 ( V_2 , V_37 ,
V_37 ) ;
F_16 ( 5 ) ;
for ( V_51 = 0 ; V_51 < 100 ; V_51 ++ ) {
if ( ! F_6 ( V_2 ,
V_28 , 0 ) )
goto V_53;
if ( F_13 ( V_34 ) ) {
F_22 ( V_2 ,
V_37 ,
0 ) ;
break;
}
}
F_14 ( V_35 L_12 , V_2 -> V_36 ) ;
F_22 ( V_2 , V_16 ,
V_16 ) ;
F_16 ( 50 ) ;
if ( F_7 ( V_2 ) & V_31 ) {
F_22 ( V_2 , V_16 , 0 ) ;
break;
}
F_22 ( V_2 , V_16 , 0 ) ;
F_16 ( 50 ) ;
if ( ! ( F_7 ( V_2 ) & V_31 ) )
break;
F_14 ( V_35 L_13 ,
V_2 -> V_36 ) ;
if ( F_29 ( V_23 , V_22 ) ) break;
goto V_52;
V_53:
F_22 ( V_2 , V_37 , 0 ) ;
F_16 ( 5 ) ;
if ( F_6 ( V_2 ,
V_28 ,
V_28 ) )
break;
}
V_2 -> V_19 . V_20 = V_38 ;
return V_50 ;
#endif
}
T_1 F_30 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 , int V_5 )
{
#ifndef F_21
return 0 ;
#else
struct V_10 * V_11 = V_2 -> V_13 ;
unsigned char * V_39 = V_3 ;
int V_54 = 0 ;
unsigned char V_14 ;
int V_55 = 0 ;
T_2 V_7 = 0 ;
V_2 = V_2 -> V_12 ;
if ( V_2 -> V_19 . V_20 != V_46 )
if ( F_26 ( V_2 ) )
return 0 ;
V_2 -> V_19 . V_20 = V_44 ;
V_14 = F_31 ( V_2 ) ;
V_14 &= ~ ( V_37 | V_16 |
V_43 ) ;
F_3 ( V_2 ,
V_14 | V_43 ) ;
while ( V_7 < V_4 ) {
unsigned long V_22 = V_23 + V_11 -> V_24 ;
unsigned char V_9 ;
int V_56 ;
while ( F_6 ( V_2 , V_45 , 0 ) ) {
if ( V_7 )
goto V_57;
if ( ! F_8 ( V_23 , V_22 ) )
goto V_57;
if ( V_7 && V_11 -> V_2 -> V_17 != V_18 ) {
F_9 ( V_11 ) ;
F_10 ( F_5 ( 40 ) ) ;
F_11 ( V_11 ) ;
}
else
F_12 ( V_2 , F_5 ( 40 ) ) ;
if ( F_13 ( V_34 ) )
goto V_57;
}
if ( V_55 )
V_56 = 0 ;
else
V_56 = ( F_7 ( V_2 ) &
V_28 ) ? 1 : 0 ;
V_9 = F_25 ( V_2 ) ;
if ( V_56 ) {
if ( V_9 & 0x80 ) {
F_14 ( V_35 L_14
L_15 ,
V_2 -> V_36 , V_9 ) ;
goto V_57;
}
else if ( V_2 -> V_19 . V_58 != V_59 )
F_14 ( V_35 L_16
L_17 ,
V_2 -> V_36 ) ;
V_54 = V_9 + 1 ;
if ( V_54 > ( V_4 - V_7 ) ) {
F_14 ( V_35 L_18
L_19 , V_2 -> V_36 ,
V_54 ) ;
break;
}
V_55 = 1 ;
}
F_3 ( V_2 , V_14 ) ;
if ( F_6 ( V_2 , V_45 ,
V_45 ) ) {
F_14 ( V_35 L_20 ) ;
if ( V_56 )
F_32 ( V_60
L_21 ,
V_2 -> V_36 , V_9 ) ;
break;
}
F_3 ( V_2 ,
V_14 | V_43 ) ;
if ( V_56 )
continue;
if ( V_55 ) {
V_55 = 0 ;
memset ( V_39 , V_9 , V_54 ) ;
V_39 += V_54 ;
V_7 += V_54 ;
F_14 ( V_35 L_22 ,
V_2 -> V_36 , V_54 ) ;
} else {
* V_39 = V_9 ;
V_39 ++ , V_7 ++ ;
}
}
V_57:
V_2 -> V_19 . V_20 = V_46 ;
return V_7 ;
#endif
}
T_1 F_33 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 ,
int V_5 )
{
#ifndef F_21
return 0 ;
#else
const unsigned char * V_39 = V_3 ;
T_1 V_50 ;
int V_51 ;
V_2 = V_2 -> V_12 ;
if ( V_2 -> V_19 . V_20 != V_38 )
if ( F_27 ( V_2 ) )
return 0 ;
V_2 -> V_19 . V_20 = V_21 ;
F_22 ( V_2 ,
V_43
| V_37
| V_16 ,
V_43
| V_16 ) ;
for ( V_50 = 0 ; V_50 < V_4 ; V_50 ++ , V_39 ++ ) {
unsigned long V_22 = V_23 + V_2 -> V_13 -> V_24 ;
unsigned char V_9 ;
V_9 = * V_39 ;
V_52:
F_15 ( V_2 , V_9 ) ;
F_22 ( V_2 , V_37 ,
V_37 ) ;
F_16 ( 5 ) ;
for ( V_51 = 0 ; V_51 < 100 ; V_51 ++ ) {
if ( ! F_6 ( V_2 ,
V_28 , 0 ) )
goto V_53;
if ( F_13 ( V_34 ) ) {
F_22 ( V_2 ,
V_37 ,
0 ) ;
break;
}
}
F_14 ( V_35 L_12 , V_2 -> V_36 ) ;
F_22 ( V_2 , V_16 ,
V_16 ) ;
F_16 ( 50 ) ;
if ( F_7 ( V_2 ) & V_31 ) {
F_22 ( V_2 , V_16 , 0 ) ;
break;
}
F_22 ( V_2 , V_16 , 0 ) ;
F_16 ( 50 ) ;
if ( ! ( F_7 ( V_2 ) & V_31 ) )
break;
F_14 ( V_35 L_13 ,
V_2 -> V_36 ) ;
if ( F_29 ( V_23 , V_22 ) ) break;
goto V_52;
V_53:
F_22 ( V_2 , V_37 , 0 ) ;
F_16 ( 5 ) ;
if ( F_6 ( V_2 ,
V_28 ,
V_28 ) )
break;
}
V_2 -> V_19 . V_20 = V_38 ;
return V_50 ;
#endif
}
T_1 F_34 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 ,
int V_5 )
{
unsigned char * V_61 = ( unsigned char * ) V_3 ;
T_1 V_62 = 0 ;
F_22 ( V_2 ,
V_37 |
V_43 |
V_15 |
V_16 ,
V_37 |
V_16 ) ;
V_2 -> V_63 -> V_64 ( V_2 ) ;
for (; V_4 > 0 ; V_4 -- , V_61 ++ ) {
F_15 ( V_2 , * V_61 ) ;
F_22 ( V_2 , V_43 ,
V_43 ) ;
if ( F_35 ( V_2 , V_28 , 0 , 10 ) )
break;
F_22 ( V_2 , V_43 , 0 ) ;
if ( F_35 ( V_2 , V_28 ,
V_28 , 5 ) )
break;
V_62 ++ ;
}
F_22 ( V_2 , V_37 , 0 ) ;
return V_62 ;
}
T_1 F_36 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 ,
int V_5 )
{
unsigned char * V_61 = ( unsigned char * ) V_3 ;
unsigned V_62 = 0 ;
F_22 ( V_2 ,
V_37 |
V_43 |
V_15 |
V_16 ,
V_16 ) ;
V_2 -> V_63 -> V_65 ( V_2 ) ;
for (; V_4 > 0 ; V_4 -- , V_61 ++ ) {
F_22 ( V_2 ,
V_43 ,
V_43 ) ;
if ( F_6 ( V_2 , V_28 , 0 ) ) {
break;
}
* V_61 = F_25 ( V_2 ) ;
F_22 ( V_2 , V_43 , 0 ) ;
if ( F_35 ( V_2 , V_28 ,
V_28 , 5 ) ) {
break;
}
V_62 ++ ;
}
V_2 -> V_63 -> V_64 ( V_2 ) ;
return V_62 ;
}
T_1 F_37 ( struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 ,
int V_5 )
{
unsigned char * V_61 = ( unsigned char * ) V_3 ;
T_1 V_62 = 0 ;
F_22 ( V_2 ,
V_37 |
V_43 |
V_15 |
V_16 ,
V_37 |
V_16 ) ;
V_2 -> V_63 -> V_64 ( V_2 ) ;
for (; V_4 > 0 ; V_4 -- , V_61 ++ ) {
F_15 ( V_2 , * V_61 ) ;
F_22 ( V_2 , V_15 ,
V_15 ) ;
if ( F_35 ( V_2 , V_28 , 0 , 10 ) )
break;
F_22 ( V_2 , V_15 , 0 ) ;
if ( F_35 ( V_2 , V_28 ,
V_28 , 5 ) )
break;
V_62 ++ ;
}
F_22 ( V_2 , V_37 , 0 ) ;
return V_62 ;
}
T_1 F_38 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 ,
int V_5 )
{
unsigned char * V_61 = ( unsigned char * ) V_3 ;
unsigned V_62 = 0 ;
F_22 ( V_2 ,
V_37 |
V_43 |
V_15 |
V_16 ,
V_16 ) ;
V_2 -> V_63 -> V_65 ( V_2 ) ;
for (; V_4 > 0 ; V_4 -- , V_61 ++ ) {
F_22 ( V_2 , V_15 ,
V_15 ) ;
if ( F_6 ( V_2 , V_28 , 0 ) ) {
break;
}
* V_61 = F_25 ( V_2 ) ;
F_22 ( V_2 , V_15 ,
0 ) ;
if ( F_35 ( V_2 , V_28 ,
V_28 , 5 ) )
break;
V_62 ++ ;
}
V_2 -> V_63 -> V_64 ( V_2 ) ;
return V_62 ;
}
