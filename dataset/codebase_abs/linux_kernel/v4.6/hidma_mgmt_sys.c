static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
T_1 V_5 ;
int V_6 ;
if ( V_3 >= V_2 -> V_7 )
return - V_8 ;
V_5 = V_2 -> V_9 [ V_3 ] ;
V_2 -> V_9 [ V_3 ] = V_4 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
V_2 -> V_9 [ V_3 ] = V_5 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
T_1 V_5 ;
int V_6 ;
if ( V_3 >= V_2 -> V_7 )
return - V_8 ;
V_5 = V_2 -> V_10 [ V_3 ] ;
V_2 -> V_10 [ V_3 ] = V_4 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
V_2 -> V_10 [ V_3 ] = V_5 ;
return V_6 ;
}
static T_2 F_4 ( struct V_11 * V_12 , struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_5 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned int V_3 ;
V_15 [ 0 ] = 0 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_18 ) ; V_3 ++ ) {
if ( strcmp ( V_14 -> V_14 . V_19 , V_18 [ V_3 ] . V_19 ) == 0 ) {
sprintf ( V_15 , L_1 , V_18 [ V_3 ] . F_8 ( V_2 ) ) ;
break;
}
}
return strlen ( V_15 ) ;
}
static T_2 F_9 ( struct V_11 * V_12 , struct V_13 * V_14 ,
const char * V_15 , T_3 V_20 )
{
struct V_16 * V_17 = F_5 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned long V_5 ;
unsigned int V_3 ;
int V_6 ;
V_6 = F_10 ( V_15 , 0 , & V_5 ) ;
if ( V_6 )
return V_6 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_18 ) ; V_3 ++ ) {
if ( strcmp ( V_14 -> V_14 . V_19 , V_18 [ V_3 ] . V_19 ) == 0 ) {
V_6 = V_18 [ V_3 ] . F_11 ( V_2 , V_5 ) ;
if ( V_6 )
return V_6 ;
break;
}
}
return V_20 ;
}
static T_2 F_12 ( struct V_21 * V_22 ,
struct V_23 * V_14 , char * V_15 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_15 [ 0 ] = 0 ;
V_25 = F_13 ( V_14 , struct V_24 , V_14 ) ;
V_2 = V_25 -> V_2 ;
if ( strcmp ( V_14 -> V_14 . V_19 , L_2 ) == 0 )
sprintf ( V_15 , L_1 , V_2 -> V_9 [ V_25 -> V_26 ] ) ;
else if ( strcmp ( V_14 -> V_14 . V_19 , L_3 ) == 0 )
sprintf ( V_15 , L_1 , V_2 -> V_10 [ V_25 -> V_26 ] ) ;
return strlen ( V_15 ) ;
}
static T_2 F_14 ( struct V_21 * V_22 ,
struct V_23 * V_14 , const char * V_15 ,
T_3 V_20 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_6 ;
V_25 = F_13 ( V_14 , struct V_24 , V_14 ) ;
V_2 = V_25 -> V_2 ;
V_6 = F_10 ( V_15 , 0 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( strcmp ( V_14 -> V_14 . V_19 , L_2 ) == 0 ) {
V_6 = F_1 ( V_2 , V_25 -> V_26 , V_5 ) ;
if ( V_6 )
return V_6 ;
} else if ( strcmp ( V_14 -> V_14 . V_19 , L_3 ) == 0 ) {
V_6 = F_3 ( V_2 , V_25 -> V_26 , V_5 ) ;
if ( V_6 )
return V_6 ;
}
return V_20 ;
}
static int F_15 ( struct V_1 * V_12 , char * V_19 , int V_27 )
{
struct V_13 * V_28 ;
char * V_29 ;
V_28 = F_16 ( & V_12 -> V_17 -> V_12 ,
sizeof( struct V_13 ) , V_30 ) ;
if ( ! V_28 )
return - V_31 ;
V_29 = F_17 ( & V_12 -> V_17 -> V_12 , V_19 , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_28 -> V_14 . V_19 = V_29 ;
V_28 -> V_14 . V_27 = V_27 ;
V_28 -> V_32 = F_4 ;
V_28 -> V_33 = F_9 ;
F_18 ( & V_28 -> V_14 ) ;
return F_19 ( & V_12 -> V_17 -> V_12 , V_28 ) ;
}
static int F_20 ( struct V_1 * V_2 , char * V_19 ,
int V_27 , int V_26 ,
struct V_21 * V_34 )
{
struct V_24 * V_25 ;
char * V_29 ;
V_25 = F_16 ( & V_2 -> V_17 -> V_12 , sizeof( * V_25 ) , V_30 ) ;
if ( ! V_25 )
return - V_31 ;
V_29 = F_17 ( & V_2 -> V_17 -> V_12 , V_19 , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_25 -> V_2 = V_2 ;
V_25 -> V_26 = V_26 ;
V_25 -> V_14 . V_14 . V_19 = V_29 ;
V_25 -> V_14 . V_14 . V_27 = V_27 ;
V_25 -> V_14 . V_32 = F_12 ;
V_25 -> V_14 . V_33 = F_14 ;
F_18 ( & V_25 -> V_14 . V_14 ) ;
return F_21 ( V_34 , & V_25 -> V_14 . V_14 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_6 ;
int V_35 ;
struct V_21 * V_36 ;
V_35 = sizeof( * V_2 -> V_37 ) * V_2 -> V_7 ;
V_2 -> V_37 = F_16 ( & V_2 -> V_17 -> V_12 , V_35 , V_30 ) ;
if ( ! V_2 -> V_37 )
return - V_31 ;
V_36 = F_23 ( L_4 , & V_2 -> V_17 -> V_12 . V_22 ) ;
if ( ! V_36 )
return - V_31 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
char V_19 [ 20 ] ;
snprintf ( V_19 , sizeof( V_19 ) , L_5 , V_3 ) ;
V_2 -> V_37 [ V_3 ] = F_23 ( V_19 , V_36 ) ;
if ( ! V_2 -> V_37 [ V_3 ] )
return - V_31 ;
}
for ( V_3 = 0 ; V_3 < F_7 ( V_18 ) ; V_3 ++ ) {
V_6 = F_15 ( V_2 , V_18 [ V_3 ] . V_19 ,
V_18 [ V_3 ] . V_27 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_6 = F_20 ( V_2 , L_2 ,
( V_38 | V_39 ) , V_3 ,
V_2 -> V_37 [ V_3 ] ) ;
if ( V_6 )
return V_6 ;
V_6 = F_20 ( V_2 , L_3 ,
( V_38 | V_39 ) , V_3 ,
V_2 -> V_37 [ V_3 ] ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
