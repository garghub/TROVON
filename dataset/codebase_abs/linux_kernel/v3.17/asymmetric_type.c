int F_1 ( const char * V_1 , const char * V_2 )
{
T_1 V_3 , V_4 ;
if ( ! V_1 || ! V_2 )
return 0 ;
if ( strncmp ( V_2 , L_1 , 3 ) == 0 )
V_2 += 3 ;
V_3 = strlen ( V_2 ) ;
V_4 = strlen ( V_1 ) ;
if ( V_3 > V_4 )
return 0 ;
V_1 += V_4 - V_3 ;
if ( strcasecmp ( V_2 , V_1 ) != 0 )
return 0 ;
return 1 ;
}
static int F_2 ( const struct V_5 * V_5 , const void * V_6 )
{
const struct V_7 * V_8 = V_7 ( V_5 ) ;
const char * V_9 = V_6 ;
const char * V_2 ;
T_2 V_10 ;
if ( ! V_8 || ! V_9 || ! * V_9 )
return 0 ;
if ( V_5 -> V_6 && strcmp ( V_5 -> V_6 , V_6 ) == 0 )
return 1 ;
V_2 = strchr ( V_9 , ':' ) ;
if ( ! V_2 )
return 0 ;
V_10 = V_2 - V_9 ;
V_2 ++ ;
if ( V_10 == 2 && memcmp ( V_9 , L_2 , 2 ) == 0 )
return F_1 ( F_3 ( V_5 ) , V_2 ) ;
if ( V_10 == V_8 -> V_11 &&
memcmp ( V_9 , V_8 -> V_12 , V_10 ) == 0 )
return 1 ;
return 0 ;
}
static void F_4 ( const struct V_5 * V_5 , struct V_13 * V_14 )
{
const struct V_7 * V_8 = V_7 ( V_5 ) ;
const char * V_1 = F_3 ( V_5 ) ;
T_1 V_15 ;
F_5 ( V_14 , V_5 -> V_6 ) ;
if ( V_8 ) {
F_5 ( V_14 , L_3 ) ;
V_8 -> V_16 ( V_5 , V_14 ) ;
if ( V_1 ) {
F_6 ( V_14 , ' ' ) ;
V_15 = strlen ( V_1 ) ;
if ( V_15 <= 8 )
F_5 ( V_14 , V_1 ) ;
else
F_5 ( V_14 , V_1 + V_15 - 8 ) ;
}
F_5 ( V_14 , L_4 ) ;
F_6 ( V_14 , ']' ) ;
}
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
F_8 ( L_5 , V_22 ) ;
if ( V_18 -> V_23 == 0 )
return - V_24 ;
F_9 ( & V_25 ) ;
V_21 = - V_26 ;
F_10 (parser, &asymmetric_key_parsers, link) {
F_11 ( L_6 , V_20 -> V_12 ) ;
V_21 = V_20 -> V_27 ( V_18 ) ;
if ( V_21 != - V_26 ) {
F_11 ( L_7 ,
V_21 ) ;
break;
}
}
F_12 ( & V_25 ) ;
F_8 ( L_8 , V_22 , V_21 ) ;
return V_21 ;
}
static void F_13 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = V_18 -> V_28 [ 0 ] ;
F_8 ( L_5 , V_22 ) ;
if ( V_8 ) {
V_8 -> V_29 ( V_18 -> V_30 [ 0 ] ) ;
F_14 ( V_8 -> V_31 ) ;
}
F_15 ( V_18 -> V_28 [ 1 ] ) ;
F_15 ( V_18 -> V_6 ) ;
}
static void F_16 ( struct V_5 * V_5 )
{
struct V_7 * V_8 = V_7 ( V_5 ) ;
if ( V_8 ) {
V_8 -> V_29 ( V_5 -> V_30 . V_32 ) ;
F_14 ( V_8 -> V_31 ) ;
V_5 -> V_28 . V_33 [ 0 ] = NULL ;
}
F_15 ( V_5 -> V_28 . V_33 [ 1 ] ) ;
V_5 -> V_28 . V_33 [ 1 ] = NULL ;
}
int F_17 ( struct V_19 * V_20 )
{
struct V_19 * V_34 ;
int V_21 ;
F_18 ( & V_25 ) ;
F_10 (cursor, &asymmetric_key_parsers, link) {
if ( strcmp ( V_34 -> V_12 , V_20 -> V_12 ) == 0 ) {
F_19 ( L_9 ,
V_20 -> V_12 ) ;
V_21 = - V_35 ;
goto V_36;
}
}
F_20 ( & V_20 -> V_37 , & V_38 ) ;
F_21 ( L_10 , V_20 -> V_12 ) ;
V_21 = 0 ;
V_36:
F_22 ( & V_25 ) ;
return V_21 ;
}
void F_23 ( struct V_19 * V_20 )
{
F_18 ( & V_25 ) ;
F_24 ( & V_20 -> V_37 ) ;
F_22 ( & V_25 ) ;
F_21 ( L_11 , V_20 -> V_12 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_39 ) ;
}
