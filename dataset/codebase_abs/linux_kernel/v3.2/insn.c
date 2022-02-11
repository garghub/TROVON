void F_1 ( struct V_1 * V_1 , const void * V_2 , int V_3 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_2 = V_2 ;
V_1 -> V_4 = V_2 ;
V_1 -> V_3 = V_3 ? 1 : 0 ;
V_1 -> V_5 = 4 ;
if ( V_3 )
V_1 -> V_6 = 8 ;
else
V_1 -> V_6 = 4 ;
}
void F_2 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = & V_1 -> V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
int V_12 , V_13 ;
if ( V_8 -> V_14 )
return;
V_13 = 0 ;
V_11 = 0 ;
V_10 = F_3 ( T_2 , V_1 ) ;
V_9 = F_4 ( V_10 ) ;
while ( F_5 ( V_9 ) ) {
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_8 -> V_15 [ V_12 ] == V_10 )
goto V_16;
if ( V_13 == 4 )
break;
V_8 -> V_15 [ V_13 ++ ] = V_10 ;
if ( F_6 ( V_9 ) ) {
if ( V_1 -> V_3 )
V_1 -> V_6 ^= 12 ;
else
V_1 -> V_6 ^= 6 ;
} else if ( F_7 ( V_9 ) ) {
V_1 -> V_5 ^= 6 ;
}
V_16:
V_8 -> V_17 ++ ;
V_1 -> V_4 ++ ;
V_11 = V_10 ;
V_10 = F_3 ( T_2 , V_1 ) ;
V_9 = F_4 ( V_10 ) ;
}
if ( V_11 && V_11 != V_1 -> V_8 . V_15 [ 3 ] ) {
if ( F_8 ( V_1 -> V_8 . V_15 [ 3 ] ) ) {
V_10 = V_1 -> V_8 . V_15 [ 3 ] ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_8 -> V_15 [ V_12 ] == V_11 )
V_8 -> V_15 [ V_12 ] = V_10 ;
}
V_1 -> V_8 . V_15 [ 3 ] = V_11 ;
}
if ( V_1 -> V_3 ) {
V_10 = F_3 ( T_2 , V_1 ) ;
V_9 = F_4 ( V_10 ) ;
if ( F_9 ( V_9 ) ) {
V_1 -> V_18 . V_19 = V_10 ;
V_1 -> V_18 . V_17 = 1 ;
V_1 -> V_4 ++ ;
if ( F_10 ( V_10 ) )
V_1 -> V_5 = 8 ;
}
}
V_1 -> V_18 . V_14 = 1 ;
V_10 = F_3 ( T_2 , V_1 ) ;
V_9 = F_4 ( V_10 ) ;
if ( F_11 ( V_9 ) ) {
T_2 V_20 = F_12 ( T_2 , V_1 , 1 ) ;
if ( ! V_1 -> V_3 ) {
if ( F_13 ( V_20 ) != 3 )
goto V_21;
}
V_1 -> V_22 . V_15 [ 0 ] = V_10 ;
V_1 -> V_22 . V_15 [ 1 ] = V_20 ;
if ( F_14 ( V_9 ) ) {
V_20 = F_12 ( T_2 , V_1 , 2 ) ;
V_1 -> V_22 . V_15 [ 2 ] = V_20 ;
V_1 -> V_22 . V_17 = 3 ;
V_1 -> V_4 += 3 ;
if ( V_1 -> V_3 && F_15 ( V_20 ) )
V_1 -> V_5 = 8 ;
} else {
V_1 -> V_22 . V_17 = 2 ;
V_1 -> V_4 += 2 ;
}
}
V_21:
V_1 -> V_22 . V_14 = 1 ;
V_8 -> V_14 = 1 ;
V_23:
return;
}
void F_16 ( struct V_1 * V_1 )
{
struct V_7 * V_24 = & V_1 -> V_24 ;
T_2 V_25 , V_26 ;
if ( V_24 -> V_14 )
return;
if ( ! V_1 -> V_8 . V_14 )
F_2 ( V_1 ) ;
V_25 = F_17 ( T_2 , V_1 ) ;
V_24 -> V_15 [ 0 ] = V_25 ;
V_24 -> V_17 = 1 ;
if ( F_18 ( V_1 ) ) {
T_2 V_27 , V_28 ;
V_27 = F_19 ( V_1 ) ;
V_28 = F_20 ( V_1 ) ;
V_1 -> V_9 = F_21 ( V_25 , V_27 , V_28 ) ;
if ( ! F_22 ( V_1 -> V_9 ) )
V_1 -> V_9 = 0 ;
goto V_29;
}
V_1 -> V_9 = F_4 ( V_25 ) ;
while ( F_23 ( V_1 -> V_9 ) ) {
V_25 = F_17 ( T_2 , V_1 ) ;
V_24 -> V_15 [ V_24 -> V_17 ++ ] = V_25 ;
V_26 = F_24 ( V_1 ) ;
V_1 -> V_9 = F_25 ( V_25 , V_26 , V_1 -> V_9 ) ;
}
if ( F_26 ( V_1 -> V_9 ) )
V_1 -> V_9 = 0 ;
V_29:
V_24 -> V_14 = 1 ;
V_23:
return;
}
void F_27 ( struct V_1 * V_1 )
{
struct V_7 * V_30 = & V_1 -> V_30 ;
T_2 V_26 , V_31 ;
if ( V_30 -> V_14 )
return;
if ( ! V_1 -> V_24 . V_14 )
F_16 ( V_1 ) ;
if ( F_28 ( V_1 -> V_9 ) ) {
V_31 = F_17 ( T_2 , V_1 ) ;
V_30 -> V_19 = V_31 ;
V_30 -> V_17 = 1 ;
if ( F_29 ( V_1 -> V_9 ) ) {
V_26 = F_24 ( V_1 ) ;
V_1 -> V_9 = F_30 ( V_31 , V_26 ,
V_1 -> V_9 ) ;
}
}
if ( V_1 -> V_3 && F_31 ( V_1 -> V_9 ) )
V_1 -> V_5 = 8 ;
V_30 -> V_14 = 1 ;
V_23:
return;
}
int F_32 ( struct V_1 * V_1 )
{
struct V_7 * V_30 = & V_1 -> V_30 ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( ! V_30 -> V_14 )
F_27 ( V_1 ) ;
return ( V_30 -> V_17 && ( V_30 -> V_19 & 0xc7 ) == 0x5 ) ;
}
void F_33 ( struct V_1 * V_1 )
{
T_2 V_30 ;
if ( V_1 -> V_32 . V_14 )
return;
if ( ! V_1 -> V_30 . V_14 )
F_27 ( V_1 ) ;
if ( V_1 -> V_30 . V_17 ) {
V_30 = ( T_2 ) V_1 -> V_30 . V_19 ;
if ( V_1 -> V_6 != 2 &&
F_13 ( V_30 ) != 3 && F_34 ( V_30 ) == 4 ) {
V_1 -> V_32 . V_19 = F_17 ( T_2 , V_1 ) ;
V_1 -> V_32 . V_17 = 1 ;
}
}
V_1 -> V_32 . V_14 = 1 ;
V_23:
return;
}
void F_35 ( struct V_1 * V_1 )
{
T_2 V_31 , V_33 , V_34 ;
if ( V_1 -> V_35 . V_14 )
return;
if ( ! V_1 -> V_32 . V_14 )
F_33 ( V_1 ) ;
if ( V_1 -> V_30 . V_17 ) {
V_31 = F_13 ( V_1 -> V_30 . V_19 ) ;
V_33 = F_34 ( V_1 -> V_30 . V_19 ) ;
V_34 = F_36 ( V_1 -> V_32 . V_19 ) ;
if ( V_31 == 3 )
goto V_36;
if ( V_31 == 1 ) {
V_1 -> V_35 . V_19 = F_17 ( char , V_1 ) ;
V_1 -> V_35 . V_17 = 1 ;
} else if ( V_1 -> V_6 == 2 ) {
if ( ( V_31 == 0 && V_33 == 6 ) || V_31 == 2 ) {
V_1 -> V_35 . V_19 =
F_17 ( short , V_1 ) ;
V_1 -> V_35 . V_17 = 2 ;
}
} else {
if ( ( V_31 == 0 && V_33 == 5 ) || V_31 == 2 ||
( V_31 == 0 && V_34 == 5 ) ) {
V_1 -> V_35 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_35 . V_17 = 4 ;
}
}
}
V_36:
V_1 -> V_35 . V_14 = 1 ;
V_23:
return;
}
static void F_37 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_6 ) {
case 2 :
V_1 -> V_37 . V_19 = F_17 ( short , V_1 ) ;
V_1 -> V_37 . V_17 = 2 ;
break;
case 4 :
V_1 -> V_37 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_37 . V_17 = 4 ;
break;
case 8 :
V_1 -> V_37 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_37 . V_17 = 4 ;
V_1 -> V_38 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_38 . V_17 = 4 ;
break;
}
V_1 -> V_37 . V_14 = V_1 -> V_38 . V_14 = 1 ;
V_23:
return;
}
static void F_38 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_5 ) {
case 2 :
V_1 -> V_39 . V_19 = F_17 ( short , V_1 ) ;
V_1 -> V_39 . V_17 = 2 ;
break;
case 4 :
case 8 :
V_1 -> V_39 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_39 . V_17 = 4 ;
break;
}
V_23:
return;
}
static void F_39 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_5 ) {
case 2 :
V_1 -> V_40 . V_19 = F_17 ( short , V_1 ) ;
V_1 -> V_40 . V_17 = 2 ;
break;
case 4 :
V_1 -> V_40 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_17 = 4 ;
break;
case 8 :
V_1 -> V_40 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_17 = 4 ;
V_1 -> V_41 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_41 . V_17 = 4 ;
break;
}
V_1 -> V_40 . V_14 = V_1 -> V_41 . V_14 = 1 ;
V_23:
return;
}
static void F_40 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_5 ) {
case 2 :
V_1 -> V_40 . V_19 = F_17 ( short , V_1 ) ;
V_1 -> V_40 . V_17 = 2 ;
break;
case 4 :
V_1 -> V_40 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_17 = 4 ;
break;
case 8 :
return;
}
V_1 -> V_41 . V_19 = F_17 (unsigned short, insn) ;
V_1 -> V_41 . V_17 = 2 ;
V_1 -> V_40 . V_14 = V_1 -> V_41 . V_14 = 1 ;
V_23:
return;
}
void F_41 ( struct V_1 * V_1 )
{
if ( V_1 -> V_39 . V_14 )
return;
if ( ! V_1 -> V_35 . V_14 )
F_35 ( V_1 ) ;
if ( F_42 ( V_1 -> V_9 ) ) {
F_37 ( V_1 ) ;
goto V_42;
}
if ( ! F_43 ( V_1 -> V_9 ) )
goto V_42;
switch ( F_44 ( V_1 -> V_9 ) ) {
case V_43 :
V_1 -> V_39 . V_19 = F_17 ( char , V_1 ) ;
V_1 -> V_39 . V_17 = 1 ;
break;
case V_44 :
V_1 -> V_39 . V_19 = F_17 ( short , V_1 ) ;
V_1 -> V_39 . V_17 = 2 ;
break;
case V_45 :
V_1 -> V_39 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_39 . V_17 = 4 ;
break;
case V_46 :
V_1 -> V_40 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_40 . V_17 = 4 ;
V_1 -> V_41 . V_19 = F_17 ( int , V_1 ) ;
V_1 -> V_41 . V_17 = 4 ;
break;
case V_47 :
F_40 ( V_1 ) ;
break;
case V_48 :
F_38 ( V_1 ) ;
break;
case V_49 :
F_39 ( V_1 ) ;
break;
default:
break;
}
if ( F_45 ( V_1 -> V_9 ) ) {
V_1 -> V_41 . V_19 = F_17 ( char , V_1 ) ;
V_1 -> V_41 . V_17 = 1 ;
}
V_42:
V_1 -> V_39 . V_14 = 1 ;
V_23:
return;
}
void F_46 ( struct V_1 * V_1 )
{
if ( V_1 -> V_50 )
return;
if ( ! V_1 -> V_39 . V_14 )
F_41 ( V_1 ) ;
V_1 -> V_50 = ( unsigned char ) ( ( unsigned long ) V_1 -> V_4
- ( unsigned long ) V_1 -> V_2 ) ;
}
