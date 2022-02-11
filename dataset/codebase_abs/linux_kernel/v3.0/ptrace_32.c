void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( struct V_1 * V_3 ,
const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
void * V_8 , void T_1 * V_9 )
{
const struct V_10 * V_11 = V_3 -> V_12 . V_13 ;
unsigned long T_1 * V_14 ;
unsigned long * V_15 = V_8 ;
unsigned long T_1 * V_16 = V_9 ;
unsigned long V_17 ;
if ( V_3 == V_18 )
F_3 () ;
V_6 /= sizeof( V_17 ) ;
V_7 /= sizeof( V_17 ) ;
if ( V_8 ) {
for (; V_7 > 0 && V_6 < 16 ; V_7 -- )
* V_15 ++ = V_11 -> V_19 [ V_6 ++ ] ;
V_14 = ( unsigned long T_1 * ) V_11 -> V_19 [ V_20 ] ;
V_14 -= 16 ;
for (; V_7 > 0 && V_6 < 32 ; V_7 -- ) {
if ( F_4 ( * V_15 ++ , & V_14 [ V_6 ++ ] ) )
return - V_21 ;
}
} else {
for (; V_7 > 0 && V_6 < 16 ; V_7 -- ) {
if ( F_5 ( V_11 -> V_19 [ V_6 ++ ] , V_16 ++ ) )
return - V_21 ;
}
V_14 = ( unsigned long T_1 * ) V_11 -> V_19 [ V_20 ] ;
V_14 -= 16 ;
for (; V_7 > 0 && V_6 < 32 ; V_7 -- ) {
if ( F_4 ( V_17 , & V_14 [ V_6 ++ ] ) ||
F_5 ( V_17 , V_16 ++ ) )
return - V_21 ;
}
}
while ( V_7 > 0 ) {
switch ( V_6 ) {
case 32 :
V_17 = V_11 -> V_22 ;
break;
case 33 :
V_17 = V_11 -> V_23 ;
break;
case 34 :
V_17 = V_11 -> V_24 ;
break;
case 35 :
V_17 = V_11 -> V_25 ;
break;
case 36 :
case 37 :
V_17 = 0 ;
break;
default:
goto V_26;
}
if ( V_8 )
* V_15 ++ = V_17 ;
else if ( F_5 ( V_17 , V_16 ++ ) )
return - V_21 ;
V_6 ++ ;
V_7 -- ;
}
V_26:
V_6 *= sizeof( V_17 ) ;
V_7 *= sizeof( V_17 ) ;
return F_6 ( & V_6 , & V_7 , & V_8 , & V_9 ,
38 * sizeof( V_17 ) , - 1 ) ;
}
static int F_7 ( struct V_1 * V_3 ,
const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
const void * V_8 , const void T_1 * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 . V_13 ;
unsigned long T_1 * V_14 ;
const unsigned long * V_15 = V_8 ;
const unsigned long T_1 * V_16 = V_9 ;
unsigned long V_17 ;
if ( V_3 == V_18 )
F_3 () ;
V_6 /= sizeof( V_17 ) ;
V_7 /= sizeof( V_17 ) ;
if ( V_8 ) {
for (; V_7 > 0 && V_6 < 16 ; V_7 -- )
V_11 -> V_19 [ V_6 ++ ] = * V_15 ++ ;
V_14 = ( unsigned long T_1 * ) V_11 -> V_19 [ V_20 ] ;
V_14 -= 16 ;
for (; V_7 > 0 && V_6 < 32 ; V_7 -- ) {
if ( F_5 ( * V_15 ++ , & V_14 [ V_6 ++ ] ) )
return - V_21 ;
}
} else {
for (; V_7 > 0 && V_6 < 16 ; V_7 -- ) {
if ( F_4 ( V_17 , V_16 ++ ) )
return - V_21 ;
V_11 -> V_19 [ V_6 ++ ] = V_17 ;
}
V_14 = ( unsigned long T_1 * ) V_11 -> V_19 [ V_20 ] ;
V_14 -= 16 ;
for (; V_7 > 0 && V_6 < 32 ; V_7 -- ) {
if ( F_4 ( V_17 , V_16 ++ ) ||
F_5 ( V_17 , & V_14 [ V_6 ++ ] ) )
return - V_21 ;
}
}
while ( V_7 > 0 ) {
unsigned long V_22 ;
if ( V_8 )
V_17 = * V_15 ++ ;
else if ( F_4 ( V_17 , V_16 ++ ) )
return - V_21 ;
switch ( V_6 ) {
case 32 :
V_22 = V_11 -> V_22 ;
V_22 &= ~ ( V_27 | V_28 ) ;
V_22 |= ( V_17 & ( V_27 | V_28 ) ) ;
V_11 -> V_22 = V_22 ;
break;
case 33 :
V_11 -> V_23 = V_17 ;
break;
case 34 :
V_11 -> V_24 = V_17 ;
break;
case 35 :
V_11 -> V_25 = V_17 ;
break;
case 36 :
case 37 :
break;
default:
goto V_26;
}
V_6 ++ ;
V_7 -- ;
}
V_26:
V_6 *= sizeof( V_17 ) ;
V_7 *= sizeof( V_17 ) ;
return F_8 ( & V_6 , & V_7 , & V_8 , & V_9 ,
38 * sizeof( V_17 ) , - 1 ) ;
}
static int F_9 ( struct V_1 * V_3 ,
const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
void * V_8 , void T_1 * V_9 )
{
const unsigned long * V_29 = V_3 -> V_12 . V_30 ;
int V_31 = 0 ;
#if 0
if (target == current)
save_and_clear_fpu();
#endif
V_31 = F_10 ( & V_6 , & V_7 , & V_8 , & V_9 ,
V_29 ,
0 , 32 * sizeof( V_32 ) ) ;
if ( ! V_31 )
V_31 = F_6 ( & V_6 , & V_7 , & V_8 , & V_9 ,
32 * sizeof( V_32 ) ,
33 * sizeof( V_32 ) ) ;
if ( ! V_31 )
V_31 = F_10 ( & V_6 , & V_7 , & V_8 , & V_9 ,
& V_3 -> V_12 . V_33 ,
33 * sizeof( V_32 ) ,
34 * sizeof( V_32 ) ) ;
if ( ! V_31 ) {
unsigned long V_34 ;
V_34 = ( 1 << 8 ) | ( 8 << 16 ) ;
V_31 = F_10 ( & V_6 , & V_7 , & V_8 , & V_9 ,
& V_34 ,
34 * sizeof( V_32 ) ,
35 * sizeof( V_32 ) ) ;
}
if ( ! V_31 )
V_31 = F_6 ( & V_6 , & V_7 , & V_8 , & V_9 ,
35 * sizeof( V_32 ) , - 1 ) ;
return V_31 ;
}
static int F_11 ( struct V_1 * V_3 ,
const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
const void * V_8 , const void T_1 * V_9 )
{
unsigned long * V_29 = V_3 -> V_12 . V_30 ;
int V_31 ;
#if 0
if (target == current)
save_and_clear_fpu();
#endif
V_31 = F_12 ( & V_6 , & V_7 , & V_8 , & V_9 ,
V_29 ,
0 , 32 * sizeof( V_32 ) ) ;
if ( ! V_31 )
F_8 ( & V_6 , & V_7 , & V_8 , & V_9 ,
32 * sizeof( V_32 ) ,
33 * sizeof( V_32 ) ) ;
if ( ! V_31 && V_7 > 0 ) {
V_31 = F_12 ( & V_6 , & V_7 , & V_8 , & V_9 ,
& V_3 -> V_12 . V_33 ,
33 * sizeof( V_32 ) ,
34 * sizeof( V_32 ) ) ;
}
if ( ! V_31 )
V_31 = F_8 ( & V_6 , & V_7 , & V_8 , & V_9 ,
34 * sizeof( V_32 ) , - 1 ) ;
return V_31 ;
}
const struct V_35 * F_13 ( struct V_1 * V_36 )
{
return & V_37 ;
}
long F_14 ( struct V_1 * V_2 , long V_38 ,
unsigned long V_39 , unsigned long V_40 )
{
unsigned long V_41 = V_18 -> V_12 . V_13 -> V_19 [ V_42 ] ;
void T_1 * V_43 ;
const struct V_35 * V_44 ;
struct V_10 T_1 * V_45 ;
struct V_46 T_1 * V_46 ;
int V_31 ;
V_44 = F_13 ( V_18 ) ;
V_43 = ( void T_1 * ) V_41 ;
V_45 = (struct V_10 T_1 * ) V_39 ;
V_46 = (struct V_46 T_1 * ) V_39 ;
switch( V_38 ) {
case V_47 : {
V_31 = F_15 ( V_2 , V_44 , V_48 ,
32 * sizeof( V_32 ) ,
4 * sizeof( V_32 ) ,
& V_45 -> V_22 ) ;
if ( ! V_31 )
F_15 ( V_2 , V_44 , V_48 ,
1 * sizeof( V_32 ) ,
15 * sizeof( V_32 ) ,
& V_45 -> V_19 [ 0 ] ) ;
break;
}
case V_49 : {
V_31 = F_16 ( V_2 , V_44 , V_48 ,
32 * sizeof( V_32 ) ,
4 * sizeof( V_32 ) ,
& V_45 -> V_22 ) ;
if ( ! V_31 )
F_16 ( V_2 , V_44 , V_48 ,
1 * sizeof( V_32 ) ,
15 * sizeof( V_32 ) ,
& V_45 -> V_19 [ 0 ] ) ;
break;
}
case V_50 : {
V_31 = F_15 ( V_2 , V_44 , V_51 ,
0 * sizeof( V_32 ) ,
32 * sizeof( V_32 ) ,
& V_46 -> V_11 [ 0 ] ) ;
if ( ! V_31 )
V_31 = F_15 ( V_2 , V_44 , V_51 ,
33 * sizeof( V_32 ) ,
1 * sizeof( V_32 ) ,
& V_46 -> V_33 ) ;
if ( ! V_31 ) {
if ( F_17 ( 0 , & V_46 -> V_52 ) ||
F_17 ( 0 , & V_46 -> V_53 ) ||
F_17 ( 0 , & V_46 -> V_54 ) ||
F_18 ( V_46 -> V_55 , sizeof( V_46 -> V_55 ) ) )
V_31 = - V_21 ;
}
break;
}
case V_56 : {
V_31 = F_16 ( V_2 , V_44 , V_51 ,
0 * sizeof( V_32 ) ,
32 * sizeof( V_32 ) ,
& V_46 -> V_11 [ 0 ] ) ;
if ( ! V_31 )
V_31 = F_16 ( V_2 , V_44 , V_51 ,
33 * sizeof( V_32 ) ,
1 * sizeof( V_32 ) ,
& V_46 -> V_33 ) ;
break;
}
case V_57 :
case V_58 :
V_31 = F_19 ( V_2 , V_39 , V_43 , V_40 ) ;
if ( V_31 == V_40 )
V_31 = 0 ;
else if ( V_31 >= 0 )
V_31 = - V_59 ;
break;
case V_60 :
case V_61 :
V_31 = F_20 ( V_2 , V_43 , V_39 , V_40 ) ;
if ( V_31 == V_40 )
V_31 = 0 ;
else if ( V_31 >= 0 )
V_31 = - V_59 ;
break;
default:
if ( V_38 == V_62 )
V_38 = V_63 ;
V_31 = F_21 ( V_2 , V_38 , V_39 , V_40 ) ;
break;
}
return V_31 ;
}
T_2 int F_22 ( struct V_10 * V_11 , int V_64 )
{
int V_31 = 0 ;
if ( F_23 ( V_65 ) ) {
if ( V_64 )
F_24 ( V_11 , 0 ) ;
else
V_31 = F_25 ( V_11 ) ;
}
return V_31 ;
}
