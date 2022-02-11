void F_1 ( struct V_1 * V_1 , const void * V_2 , int V_3 , int V_4 )
{
if ( V_3 > V_5 )
V_3 = V_5 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_2 = V_2 ;
V_1 -> V_6 = V_2 + V_3 ;
V_1 -> V_7 = V_2 ;
V_1 -> V_4 = V_4 ? 1 : 0 ;
V_1 -> V_8 = 4 ;
if ( V_4 )
V_1 -> V_9 = 8 ;
else
V_1 -> V_9 = 4 ;
}
void F_2 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = & V_1 -> V_11 ;
T_1 V_12 ;
T_2 V_13 , V_14 ;
int V_15 , V_16 ;
if ( V_11 -> V_17 )
return;
V_16 = 0 ;
V_14 = 0 ;
V_13 = F_3 ( T_2 , V_1 ) ;
V_12 = F_4 ( V_13 ) ;
while ( F_5 ( V_12 ) ) {
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( V_11 -> V_18 [ V_15 ] == V_13 )
goto V_19;
if ( V_16 == 4 )
break;
V_11 -> V_18 [ V_16 ++ ] = V_13 ;
if ( F_6 ( V_12 ) ) {
if ( V_1 -> V_4 )
V_1 -> V_9 ^= 12 ;
else
V_1 -> V_9 ^= 6 ;
} else if ( F_7 ( V_12 ) ) {
V_1 -> V_8 ^= 6 ;
}
V_19:
V_11 -> V_20 ++ ;
V_1 -> V_7 ++ ;
V_14 = V_13 ;
V_13 = F_3 ( T_2 , V_1 ) ;
V_12 = F_4 ( V_13 ) ;
}
if ( V_14 && V_14 != V_1 -> V_11 . V_18 [ 3 ] ) {
if ( F_8 ( V_1 -> V_11 . V_18 [ 3 ] ) ) {
V_13 = V_1 -> V_11 . V_18 [ 3 ] ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( V_11 -> V_18 [ V_15 ] == V_14 )
V_11 -> V_18 [ V_15 ] = V_13 ;
}
V_1 -> V_11 . V_18 [ 3 ] = V_14 ;
}
if ( V_1 -> V_4 ) {
V_13 = F_3 ( T_2 , V_1 ) ;
V_12 = F_4 ( V_13 ) ;
if ( F_9 ( V_12 ) ) {
V_1 -> V_21 . V_22 = V_13 ;
V_1 -> V_21 . V_20 = 1 ;
V_1 -> V_7 ++ ;
if ( F_10 ( V_13 ) )
V_1 -> V_8 = 8 ;
}
}
V_1 -> V_21 . V_17 = 1 ;
V_13 = F_3 ( T_2 , V_1 ) ;
V_12 = F_4 ( V_13 ) ;
if ( F_11 ( V_12 ) ) {
T_2 V_23 = F_12 ( T_2 , V_1 , 1 ) ;
if ( ! V_1 -> V_4 ) {
if ( F_13 ( V_23 ) != 3 )
goto V_24;
}
V_1 -> V_25 . V_18 [ 0 ] = V_13 ;
V_1 -> V_25 . V_18 [ 1 ] = V_23 ;
if ( F_14 ( V_12 ) ) {
V_23 = F_12 ( T_2 , V_1 , 2 ) ;
V_1 -> V_25 . V_18 [ 2 ] = V_23 ;
V_1 -> V_25 . V_20 = 3 ;
V_1 -> V_7 += 3 ;
if ( V_1 -> V_4 && F_15 ( V_23 ) )
V_1 -> V_8 = 8 ;
} else {
V_1 -> V_25 . V_18 [ 2 ] = V_23 & 0x7f ;
V_1 -> V_25 . V_20 = 2 ;
V_1 -> V_7 += 2 ;
}
}
V_24:
V_1 -> V_25 . V_17 = 1 ;
V_11 -> V_17 = 1 ;
V_26:
return;
}
void F_16 ( struct V_1 * V_1 )
{
struct V_10 * V_27 = & V_1 -> V_27 ;
T_2 V_28 ;
int V_29 ;
if ( V_27 -> V_17 )
return;
if ( ! V_1 -> V_11 . V_17 )
F_2 ( V_1 ) ;
V_28 = F_17 ( T_2 , V_1 ) ;
V_27 -> V_18 [ 0 ] = V_28 ;
V_27 -> V_20 = 1 ;
if ( F_18 ( V_1 ) ) {
T_2 V_30 , V_31 ;
V_30 = F_19 ( V_1 ) ;
V_31 = F_20 ( V_1 ) ;
V_1 -> V_12 = F_21 ( V_28 , V_30 , V_31 ) ;
if ( ! F_22 ( V_1 -> V_12 ) && ! F_23 ( V_1 -> V_12 ) )
V_1 -> V_12 = 0 ;
goto V_32;
}
V_1 -> V_12 = F_4 ( V_28 ) ;
while ( F_24 ( V_1 -> V_12 ) ) {
V_28 = F_17 ( T_2 , V_1 ) ;
V_27 -> V_18 [ V_27 -> V_20 ++ ] = V_28 ;
V_29 = F_25 ( V_1 ) ;
V_1 -> V_12 = F_26 ( V_28 , V_29 , V_1 -> V_12 ) ;
}
if ( F_27 ( V_1 -> V_12 ) )
V_1 -> V_12 = 0 ;
V_32:
V_27 -> V_17 = 1 ;
V_26:
return;
}
void F_28 ( struct V_1 * V_1 )
{
struct V_10 * V_33 = & V_1 -> V_33 ;
T_2 V_29 , V_34 ;
if ( V_33 -> V_17 )
return;
if ( ! V_1 -> V_27 . V_17 )
F_16 ( V_1 ) ;
if ( F_29 ( V_1 -> V_12 ) ) {
V_34 = F_17 ( T_2 , V_1 ) ;
V_33 -> V_22 = V_34 ;
V_33 -> V_20 = 1 ;
if ( F_23 ( V_1 -> V_12 ) ) {
V_29 = F_25 ( V_1 ) ;
V_1 -> V_12 = F_30 ( V_34 , V_29 ,
V_1 -> V_12 ) ;
if ( F_18 ( V_1 ) && ! F_22 ( V_1 -> V_12 ) )
V_1 -> V_12 = 0 ;
}
}
if ( V_1 -> V_4 && F_31 ( V_1 -> V_12 ) )
V_1 -> V_8 = 8 ;
V_33 -> V_17 = 1 ;
V_26:
return;
}
int F_32 ( struct V_1 * V_1 )
{
struct V_10 * V_33 = & V_1 -> V_33 ;
if ( ! V_1 -> V_4 )
return 0 ;
if ( ! V_33 -> V_17 )
F_28 ( V_1 ) ;
return ( V_33 -> V_20 && ( V_33 -> V_22 & 0xc7 ) == 0x5 ) ;
}
void F_33 ( struct V_1 * V_1 )
{
T_2 V_33 ;
if ( V_1 -> V_35 . V_17 )
return;
if ( ! V_1 -> V_33 . V_17 )
F_28 ( V_1 ) ;
if ( V_1 -> V_33 . V_20 ) {
V_33 = ( T_2 ) V_1 -> V_33 . V_22 ;
if ( V_1 -> V_9 != 2 &&
F_13 ( V_33 ) != 3 && F_34 ( V_33 ) == 4 ) {
V_1 -> V_35 . V_22 = F_17 ( T_2 , V_1 ) ;
V_1 -> V_35 . V_20 = 1 ;
}
}
V_1 -> V_35 . V_17 = 1 ;
V_26:
return;
}
void F_35 ( struct V_1 * V_1 )
{
T_2 V_34 , V_36 , V_37 ;
if ( V_1 -> V_38 . V_17 )
return;
if ( ! V_1 -> V_35 . V_17 )
F_33 ( V_1 ) ;
if ( V_1 -> V_33 . V_20 ) {
V_34 = F_13 ( V_1 -> V_33 . V_22 ) ;
V_36 = F_34 ( V_1 -> V_33 . V_22 ) ;
V_37 = F_36 ( V_1 -> V_35 . V_22 ) ;
if ( V_34 == 3 )
goto V_39;
if ( V_34 == 1 ) {
V_1 -> V_38 . V_22 = F_17 ( char , V_1 ) ;
V_1 -> V_38 . V_20 = 1 ;
} else if ( V_1 -> V_9 == 2 ) {
if ( ( V_34 == 0 && V_36 == 6 ) || V_34 == 2 ) {
V_1 -> V_38 . V_22 =
F_17 ( short , V_1 ) ;
V_1 -> V_38 . V_20 = 2 ;
}
} else {
if ( ( V_34 == 0 && V_36 == 5 ) || V_34 == 2 ||
( V_34 == 0 && V_37 == 5 ) ) {
V_1 -> V_38 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_38 . V_20 = 4 ;
}
}
}
V_39:
V_1 -> V_38 . V_17 = 1 ;
V_26:
return;
}
static int F_37 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_9 ) {
case 2 :
V_1 -> V_40 . V_22 = F_17 ( short , V_1 ) ;
V_1 -> V_40 . V_20 = 2 ;
break;
case 4 :
V_1 -> V_40 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_20 = 4 ;
break;
case 8 :
V_1 -> V_40 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_20 = 4 ;
V_1 -> V_41 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_41 . V_20 = 4 ;
break;
default:
goto V_26;
}
V_1 -> V_40 . V_17 = V_1 -> V_41 . V_17 = 1 ;
return 1 ;
V_26:
return 0 ;
}
static int F_38 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_8 ) {
case 2 :
V_1 -> V_42 . V_22 = F_17 ( short , V_1 ) ;
V_1 -> V_42 . V_20 = 2 ;
break;
case 4 :
case 8 :
V_1 -> V_42 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_42 . V_20 = 4 ;
break;
default:
goto V_26;
}
return 1 ;
V_26:
return 0 ;
}
static int F_39 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_8 ) {
case 2 :
V_1 -> V_43 . V_22 = F_17 ( short , V_1 ) ;
V_1 -> V_43 . V_20 = 2 ;
break;
case 4 :
V_1 -> V_43 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_43 . V_20 = 4 ;
break;
case 8 :
V_1 -> V_43 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_43 . V_20 = 4 ;
V_1 -> V_44 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_44 . V_20 = 4 ;
break;
default:
goto V_26;
}
V_1 -> V_43 . V_17 = V_1 -> V_44 . V_17 = 1 ;
return 1 ;
V_26:
return 0 ;
}
static int F_40 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_8 ) {
case 2 :
V_1 -> V_43 . V_22 = F_17 ( short , V_1 ) ;
V_1 -> V_43 . V_20 = 2 ;
break;
case 4 :
V_1 -> V_43 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_43 . V_20 = 4 ;
break;
case 8 :
return 0 ;
default:
goto V_26;
}
V_1 -> V_44 . V_22 = F_17 (unsigned short, insn) ;
V_1 -> V_44 . V_20 = 2 ;
V_1 -> V_43 . V_17 = V_1 -> V_44 . V_17 = 1 ;
return 1 ;
V_26:
return 0 ;
}
void F_41 ( struct V_1 * V_1 )
{
if ( V_1 -> V_42 . V_17 )
return;
if ( ! V_1 -> V_38 . V_17 )
F_35 ( V_1 ) ;
if ( F_42 ( V_1 -> V_12 ) ) {
if ( ! F_37 ( V_1 ) )
goto V_26;
goto V_45;
}
if ( ! F_43 ( V_1 -> V_12 ) )
goto V_45;
switch ( F_44 ( V_1 -> V_12 ) ) {
case V_46 :
V_1 -> V_42 . V_22 = F_17 ( char , V_1 ) ;
V_1 -> V_42 . V_20 = 1 ;
break;
case V_47 :
V_1 -> V_42 . V_22 = F_17 ( short , V_1 ) ;
V_1 -> V_42 . V_20 = 2 ;
break;
case V_48 :
V_1 -> V_42 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_42 . V_20 = 4 ;
break;
case V_49 :
V_1 -> V_43 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_43 . V_20 = 4 ;
V_1 -> V_44 . V_22 = F_17 ( int , V_1 ) ;
V_1 -> V_44 . V_20 = 4 ;
break;
case V_50 :
if ( ! F_40 ( V_1 ) )
goto V_26;
break;
case V_51 :
if ( ! F_38 ( V_1 ) )
goto V_26;
break;
case V_52 :
if ( ! F_39 ( V_1 ) )
goto V_26;
break;
default:
goto V_26;
}
if ( F_45 ( V_1 -> V_12 ) ) {
V_1 -> V_44 . V_22 = F_17 ( char , V_1 ) ;
V_1 -> V_44 . V_20 = 1 ;
}
V_45:
V_1 -> V_42 . V_17 = 1 ;
V_26:
return;
}
void F_46 ( struct V_1 * V_1 )
{
if ( V_1 -> V_53 )
return;
if ( ! V_1 -> V_42 . V_17 )
F_41 ( V_1 ) ;
V_1 -> V_53 = ( unsigned char ) ( ( unsigned long ) V_1 -> V_7
- ( unsigned long ) V_1 -> V_2 ) ;
}
