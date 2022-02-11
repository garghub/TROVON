static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = F_2 ( V_1 -> V_6 ) ;
int V_7 ;
T_1 * V_8 ;
F_3 ( L_1 ,
V_5 == V_9 ? L_2 : L_3 ,
V_1 -> V_10 , V_1 -> V_11 , V_1 -> V_12 ,
V_1 -> V_13 , V_1 -> V_14 ) ;
switch ( V_1 -> V_10 ) {
case 0 :
case - V_15 :
break;
case - V_16 :
case - V_17 :
case - V_18 :
return;
default:
F_4 ( L_4 , V_1 -> V_10 ) ;
break;
}
V_8 = ( T_1 * ) V_1 -> V_19 ;
switch ( V_5 ) {
case V_9 :
for ( V_7 = 0 ; V_7 < V_1 -> V_13 ; V_7 ++ ) {
if ( V_1 -> V_20 [ V_7 ] . V_10 != 0 )
F_4 ( L_5 , V_1 -> V_20 [ V_7 ] . V_10 ) ;
else if ( V_1 -> V_20 [ V_7 ] . V_11 > 0 )
V_3 -> V_21 ( V_3 , V_8 + V_1 -> V_20 [ V_7 ] . V_22 , V_1 -> V_20 [ V_7 ] . V_11 ) ;
V_1 -> V_20 [ V_7 ] . V_10 = 0 ;
V_1 -> V_20 [ V_7 ] . V_11 = 0 ;
}
F_5 ( V_8 , 20 , F_3 ) ;
break;
case V_23 :
if ( V_1 -> V_11 > 0 )
V_3 -> V_21 ( V_3 , V_8 , V_1 -> V_11 ) ;
break;
default:
F_6 ( L_6 ) ;
return;
}
F_7 ( V_1 , V_24 ) ;
}
int F_8 ( struct V_2 * V_3 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_25 ; V_7 ++ ) {
F_4 ( L_7 , V_7 ) ;
F_9 ( V_3 -> V_26 [ V_7 ] ) ;
}
V_3 -> V_25 = 0 ;
return 0 ;
}
int F_10 ( struct V_2 * V_3 )
{
int V_7 , V_27 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_28 ; V_7 ++ ) {
F_4 ( L_8 , V_7 ) ;
if ( ( V_27 = F_7 ( V_3 -> V_26 [ V_7 ] , V_24 ) ) ) {
F_6 ( L_9 , V_7 ) ;
F_8 ( V_3 ) ;
return V_27 ;
}
V_3 -> V_25 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_30 ) {
while ( V_3 -> V_31 ) {
V_3 -> V_31 -- ;
F_12 ( L_10 , V_3 -> V_31 ) ;
F_13 ( V_3 -> V_32 , V_3 -> V_33 ,
V_3 -> V_34 [ V_3 -> V_31 ] ,
V_3 -> V_35 [ V_3 -> V_31 ] ) ;
}
}
V_3 -> V_29 &= ~ V_30 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , int V_36 , unsigned long V_37 )
{
V_3 -> V_31 = 0 ;
V_3 -> V_33 = V_37 ;
F_12 ( L_11 , V_36 * V_37 ) ;
for ( V_3 -> V_31 = 0 ; V_3 -> V_31 < V_36 ; V_3 -> V_31 ++ ) {
F_12 ( L_12 , V_3 -> V_31 ) ;
if ( ( V_3 -> V_34 [ V_3 -> V_31 ] =
F_15 ( V_3 -> V_32 , V_37 , V_24 ,
& V_3 -> V_35 [ V_3 -> V_31 ] ) ) == NULL ) {
F_12 ( L_13 ) ;
F_11 ( V_3 ) ;
return - V_38 ;
}
F_12 ( L_14 ,
V_3 -> V_31 ,
V_3 -> V_34 [ V_3 -> V_31 ] , ( long long ) V_3 -> V_35 [ V_3 -> V_31 ] ) ;
memset ( V_3 -> V_34 [ V_3 -> V_31 ] , 0 , V_37 ) ;
V_3 -> V_29 |= V_30 ;
}
F_12 ( L_15 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_7 , V_39 ;
if ( ( V_7 = F_14 ( V_3 , V_3 -> V_40 . V_41 ,
V_3 -> V_40 . V_42 . V_43 . V_44 ) ) < 0 )
return V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_40 . V_41 ; V_7 ++ ) {
V_3 -> V_26 [ V_7 ] = F_17 ( 0 , V_24 ) ;
if ( ! V_3 -> V_26 [ V_7 ] ) {
F_12 ( L_16 ) ;
for ( V_39 = 0 ; V_39 < V_7 ; V_39 ++ )
F_18 ( V_3 -> V_26 [ V_39 ] ) ;
return - V_38 ;
}
F_19 ( V_3 -> V_26 [ V_7 ] , V_3 -> V_32 ,
F_20 ( V_3 -> V_32 , V_3 -> V_40 . V_45 ) ,
V_3 -> V_34 [ V_7 ] ,
V_3 -> V_40 . V_42 . V_43 . V_44 ,
F_1 , V_3 ) ;
V_3 -> V_26 [ V_7 ] -> V_46 = V_47 ;
V_3 -> V_26 [ V_7 ] -> V_48 = V_3 -> V_35 [ V_7 ] ;
V_3 -> V_28 ++ ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
int V_7 , V_39 ;
if ( ( V_7 = F_14 ( V_3 , V_3 -> V_40 . V_41 ,
V_3 -> V_40 . V_42 . V_49 . V_50 * V_3 -> V_40 . V_42 . V_49 . V_51 ) ) < 0 )
return V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_40 . V_41 ; V_7 ++ ) {
struct V_1 * V_1 ;
int V_52 = 0 ;
V_3 -> V_26 [ V_7 ] = F_17 ( V_3 -> V_40 . V_42 . V_49 . V_51 , V_24 ) ;
if ( ! V_3 -> V_26 [ V_7 ] ) {
F_12 ( L_17 ) ;
for ( V_39 = 0 ; V_39 < V_7 ; V_39 ++ )
F_18 ( V_3 -> V_26 [ V_39 ] ) ;
return - V_38 ;
}
V_1 = V_3 -> V_26 [ V_7 ] ;
V_1 -> V_53 = V_3 -> V_32 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_21 = F_1 ;
V_1 -> V_6 = F_22 ( V_3 -> V_32 , V_3 -> V_40 . V_45 ) ;
V_1 -> V_46 = V_54 | V_47 ;
V_1 -> V_55 = V_3 -> V_40 . V_42 . V_49 . V_55 ;
V_1 -> V_13 = V_3 -> V_40 . V_42 . V_49 . V_51 ;
V_1 -> V_12 = V_3 -> V_33 ;
V_1 -> V_19 = V_3 -> V_34 [ V_7 ] ;
V_1 -> V_48 = V_3 -> V_35 [ V_7 ] ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 . V_42 . V_49 . V_51 ; V_39 ++ ) {
V_1 -> V_20 [ V_39 ] . V_22 = V_52 ;
V_1 -> V_20 [ V_39 ] . V_56 = V_3 -> V_40 . V_42 . V_49 . V_50 ;
V_52 += V_3 -> V_40 . V_42 . V_49 . V_50 ;
}
V_3 -> V_28 ++ ;
}
return 0 ;
}
int F_23 ( struct V_2 * V_3 , struct V_57 * V_40 )
{
if ( V_3 == NULL || V_40 == NULL )
return - V_58 ;
memcpy ( & V_3 -> V_40 , V_40 , sizeof( * V_40 ) ) ;
F_24 ( V_3 -> V_32 , F_20 ( V_3 -> V_32 , V_3 -> V_40 . V_45 ) ) ;
if ( V_3 -> V_21 == NULL ) {
F_6 ( L_18 ) ;
return - V_58 ;
}
switch ( V_3 -> V_40 . type ) {
case V_59 :
return F_16 ( V_3 ) ;
case V_60 :
return F_21 ( V_3 ) ;
default:
F_6 ( L_19 ) ;
return - V_58 ;
}
}
int F_25 ( struct V_2 * V_3 )
{
int V_7 ;
F_8 ( V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_28 ; V_7 ++ ) {
if ( V_3 -> V_26 [ V_7 ] != NULL ) {
F_12 ( L_20 , V_7 ) ;
F_18 ( V_3 -> V_26 [ V_7 ] ) ;
}
}
V_3 -> V_28 = 0 ;
F_11 ( V_3 ) ;
return 0 ;
}
