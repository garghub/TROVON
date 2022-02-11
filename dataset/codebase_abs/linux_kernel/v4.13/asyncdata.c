static inline int F_1 ( unsigned char V_1 )
{
if ( V_1 < V_2 ) return 1 ;
if ( V_1 == V_3 ) return 1 ;
if ( V_1 == V_4 ) return 1 ;
return 0 ;
}
static unsigned F_2 ( unsigned V_5 , struct V_6 * V_7 )
{
unsigned char * V_8 = V_7 -> V_9 + V_7 -> V_10 ;
struct V_11 * V_12 = V_7 -> V_12 ;
unsigned V_13 = V_12 -> V_13 ;
unsigned V_14 = 0 ;
unsigned char V_1 ;
while ( V_14 < V_5 ) {
V_1 = * V_8 ++ ;
V_14 ++ ;
switch ( V_1 ) {
case '\n' :
if ( V_13 == 0 && V_12 -> V_15 [ 0 ] == '\r' ) {
V_12 -> V_15 [ 0 ] = 0 ;
break;
}
case '\r' :
if ( V_13 >= V_16 ) {
F_3 ( V_12 -> V_17 , L_1 ,
V_13 ) ;
V_13 = V_16 ;
}
V_12 -> V_13 = V_13 ;
F_4 ( V_18 , L_2 ,
V_13 , V_12 -> V_15 ) ;
F_5 ( V_12 ) ;
V_13 = 0 ;
V_12 -> V_15 [ 0 ] = V_1 ;
if ( V_12 -> V_19 && ! ( V_7 -> V_20 & V_21 ) )
V_7 -> V_20 &= ~ V_22 ;
goto exit;
case V_23 :
if ( V_7 -> V_20 & V_24 ) {
V_7 -> V_20 &= ~ V_24 ;
} else if ( V_12 -> V_19 ||
( V_7 -> V_20 & V_21 ) ) {
V_7 -> V_20 |= V_24 ;
goto exit;
}
default:
if ( V_13 < V_16 )
V_12 -> V_15 [ V_13 ] = V_1 ;
V_13 ++ ;
}
}
exit:
V_12 -> V_13 = V_13 ;
return V_14 ;
}
static unsigned F_6 ( unsigned V_5 , struct V_6 * V_7 )
{
unsigned char * V_8 = V_7 -> V_9 + V_7 -> V_10 ;
F_4 ( V_25 , L_2 , V_5 , V_8 ) ;
F_7 ( V_7 -> V_12 , V_8 , V_5 ) ;
return V_5 ;
}
static unsigned F_8 ( unsigned V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_20 = V_27 -> V_20 ;
T_1 V_28 = V_27 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 ;
unsigned char * V_8 = V_7 -> V_9 + V_7 -> V_10 ;
unsigned V_14 = 0 ;
unsigned char V_1 ;
if ( V_20 & V_33 ) {
if ( ! V_5 )
return 0 ;
V_20 &= ~ V_33 ;
goto V_34;
}
while ( V_14 < V_5 ) {
V_1 = * V_8 ++ ;
V_14 ++ ;
if ( V_1 == V_23 ) {
if ( V_20 & V_24 ) {
V_20 &= ~ V_24 ;
} else if ( V_12 -> V_19 || ( V_20 & V_21 ) ) {
V_20 |= V_24 ;
break;
}
}
if ( V_1 == V_4 ) {
if ( V_14 >= V_5 ) {
V_20 |= V_33 ;
break;
}
V_34:
V_1 = * V_8 ++ ;
V_14 ++ ;
if ( V_1 == V_23 ) {
if ( V_20 & V_24 ) {
V_20 &= ~ V_24 ;
} else if ( V_12 -> V_19 ||
( V_20 & V_21 ) ) {
V_20 |=
V_24 | V_33 ;
break;
}
}
V_1 ^= V_2 ;
#ifdef F_9
if ( ! F_1 ( V_1 ) )
F_10 ( V_35 , L_3 , V_1 ) ;
#endif
} else if ( V_1 == V_3 ) {
if ( V_20 & V_36 ) {
F_10 ( V_35 ,
L_4 ) ;
if ( ! V_31 ) {
F_11 ( V_27 ) ;
} else if ( V_31 -> V_37 < 2 ) {
F_3 ( V_12 -> V_17 ,
L_5 ,
V_31 -> V_37 ) ;
F_11 ( V_27 ) ;
F_12 ( V_31 ) ;
} else if ( V_28 != V_38 ) {
F_13 ( V_12 -> V_17 ,
L_6 ,
V_31 -> V_37 ) ;
F_11 ( V_27 ) ;
F_12 ( V_31 ) ;
} else {
F_14 ( V_31 , V_31 -> V_37 - 2 ) ;
F_15 ( V_27 , V_31 ) ;
}
V_20 &= ~ V_36 ;
V_31 = F_16 ( V_27 ) ;
} else {
#ifdef F_9
++ V_27 -> V_39 ;
#endif
if ( ! V_31 ) {
F_11 ( V_27 ) ;
V_31 = F_16 ( V_27 ) ;
}
}
V_28 = V_40 ;
continue;
#ifdef F_9
} else if ( F_1 ( V_1 ) ) {
F_10 ( V_35 , L_7 , V_1 ) ;
#endif
}
#ifdef F_9
if ( ! ( V_20 & V_36 ) ) {
F_10 ( V_35 , L_8 ,
V_27 -> V_39 ) ;
V_27 -> V_39 = 0 ;
}
#endif
V_20 |= V_36 ;
if ( V_31 ) {
if ( V_31 -> V_37 >= V_27 -> V_41 ) {
F_3 ( V_12 -> V_17 , L_9 ) ;
F_12 ( V_31 ) ;
V_27 -> V_32 = V_31 = NULL ;
} else {
F_17 ( V_31 , V_1 ) ;
V_28 = F_18 ( V_28 , V_1 ) ;
}
}
}
V_27 -> V_20 = V_20 ;
V_27 -> V_29 = V_28 ;
return V_14 ;
}
static unsigned F_19 ( unsigned V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_20 = V_27 -> V_20 ;
struct V_30 * V_31 = V_27 -> V_32 ;
unsigned char * V_8 = V_7 -> V_9 + V_7 -> V_10 ;
unsigned V_14 = 0 ;
unsigned char V_1 ;
if ( ! V_31 ) {
F_16 ( V_27 ) ;
return V_5 ;
}
while ( V_14 < V_5 && V_31 -> V_37 < V_27 -> V_41 ) {
V_1 = * V_8 ++ ;
V_14 ++ ;
if ( V_1 == V_23 ) {
if ( V_20 & V_24 ) {
V_20 &= ~ V_24 ;
} else if ( V_12 -> V_19 || ( V_20 & V_21 ) ) {
V_20 |= V_24 ;
break;
}
}
V_20 |= V_36 ;
F_17 ( V_31 , F_20 ( V_1 ) ) ;
}
if ( V_20 & V_36 ) {
F_15 ( V_27 , V_31 ) ;
V_20 &= ~ V_36 ;
F_16 ( V_27 ) ;
}
V_27 -> V_20 = V_20 ;
return V_14 ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
if ( V_12 -> V_42 == V_43 )
return;
if ( ! ( V_7 -> V_20 & V_24 ) ) {
if ( V_7 -> V_9 [ V_7 -> V_10 ] == V_23 &&
( V_12 -> V_19 || V_7 -> V_20 & V_21 ) ) {
V_7 -> V_10 ++ ;
if ( V_7 -> V_10 == V_7 -> V_44 ||
V_7 -> V_10 == V_45 ) {
V_7 -> V_20 |= V_24 ;
return;
}
} else {
return;
}
}
V_7 -> V_20 &= ~ V_24 ;
switch ( V_7 -> V_9 [ V_7 -> V_10 ] ) {
case 'X' :
if ( V_7 -> V_20 & V_22 )
F_22 ( V_12 -> V_17 ,
L_10 ) ;
V_7 -> V_20 |= V_22 | V_21 ;
V_7 -> V_10 ++ ;
break;
case '.' :
if ( ! ( V_7 -> V_20 & V_21 ) )
F_22 ( V_12 -> V_17 ,
L_11 ) ;
V_7 -> V_20 &= ~ V_21 ;
if ( V_12 -> V_19 )
V_7 -> V_20 &= ~ V_22 ;
V_7 -> V_10 ++ ;
break;
case V_23 :
V_7 -> V_20 |= V_24 ;
if ( ! ( V_12 -> V_19 || V_7 -> V_20 & V_21 ) )
F_22 ( V_12 -> V_17 ,
L_12 ) ;
break;
default:
F_22 ( V_12 -> V_17 , L_13 ,
V_7 -> V_9 [ V_7 -> V_10 ] ) ;
}
}
void F_23 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
unsigned V_5 , V_14 ;
F_10 ( V_46 , L_14 , V_7 -> V_10 , V_7 -> V_44 ) ;
while ( V_7 -> V_10 != V_7 -> V_44 ) {
F_21 ( V_7 ) ;
V_5 = ( V_7 -> V_10 > V_7 -> V_44 ?
V_45 : V_7 -> V_44 ) - V_7 -> V_10 ;
F_10 ( V_46 , L_15 , V_5 ) ;
if ( V_12 -> V_42 == V_43 )
V_14 = F_6 ( V_5 , V_7 ) ;
else if ( V_7 -> V_20 & V_22 )
V_14 = F_2 ( V_5 , V_7 ) ;
else if ( V_12 -> V_27 -> V_47 == V_48 )
V_14 = F_8 ( V_5 , V_7 ) ;
else
V_14 = F_19 ( V_5 , V_7 ) ;
V_7 -> V_10 += V_14 ;
if ( V_7 -> V_10 >= V_45 )
V_7 -> V_10 = 0 ;
F_10 ( V_46 , L_16 , V_7 -> V_10 ) ;
}
}
static struct V_30 * F_24 ( struct V_30 * V_31 )
{
struct V_30 * V_49 ;
T_1 V_28 ;
unsigned char V_1 ;
unsigned char * V_50 ;
int V_37 ;
unsigned int V_51 ;
V_51 = 0 ;
V_28 = V_40 ;
V_50 = V_31 -> V_9 ;
V_37 = V_31 -> V_37 ;
while ( V_37 -- ) {
if ( F_1 ( * V_50 ) )
V_51 ++ ;
V_28 = F_18 ( V_28 , * V_50 ++ ) ;
}
V_28 ^= 0xffff ;
V_49 = F_25 ( V_31 -> V_37 + V_51 + 6 + V_31 -> V_52 ) ;
if ( ! V_49 ) {
F_12 ( V_31 ) ;
return NULL ;
}
F_26 ( V_49 ) ;
F_27 ( V_49 , V_31 -> V_52 ) ;
memcpy ( F_28 ( V_49 ) , F_28 ( V_31 ) , V_31 -> V_52 ) ;
V_49 -> V_52 = V_31 -> V_52 ;
F_29 ( V_49 , V_3 ) ;
while ( V_31 -> V_37 -- ) {
if ( F_1 ( * V_31 -> V_9 ) ) {
F_29 ( V_49 , V_4 ) ;
F_29 ( V_49 , ( * V_31 -> V_9 ++ ) ^ V_2 ) ;
} else
F_29 ( V_49 , * V_31 -> V_9 ++ ) ;
}
V_1 = ( V_28 & 0x00ff ) ;
if ( F_1 ( V_1 ) ) {
F_29 ( V_49 , V_4 ) ;
V_1 ^= V_2 ;
}
F_29 ( V_49 , V_1 ) ;
V_1 = ( ( V_28 >> 8 ) & 0x00ff ) ;
if ( F_1 ( V_1 ) ) {
F_29 ( V_49 , V_4 ) ;
V_1 ^= V_2 ;
}
F_29 ( V_49 , V_1 ) ;
F_29 ( V_49 , V_3 ) ;
F_12 ( V_31 ) ;
return V_49 ;
}
static struct V_30 * F_30 ( struct V_30 * V_31 )
{
struct V_30 * V_53 ;
unsigned char V_1 ;
unsigned char * V_50 ;
int V_37 ;
V_53 = F_25 ( 2 * V_31 -> V_37 + V_31 -> V_52 ) ;
if ( ! V_53 ) {
F_12 ( V_31 ) ;
return NULL ;
}
F_26 ( V_53 ) ;
F_27 ( V_53 , V_31 -> V_52 ) ;
memcpy ( F_28 ( V_53 ) , F_28 ( V_31 ) , V_31 -> V_52 ) ;
V_53 -> V_52 = V_31 -> V_52 ;
V_50 = V_31 -> V_9 ;
V_37 = V_31 -> V_37 ;
while ( V_37 -- ) {
V_1 = F_20 ( * V_50 ++ ) ;
if ( V_1 == V_23 )
F_29 ( V_53 , V_1 ) ;
F_29 ( V_53 , V_1 ) ;
}
F_12 ( V_31 ) ;
return V_53 ;
}
int F_31 ( struct V_26 * V_27 , struct V_30 * V_31 )
{
struct V_11 * V_12 = V_27 -> V_12 ;
unsigned V_37 = V_31 -> V_37 ;
unsigned long V_54 ;
if ( V_27 -> V_47 == V_48 )
V_31 = F_24 ( V_31 ) ;
else
V_31 = F_30 ( V_31 ) ;
if ( ! V_31 ) {
F_13 ( V_12 -> V_17 ,
L_17 ) ;
return - V_55 ;
}
F_32 ( & V_27 -> V_56 , V_31 ) ;
F_33 ( & V_12 -> V_57 , V_54 ) ;
if ( V_12 -> V_58 )
F_34 ( & V_12 -> V_59 ) ;
F_35 ( & V_12 -> V_57 , V_54 ) ;
return V_37 ;
}
