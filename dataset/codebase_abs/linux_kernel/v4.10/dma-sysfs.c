static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( F_4 ( ! V_9 ) || ! V_11 )
continue;
V_6 += sprintf ( V_5 + V_6 , L_1 ,
V_11 -> V_12 , V_9 -> V_13 ,
V_11 -> V_14 ) ;
}
return V_6 ;
}
static int T_2 F_5 ( void )
{
int V_15 ;
V_15 = F_6 ( & V_16 , NULL ) ;
if ( F_4 ( V_15 ) )
return V_15 ;
return F_7 ( V_16 . V_17 , & V_18 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_11 -> V_14 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_19 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
strcpy ( V_11 -> V_14 , V_5 ) ;
return V_19 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_19 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
unsigned long V_20 ;
V_20 = F_12 ( V_5 , NULL , 0 ) ;
F_13 ( V_11 -> V_21 , V_20 ) ;
return V_19 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_11 -> V_22 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_19 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
V_11 -> V_22 = F_12 ( V_5 , NULL , 0 ) ;
return V_19 ;
}
int F_16 ( struct V_10 * V_12 , struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_12 -> V_2 ;
char V_13 [ 16 ] ;
int V_15 ;
V_2 -> V_23 = V_12 -> V_21 ;
V_2 -> V_24 = & V_16 ;
V_15 = F_17 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_15 |= F_7 ( V_2 , & V_25 ) ;
V_15 |= F_7 ( V_2 , & V_26 ) ;
V_15 |= F_7 ( V_2 , & V_27 ) ;
V_15 |= F_7 ( V_2 , & V_28 ) ;
V_15 |= F_7 ( V_2 , & V_29 ) ;
if ( F_4 ( V_15 ) ) {
F_18 ( & V_9 -> V_30 -> V_2 , L_4 ) ;
return V_15 ;
}
snprintf ( V_13 , sizeof( V_13 ) , L_5 , V_12 -> V_12 ) ;
return F_19 ( & V_9 -> V_30 -> V_2 . V_31 , & V_2 -> V_31 , V_13 ) ;
}
void F_20 ( struct V_10 * V_12 , struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_12 -> V_2 ;
char V_13 [ 16 ] ;
F_21 ( V_2 , & V_25 ) ;
F_21 ( V_2 , & V_26 ) ;
F_21 ( V_2 , & V_27 ) ;
F_21 ( V_2 , & V_28 ) ;
F_21 ( V_2 , & V_29 ) ;
snprintf ( V_13 , sizeof( V_13 ) , L_5 , V_12 -> V_12 ) ;
F_22 ( & V_9 -> V_30 -> V_2 . V_31 , V_13 ) ;
F_23 ( V_2 ) ;
}
