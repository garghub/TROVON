static int F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
T_1 V_5 [ 3 ] ;
F_2 ( & V_2 -> V_6 ,
L_1 ,
V_2 , ( unsigned int ) V_3 , V_4 ) ;
if ( ! V_4 )
return - V_7 ;
F_3 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 , L_2 ) ;
if ( F_4 ( V_2 ) ) {
F_5 ( & V_2 -> V_8 -> V_9 ) ;
return - V_10 ;
}
V_5 [ 0 ] = V_11 ;
V_5 [ 1 ] = V_3 ;
V_5 [ 2 ] = 0 ;
F_6 ( V_2 -> V_8 , V_5 , 3 ) ;
* V_4 = F_7 ( V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 , L_3 ) ;
return 1 ;
}
static T_2 F_8 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
F_2 ( & F_9 ( V_15 ) -> V_6 ,
L_4 ,
V_17 -> V_20 . V_21 , V_15 , ( unsigned int ) V_18 , V_19 , V_4 ) ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) , V_23 , V_4 ) ;
}
static T_2 F_10 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
F_2 ( & F_9 ( V_15 ) -> V_6 ,
L_4 ,
V_17 -> V_20 . V_21 , V_15 , ( unsigned int ) V_18 , V_19 , V_4 ) ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) ,
V_24 , V_4 ) ;
}
static T_2 F_11 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
F_2 ( & F_9 ( V_15 ) -> V_6 ,
L_4 ,
V_17 -> V_20 . V_21 , V_15 , ( unsigned int ) V_18 , V_19 , V_4 ) ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) ,
V_25 , V_4 ) ;
}
static T_2 F_12 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
F_2 ( & F_9 ( V_15 ) -> V_6 ,
L_4 ,
V_17 -> V_20 . V_21 , V_15 , ( unsigned int ) V_18 , V_19 , V_4 ) ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) ,
V_26 , V_4 ) ;
}
static T_2 F_13 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) ,
V_27 , V_4 ) ;
}
static T_2 F_14 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
return F_1 ( F_9 ( V_15 ) ,
V_28 , V_4 ) ;
}
static T_2 F_15 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
T_1 V_29 [ 3 ] ;
T_1 V_30 ;
unsigned int V_31 = V_32 ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
F_2 ( & V_2 -> V_6 , L_5 ) ;
F_3 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 , L_2 ) ;
if ( F_4 ( V_2 ) )
goto error;
while ( V_31 -- ) {
V_29 [ 0 ] = V_33 ;
V_29 [ 1 ] = * V_4 ;
V_29 [ 2 ] = ~ ( * V_4 ) ;
F_6 ( V_2 -> V_8 , V_29 , 3 ) ;
V_30 = F_7 ( V_2 -> V_8 ) ;
if ( F_16 ( V_2 -> V_8 ) )
goto error;
if ( V_30 != 0xAA ) {
continue;
}
V_29 [ 0 ] = V_11 ;
V_29 [ 1 ] = V_24 ;
V_29 [ 2 ] = 0 ;
F_6 ( V_2 -> V_8 , V_29 , 3 ) ;
if ( F_7 ( V_2 -> V_8 ) == * V_4 ) {
F_5 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 ,
L_6 , V_31 ) ;
return 1 ;
}
}
error:
F_5 ( & V_2 -> V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 , L_7 , V_31 ) ;
return - V_10 ;
}
static T_2 F_17 (
struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 , T_3 V_18 , T_4 V_19 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
unsigned int V_31 = V_32 ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
F_3 ( & V_2 -> V_8 -> V_9 ) ;
if ( F_4 ( V_2 ) )
goto error;
while ( V_31 -- ) {
F_18 ( V_2 -> V_8 , V_34 ) ;
if ( F_7 ( V_2 -> V_8 ) == V_35 ) {
F_5 ( & V_2 -> V_8 -> V_9 ) ;
return 1 ;
}
if ( F_16 ( V_2 -> V_8 ) )
goto error;
}
error:
F_5 ( & V_2 -> V_8 -> V_9 ) ;
return - V_10 ;
}
static T_2 F_19 (
struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_4 ,
T_3 V_18 ,
T_4 V_19 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
T_1 V_29 [ 4 ] ;
unsigned int V_31 = V_32 ;
if ( V_19 != 1 || V_18 != 0 )
return - V_22 ;
F_3 ( & V_2 -> V_8 -> V_9 ) ;
if ( F_4 ( V_2 ) )
goto error;
while ( V_31 -- ) {
V_29 [ 0 ] = V_36 ;
V_29 [ 1 ] = V_28 ;
V_29 [ 2 ] = 0 ;
V_29 [ 3 ] = * V_4 ;
F_6 ( V_2 -> V_8 , V_29 , 4 ) ;
if ( F_16 ( V_2 -> V_8 ) )
goto error;
V_29 [ 0 ] = V_11 ;
V_29 [ 1 ] = V_28 ;
V_29 [ 2 ] = 0 ;
F_6 ( V_2 -> V_8 , V_29 , 3 ) ;
if ( F_7 ( V_2 -> V_8 ) == * V_4 ) {
F_5 ( & V_2 -> V_8 -> V_9 ) ;
return 1 ;
}
}
error:
F_5 ( & V_2 -> V_8 -> V_9 ) ;
return - V_10 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 && ! V_37 ; ++ V_38 )
V_37 = F_21 (
& V_2 -> V_6 . V_15 ,
& ( V_40 [ V_38 ] ) ) ;
if ( V_37 )
while ( -- V_38 >= 0 )
F_22 ( & V_2 -> V_6 . V_15 ,
& ( V_40 [ V_38 ] ) ) ;
return V_37 ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = V_39 ; V_38 <= 0 ; -- V_38 )
F_22 ( & V_2 -> V_6 . V_15 ,
& ( V_40 [ V_38 ] ) ) ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_41 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_41 ) ;
}
