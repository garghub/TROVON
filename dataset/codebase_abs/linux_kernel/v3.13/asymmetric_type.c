static int F_1 ( const struct V_1 * V_1 , const void * V_2 )
{
const struct V_3 * V_4 = V_3 ( V_1 ) ;
const char * V_5 = V_2 ;
const char * V_6 , * V_7 ;
T_1 V_8 ;
T_2 V_9 , V_10 ;
if ( ! V_4 || ! V_5 || ! * V_5 )
return 0 ;
if ( V_1 -> V_2 && strcmp ( V_1 -> V_2 , V_2 ) == 0 )
return 1 ;
V_6 = strchr ( V_5 , ':' ) ;
if ( ! V_6 )
return 0 ;
V_8 = V_6 - V_5 ;
V_6 ++ ;
V_7 = F_2 ( V_1 ) ;
if ( ! V_7 )
return 0 ;
V_9 = strlen ( V_6 ) ;
V_10 = strlen ( V_7 ) ;
if ( V_9 > V_10 )
return 0 ;
V_7 += V_10 - V_9 ;
if ( strcasecmp ( V_6 , V_7 ) != 0 )
return 0 ;
if ( V_8 == 2 &&
memcmp ( V_5 , L_1 , 2 ) == 0 )
return 1 ;
if ( V_8 == V_4 -> V_11 &&
memcmp ( V_5 , V_4 -> V_12 , V_8 ) == 0 )
return 1 ;
return 0 ;
}
static void F_3 ( const struct V_1 * V_1 , struct V_13 * V_14 )
{
const struct V_3 * V_4 = V_3 ( V_1 ) ;
const char * V_7 = F_2 ( V_1 ) ;
T_2 V_15 ;
F_4 ( V_14 , V_1 -> V_2 ) ;
if ( V_4 ) {
F_4 ( V_14 , L_2 ) ;
V_4 -> V_16 ( V_1 , V_14 ) ;
if ( V_7 ) {
F_5 ( V_14 , ' ' ) ;
V_15 = strlen ( V_7 ) ;
if ( V_15 <= 8 )
F_4 ( V_14 , V_7 ) ;
else
F_4 ( V_14 , V_7 + V_15 - 8 ) ;
}
F_4 ( V_14 , L_3 ) ;
F_5 ( V_14 , ']' ) ;
}
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
F_7 ( L_4 , V_22 ) ;
if ( V_18 -> V_23 == 0 )
return - V_24 ;
F_8 ( & V_25 ) ;
V_21 = - V_26 ;
F_9 (parser, &asymmetric_key_parsers, link) {
F_10 ( L_5 , V_20 -> V_12 ) ;
V_21 = V_20 -> V_27 ( V_18 ) ;
if ( V_21 != - V_26 ) {
F_10 ( L_6 ,
V_21 ) ;
break;
}
}
F_11 ( & V_25 ) ;
F_7 ( L_7 , V_22 , V_21 ) ;
return V_21 ;
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_28 [ 0 ] ;
F_7 ( L_4 , V_22 ) ;
if ( V_4 ) {
V_4 -> V_29 ( V_18 -> V_30 ) ;
F_13 ( V_4 -> V_31 ) ;
}
F_14 ( V_18 -> V_28 [ 1 ] ) ;
F_14 ( V_18 -> V_2 ) ;
}
static int F_15 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
int V_21 ;
F_7 ( L_4 , V_22 ) ;
V_21 = F_16 ( V_1 , V_18 -> V_32 ) ;
if ( V_21 == 0 ) {
V_1 -> V_28 . V_33 [ 0 ] = V_18 -> V_28 [ 0 ] ;
V_1 -> V_28 . V_33 [ 1 ] = V_18 -> V_28 [ 1 ] ;
V_1 -> V_30 . V_34 = V_18 -> V_30 ;
V_18 -> V_28 [ 0 ] = NULL ;
V_18 -> V_28 [ 1 ] = NULL ;
V_18 -> V_30 = NULL ;
}
F_7 ( L_7 , V_22 , V_21 ) ;
return V_21 ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_3 ( V_1 ) ;
if ( V_4 ) {
V_4 -> V_29 ( V_1 -> V_30 . V_34 ) ;
F_13 ( V_4 -> V_31 ) ;
V_1 -> V_28 . V_33 [ 0 ] = NULL ;
}
F_14 ( V_1 -> V_28 . V_33 [ 1 ] ) ;
V_1 -> V_28 . V_33 [ 1 ] = NULL ;
}
int F_18 ( struct V_19 * V_20 )
{
struct V_19 * V_35 ;
int V_21 ;
F_19 ( & V_25 ) ;
F_9 (cursor, &asymmetric_key_parsers, link) {
if ( strcmp ( V_35 -> V_12 , V_20 -> V_12 ) == 0 ) {
F_20 ( L_8 ,
V_20 -> V_12 ) ;
V_21 = - V_36 ;
goto V_37;
}
}
F_21 ( & V_20 -> V_38 , & V_39 ) ;
F_22 ( L_9 , V_20 -> V_12 ) ;
V_21 = 0 ;
V_37:
F_23 ( & V_25 ) ;
return V_21 ;
}
void F_24 ( struct V_19 * V_20 )
{
F_19 ( & V_25 ) ;
F_25 ( & V_20 -> V_38 ) ;
F_23 ( & V_25 ) ;
F_22 ( L_10 , V_20 -> V_12 ) ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_40 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_40 ) ;
}
