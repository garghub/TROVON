static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 , int V_6 )
{
V_5 [ 0 ] = 2 ;
V_5 [ 1 ] = V_7 | V_2 -> V_8 ;
if ( V_4 -> V_4 . V_9 - V_2 -> V_10 . V_11 <= V_6 - 2 )
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
V_15 = V_10 -> V_15 + V_4 -> V_4 . V_16 . V_17 + V_10 -> V_11 ;
V_14 = F_3 ( ( unsigned int ) V_6 , V_4 -> V_4 . V_9 - V_10 -> V_11 ) ;
memcpy ( V_5 , V_15 , V_14 ) ;
V_10 -> V_11 += V_14 ;
return V_14 ;
}
static void
F_4 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void * V_15 = V_19 -> V_4 ;
int V_6 = V_2 -> V_20 ;
int V_21 ;
if ( V_2 -> V_22 == 0 ) {
V_21 = F_1 ( V_2 , V_4 , V_15 , V_6 ) ;
V_2 -> V_22 += V_21 ;
V_15 += V_21 ;
V_6 -= V_21 ;
}
V_6 = F_3 ( ( int ) ( V_2 -> V_23 - V_2 -> V_22 ) , V_6 ) ;
V_21 = F_2 ( V_2 , V_4 , V_15 , V_6 ) ;
V_2 -> V_22 += V_21 ;
V_6 -= V_21 ;
V_19 -> V_24 = V_2 -> V_20 - V_6 ;
V_19 -> V_25 = V_2 -> V_22 == V_2 -> V_23 ;
if ( V_4 -> V_4 . V_9 == V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . V_11 = 0 ;
V_4 -> V_26 = V_27 ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
V_2 -> V_8 ^= V_28 ;
V_2 -> V_22 = 0 ;
}
if ( V_2 -> V_22 == V_2 -> V_23 ||
V_4 -> V_4 . V_9 == V_2 -> V_10 . V_11 )
V_2 -> V_22 = 0 ;
}
static void
F_6 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void * V_15 = V_19 -> V_4 ;
int V_6 = V_2 -> V_20 ;
int V_21 ;
V_21 = F_1 ( V_2 , V_4 , V_15 , V_6 ) ;
V_15 += V_21 ;
V_6 -= V_21 ;
V_21 = F_2 ( V_2 , V_4 , V_15 , V_6 ) ;
V_6 -= V_21 ;
V_19 -> V_24 = V_2 -> V_20 - V_6 ;
if ( V_4 -> V_4 . V_9 == V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . V_11 = 0 ;
V_4 -> V_26 = V_27 ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
V_2 -> V_8 ^= V_28 ;
}
}
static void
F_7 ( struct V_29 * V_30 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_31 ;
struct V_3 * V_4 ;
unsigned long V_32 ;
int V_21 ;
switch ( V_19 -> V_33 ) {
case 0 :
break;
case - V_34 :
F_8 ( V_35 L_1 ) ;
goto V_36;
default:
F_8 ( V_35 L_2 ,
V_19 -> V_33 ) ;
goto V_36;
}
F_9 ( & V_2 -> V_10 . V_37 , V_32 ) ;
V_4 = F_10 ( & V_2 -> V_10 ) ;
if ( V_4 == NULL ) {
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
goto V_36;
}
V_2 -> V_38 ( V_19 , V_2 , V_4 ) ;
if ( ( V_21 = F_12 ( V_30 , V_19 , V_39 ) ) < 0 ) {
F_8 ( V_35 L_3 , V_21 ) ;
F_13 ( V_30 ) ;
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
goto V_36;
}
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
return;
V_36:
F_9 ( & V_2 -> V_40 , V_32 ) ;
F_14 ( & V_19 -> V_41 , & V_2 -> V_42 ) ;
F_11 ( & V_2 -> V_40 , V_32 ) ;
}
static int
F_15 ( struct V_1 * V_2 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
if ( V_2 -> V_19 [ V_43 ] ) {
F_16 ( V_2 -> V_30 , V_2 -> V_19 [ V_43 ] ) ;
V_2 -> V_19 [ V_43 ] = NULL ;
}
if ( V_2 -> V_45 [ V_43 ] ) {
F_17 ( V_2 -> V_45 [ V_43 ] ) ;
V_2 -> V_45 [ V_43 ] = NULL ;
}
}
F_18 ( & V_2 -> V_42 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
unsigned int V_43 ;
int V_21 = - V_46 ;
F_20 ( V_2 -> V_20 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
V_2 -> V_45 [ V_43 ] = F_21 ( V_2 -> V_30 -> V_47 , V_48 ) ;
if ( V_2 -> V_45 [ V_43 ] == NULL )
goto error;
V_2 -> V_19 [ V_43 ] = F_22 ( V_2 -> V_30 , V_48 ) ;
if ( V_2 -> V_19 [ V_43 ] == NULL )
goto error;
V_2 -> V_19 [ V_43 ] -> V_4 = V_2 -> V_45 [ V_43 ] ;
V_2 -> V_19 [ V_43 ] -> V_24 = 0 ;
V_2 -> V_19 [ V_43 ] -> V_49 = V_50 ;
V_2 -> V_19 [ V_43 ] -> V_51 = F_7 ;
V_2 -> V_19 [ V_43 ] -> V_31 = V_2 ;
F_14 ( & V_2 -> V_19 [ V_43 ] -> V_41 , & V_2 -> V_42 ) ;
}
V_2 -> V_20 = V_2 -> V_30 -> V_47 ;
return 0 ;
error:
F_15 ( V_2 ) ;
return V_21 ;
}
static int
F_23 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned long V_32 ;
int V_21 ;
while ( 1 ) {
F_9 ( & V_2 -> V_40 , V_32 ) ;
if ( F_24 ( & V_2 -> V_42 ) ) {
F_11 ( & V_2 -> V_40 , V_32 ) ;
return 0 ;
}
V_19 = F_25 ( & V_2 -> V_42 , struct V_18 ,
V_41 ) ;
F_26 ( & V_19 -> V_41 ) ;
F_11 ( & V_2 -> V_40 , V_32 ) ;
F_9 ( & V_2 -> V_10 . V_37 , V_32 ) ;
V_4 = F_10 ( & V_2 -> V_10 ) ;
if ( V_4 == NULL ) {
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
break;
}
V_2 -> V_38 ( V_19 , V_2 , V_4 ) ;
if ( ( V_21 = F_12 ( V_2 -> V_30 , V_19 , V_48 ) ) < 0 ) {
F_8 ( V_35 L_4 , V_21 ) ;
F_13 ( V_2 -> V_30 ) ;
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
break;
}
F_11 ( & V_2 -> V_10 . V_37 , V_32 ) ;
}
F_9 ( & V_2 -> V_40 , V_32 ) ;
F_14 ( & V_19 -> V_41 , & V_2 -> V_42 ) ;
F_11 ( & V_2 -> V_40 , V_32 ) ;
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 , int V_52 )
{
unsigned int V_43 ;
int V_21 ;
if ( V_2 -> V_30 == NULL ) {
F_8 ( V_35 L_5
L_6 ) ;
return - V_53 ;
}
if ( ! V_52 ) {
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 )
F_28 ( V_2 -> V_30 , V_2 -> V_19 [ V_43 ] ) ;
F_15 ( V_2 ) ;
F_29 ( & V_2 -> V_10 , 0 ) ;
return 0 ;
}
if ( ( V_21 = F_29 ( & V_2 -> V_10 , 1 ) ) < 0 )
return V_21 ;
if ( ( V_21 = F_19 ( V_2 ) ) < 0 )
return V_21 ;
if ( V_2 -> V_23 ) {
V_2 -> V_38 = F_4 ;
V_2 -> V_22 = 0 ;
} else
V_2 -> V_38 = F_6 ;
return F_23 ( V_2 ) ;
}
static int
F_30 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_42 ) ;
F_31 ( & V_2 -> V_40 ) ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = 16 ;
V_2 -> V_57 = 320 ;
V_2 -> V_58 = 240 ;
V_2 -> V_59 = 320 * 240 * 2 ;
F_32 ( & V_2 -> V_10 , V_60 ) ;
return 0 ;
}
