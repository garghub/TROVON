static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_10 = F_2 ( V_7 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
if ( F_4 ( ! V_10 ) || ! V_12 )
continue;
V_6 += sprintf ( V_5 + V_6 , L_1 ,
V_12 -> V_13 , V_10 -> V_14 ,
V_12 -> V_15 ) ;
}
return V_6 ;
}
static int T_2 F_5 ( void )
{
int V_16 ;
V_16 = F_6 ( & V_17 , NULL ) ;
if ( F_4 ( V_16 ) )
return V_16 ;
return F_7 ( V_17 . V_18 , & V_19 . V_4 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_12 -> V_15 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_20 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
strcpy ( V_12 -> V_15 , V_5 ) ;
return V_20 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_20 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
unsigned long V_21 ;
V_21 = F_12 ( V_5 , NULL , 0 ) ;
F_13 ( V_12 -> V_22 , V_21 ) ;
return V_20 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_12 -> V_23 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_20 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
V_12 -> V_23 = F_12 ( V_5 , NULL , 0 ) ;
return V_20 ;
}
int F_16 ( struct V_11 * V_13 , struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_13 -> V_2 ;
char V_14 [ 16 ] ;
int V_16 ;
V_2 -> V_24 = V_13 -> V_22 ;
V_2 -> V_25 = & V_17 ;
V_16 = F_17 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 |= F_7 ( V_2 , & V_26 ) ;
V_16 |= F_7 ( V_2 , & V_27 ) ;
V_16 |= F_7 ( V_2 , & V_28 ) ;
V_16 |= F_7 ( V_2 , & V_29 ) ;
V_16 |= F_7 ( V_2 , & V_30 ) ;
if ( F_4 ( V_16 ) ) {
F_18 ( & V_10 -> V_31 -> V_2 , L_4 ) ;
return V_16 ;
}
snprintf ( V_14 , sizeof( V_14 ) , L_5 , V_13 -> V_13 ) ;
return F_19 ( & V_10 -> V_31 -> V_2 . V_32 , & V_2 -> V_32 , V_14 ) ;
}
void F_20 ( struct V_11 * V_13 , struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_13 -> V_2 ;
char V_14 [ 16 ] ;
F_21 ( V_2 , & V_26 ) ;
F_21 ( V_2 , & V_27 ) ;
F_21 ( V_2 , & V_28 ) ;
F_21 ( V_2 , & V_29 ) ;
F_21 ( V_2 , & V_30 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_5 , V_13 -> V_13 ) ;
F_22 ( & V_10 -> V_31 -> V_2 . V_32 , V_14 ) ;
F_23 ( V_2 ) ;
}
