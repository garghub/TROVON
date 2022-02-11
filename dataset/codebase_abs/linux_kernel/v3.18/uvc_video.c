static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 , int V_6 )
{
V_5 [ 0 ] = 2 ;
V_5 [ 1 ] = V_7 | V_2 -> V_8 ;
if ( V_4 -> V_9 - V_2 -> V_10 . V_11 <= V_6 - 2 )
V_5 [ 1 ] |= V_12 ;
return 2 ;
}
static int
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 , int V_6 )
{
struct V_13 * V_10 = & V_2 -> V_10 ;
unsigned int V_14 ;
void * V_15 ;
V_15 = V_4 -> V_15 + V_10 -> V_11 ;
V_14 = F_3 ( ( unsigned int ) V_6 , V_4 -> V_9 - V_10 -> V_11 ) ;
memcpy ( V_5 , V_15 , V_14 ) ;
V_10 -> V_11 += V_14 ;
return V_14 ;
}
static void
F_4 ( struct V_16 * V_17 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void * V_15 = V_17 -> V_4 ;
int V_6 = V_2 -> V_18 ;
int V_19 ;
if ( V_2 -> V_20 == 0 ) {
V_19 = F_1 ( V_2 , V_4 , V_15 , V_6 ) ;
V_2 -> V_20 += V_19 ;
V_15 += V_19 ;
V_6 -= V_19 ;
}
V_6 = F_3 ( ( int ) ( V_2 -> V_21 - V_2 -> V_20 ) , V_6 ) ;
V_19 = F_2 ( V_2 , V_4 , V_15 , V_6 ) ;
V_2 -> V_20 += V_19 ;
V_6 -= V_19 ;
V_17 -> V_22 = V_2 -> V_18 - V_6 ;
V_17 -> V_23 = V_2 -> V_20 == V_2 -> V_21 ;
if ( V_4 -> V_9 == V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . V_11 = 0 ;
V_4 -> V_24 = V_25 ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
V_2 -> V_8 ^= V_26 ;
V_2 -> V_20 = 0 ;
}
if ( V_2 -> V_20 == V_2 -> V_21 ||
V_4 -> V_9 == V_2 -> V_10 . V_11 )
V_2 -> V_20 = 0 ;
}
static void
F_6 ( struct V_16 * V_17 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void * V_15 = V_17 -> V_4 ;
int V_6 = V_2 -> V_18 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_4 , V_15 , V_6 ) ;
V_15 += V_19 ;
V_6 -= V_19 ;
V_19 = F_2 ( V_2 , V_4 , V_15 , V_6 ) ;
V_6 -= V_19 ;
V_17 -> V_22 = V_2 -> V_18 - V_6 ;
if ( V_4 -> V_9 == V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . V_11 = 0 ;
V_4 -> V_24 = V_25 ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
V_2 -> V_8 ^= V_26 ;
}
}
static void
F_7 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_29 ;
struct V_13 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
unsigned long V_30 ;
int V_19 ;
switch ( V_17 -> V_31 ) {
case 0 :
break;
case - V_32 :
F_8 ( V_33 L_1 ) ;
F_9 ( V_10 , 1 ) ;
goto V_34;
default:
F_8 ( V_35 L_2 ,
V_17 -> V_31 ) ;
F_9 ( V_10 , 0 ) ;
goto V_34;
}
F_10 ( & V_2 -> V_10 . V_36 , V_30 ) ;
V_4 = F_11 ( & V_2 -> V_10 ) ;
if ( V_4 == NULL ) {
F_12 ( & V_2 -> V_10 . V_36 , V_30 ) ;
goto V_34;
}
V_2 -> V_37 ( V_17 , V_2 , V_4 ) ;
if ( ( V_19 = F_13 ( V_28 , V_17 , V_38 ) ) < 0 ) {
F_8 ( V_35 L_3 , V_19 ) ;
F_14 ( V_28 ) ;
F_12 ( & V_2 -> V_10 . V_36 , V_30 ) ;
F_9 ( V_10 , 0 ) ;
goto V_34;
}
F_12 ( & V_2 -> V_10 . V_36 , V_30 ) ;
return;
V_34:
F_10 ( & V_2 -> V_39 , V_30 ) ;
F_15 ( & V_17 -> V_40 , & V_2 -> V_41 ) ;
F_12 ( & V_2 -> V_39 , V_30 ) ;
}
static int
F_16 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
if ( V_2 -> V_17 [ V_42 ] ) {
F_17 ( V_2 -> V_28 , V_2 -> V_17 [ V_42 ] ) ;
V_2 -> V_17 [ V_42 ] = NULL ;
}
if ( V_2 -> V_44 [ V_42 ] ) {
F_18 ( V_2 -> V_44 [ V_42 ] ) ;
V_2 -> V_44 [ V_42 ] = NULL ;
}
}
F_19 ( & V_2 -> V_41 ) ;
V_2 -> V_18 = 0 ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 )
{
unsigned int V_18 ;
unsigned int V_42 ;
int V_19 = - V_45 ;
F_21 ( V_2 -> V_18 ) ;
V_18 = V_2 -> V_28 -> V_46
* F_22 (unsigned int, video->ep->maxburst, 1 )
* ( V_2 -> V_28 -> V_47 + 1 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
V_2 -> V_44 [ V_42 ] = F_23 ( V_18 , V_48 ) ;
if ( V_2 -> V_44 [ V_42 ] == NULL )
goto error;
V_2 -> V_17 [ V_42 ] = F_24 ( V_2 -> V_28 , V_48 ) ;
if ( V_2 -> V_17 [ V_42 ] == NULL )
goto error;
V_2 -> V_17 [ V_42 ] -> V_4 = V_2 -> V_44 [ V_42 ] ;
V_2 -> V_17 [ V_42 ] -> V_22 = 0 ;
V_2 -> V_17 [ V_42 ] -> V_49 = F_7 ;
V_2 -> V_17 [ V_42 ] -> V_29 = V_2 ;
F_15 ( & V_2 -> V_17 [ V_42 ] -> V_40 , & V_2 -> V_41 ) ;
}
V_2 -> V_18 = V_18 ;
return 0 ;
error:
F_16 ( V_2 ) ;
return V_19 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_13 * V_10 = & V_2 -> V_10 ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
unsigned long V_30 ;
int V_19 ;
while ( 1 ) {
F_10 ( & V_2 -> V_39 , V_30 ) ;
if ( F_26 ( & V_2 -> V_41 ) ) {
F_12 ( & V_2 -> V_39 , V_30 ) ;
return 0 ;
}
V_17 = F_27 ( & V_2 -> V_41 , struct V_16 ,
V_40 ) ;
F_28 ( & V_17 -> V_40 ) ;
F_12 ( & V_2 -> V_39 , V_30 ) ;
F_10 ( & V_10 -> V_36 , V_30 ) ;
V_4 = F_11 ( V_10 ) ;
if ( V_4 == NULL ) {
F_12 ( & V_10 -> V_36 , V_30 ) ;
break;
}
V_2 -> V_37 ( V_17 , V_2 , V_4 ) ;
V_19 = F_13 ( V_2 -> V_28 , V_17 , V_38 ) ;
if ( V_19 < 0 ) {
F_8 ( V_35 L_4 , V_19 ) ;
F_14 ( V_2 -> V_28 ) ;
F_12 ( & V_10 -> V_36 , V_30 ) ;
F_9 ( V_10 , 0 ) ;
break;
}
F_12 ( & V_10 -> V_36 , V_30 ) ;
}
F_10 ( & V_2 -> V_39 , V_30 ) ;
F_15 ( & V_17 -> V_40 , & V_2 -> V_41 ) ;
F_12 ( & V_2 -> V_39 , V_30 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , int V_50 )
{
unsigned int V_42 ;
int V_19 ;
if ( V_2 -> V_28 == NULL ) {
F_8 ( V_35 L_5
L_6 ) ;
return - V_51 ;
}
if ( ! V_50 ) {
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 )
if ( V_2 -> V_17 [ V_42 ] )
F_30 ( V_2 -> V_28 , V_2 -> V_17 [ V_42 ] ) ;
F_16 ( V_2 ) ;
F_31 ( & V_2 -> V_10 , 0 ) ;
return 0 ;
}
if ( ( V_19 = F_31 ( & V_2 -> V_10 , 1 ) ) < 0 )
return V_19 ;
if ( ( V_19 = F_20 ( V_2 ) ) < 0 )
return V_19 ;
if ( V_2 -> V_21 ) {
V_2 -> V_37 = F_4 ;
V_2 -> V_20 = 0 ;
} else
V_2 -> V_37 = F_6 ;
return F_25 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_41 ) ;
F_33 ( & V_2 -> V_39 ) ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = 16 ;
V_2 -> V_55 = 320 ;
V_2 -> V_56 = 240 ;
V_2 -> V_57 = 320 * 240 * 2 ;
F_34 ( & V_2 -> V_10 , V_58 ) ;
return 0 ;
}
