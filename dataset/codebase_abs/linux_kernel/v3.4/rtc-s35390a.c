static int F_1 ( struct V_1 * V_1 , int V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 [ V_2 ] ;
struct V_7 V_8 [] = {
{ V_6 -> V_9 , 0 , V_4 , V_3 } ,
} ;
if ( ( F_2 ( V_6 -> V_10 , V_8 , 1 ) ) != 1 )
return - V_11 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 -> V_6 [ V_2 ] ;
struct V_7 V_8 [] = {
{ V_6 -> V_9 , V_12 , V_4 , V_3 } ,
} ;
if ( ( F_2 ( V_6 -> V_10 , V_8 , 1 ) ) != 1 )
return - V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 )
{
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_13 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & ( V_14 | V_15 ) ) )
return 0 ;
V_3 [ 0 ] |= ( V_16 | V_17 ) ;
V_3 [ 0 ] &= 0xf0 ;
return F_1 ( V_1 , V_13 , V_3 , sizeof( V_3 ) ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
char V_3 [ 1 ] ;
if ( F_3 ( V_1 , V_18 , V_3 , sizeof( V_3 ) ) < 0 )
return - V_11 ;
if ( ! ( V_3 [ 0 ] & V_19 ) )
return 0 ;
V_3 [ 0 ] &= ~ V_19 ;
return F_1 ( V_1 , V_18 , V_3 , sizeof( V_3 ) ) ;
}
static char F_6 ( struct V_1 * V_1 , int V_20 )
{
if ( V_1 -> V_21 )
return F_7 ( V_20 ) ;
if ( V_20 < 12 )
return F_7 ( V_20 ) ;
return 0x40 | F_7 ( V_20 - 12 ) ;
}
static int F_8 ( struct V_1 * V_1 , char V_2 )
{
unsigned V_20 ;
if ( V_1 -> V_21 )
return F_9 ( V_2 & 0x3f ) ;
V_20 = F_9 ( V_2 & 0x3f ) ;
if ( V_2 & 0x40 )
V_20 += 12 ;
return V_20 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
int V_24 , V_25 ;
char V_3 [ 7 ] ;
F_12 ( & V_6 -> V_26 , L_1
L_2 , V_27 , V_23 -> V_28 ,
V_23 -> V_29 , V_23 -> V_30 , V_23 -> V_31 , V_23 -> V_32 , V_23 -> V_33 ,
V_23 -> V_34 ) ;
V_3 [ V_35 ] = F_7 ( V_23 -> V_33 - 100 ) ;
V_3 [ V_36 ] = F_7 ( V_23 -> V_32 + 1 ) ;
V_3 [ V_37 ] = F_7 ( V_23 -> V_31 ) ;
V_3 [ V_38 ] = F_7 ( V_23 -> V_34 ) ;
V_3 [ V_39 ] = F_6 ( V_1 , V_23 -> V_30 ) ;
V_3 [ V_40 ] = F_7 ( V_23 -> V_29 ) ;
V_3 [ V_41 ] = F_7 ( V_23 -> V_28 ) ;
for ( V_24 = 0 ; V_24 < 7 ; ++ V_24 )
V_3 [ V_24 ] = F_13 ( V_3 [ V_24 ] ) ;
V_25 = F_1 ( V_1 , V_42 , V_3 , sizeof( V_3 ) ) ;
return V_25 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
char V_3 [ 7 ] ;
int V_24 , V_25 ;
V_25 = F_3 ( V_1 , V_42 , V_3 , sizeof( V_3 ) ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_24 = 0 ; V_24 < 7 ; ++ V_24 )
V_3 [ V_24 ] = F_13 ( V_3 [ V_24 ] ) ;
V_23 -> V_28 = F_9 ( V_3 [ V_41 ] ) ;
V_23 -> V_29 = F_9 ( V_3 [ V_40 ] ) ;
V_23 -> V_30 = F_8 ( V_1 , V_3 [ V_39 ] ) ;
V_23 -> V_34 = F_9 ( V_3 [ V_38 ] ) ;
V_23 -> V_31 = F_9 ( V_3 [ V_37 ] ) ;
V_23 -> V_32 = F_9 ( V_3 [ V_36 ] ) - 1 ;
V_23 -> V_33 = F_9 ( V_3 [ V_35 ] ) + 100 ;
F_12 ( & V_6 -> V_26 , L_3
L_2 , V_27 , V_23 -> V_28 ,
V_23 -> V_29 , V_23 -> V_30 , V_23 -> V_31 , V_23 -> V_32 , V_23 -> V_33 ,
V_23 -> V_34 ) ;
return F_15 ( V_23 ) ;
}
static int F_16 ( struct V_43 * V_26 , struct V_22 * V_23 )
{
return F_14 ( F_17 ( V_26 ) , V_23 ) ;
}
static int F_18 ( struct V_43 * V_26 , struct V_22 * V_23 )
{
return F_10 ( F_17 ( V_26 ) , V_23 ) ;
}
static int F_19 ( struct V_5 * V_6 ,
const struct V_44 * V_45 )
{
int V_25 ;
unsigned int V_24 ;
struct V_1 * V_1 ;
struct V_22 V_23 ;
char V_3 [ 1 ] ;
if ( ! F_20 ( V_6 -> V_10 , V_46 ) ) {
V_25 = - V_47 ;
goto exit;
}
V_1 = F_21 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_1 ) {
V_25 = - V_49 ;
goto exit;
}
V_1 -> V_6 [ 0 ] = V_6 ;
F_22 ( V_6 , V_1 ) ;
for ( V_24 = 1 ; V_24 < 8 ; ++ V_24 ) {
V_1 -> V_6 [ V_24 ] = F_23 ( V_6 -> V_10 ,
V_6 -> V_9 + V_24 ) ;
if ( ! V_1 -> V_6 [ V_24 ] ) {
F_24 ( & V_6 -> V_26 , L_4 ,
V_6 -> V_9 + V_24 ) ;
V_25 = - V_50 ;
goto V_51;
}
}
V_25 = F_4 ( V_1 ) ;
if ( V_25 < 0 ) {
F_24 ( & V_6 -> V_26 , L_5 ) ;
goto V_51;
}
V_25 = F_5 ( V_1 ) ;
if ( V_25 < 0 ) {
F_24 ( & V_6 -> V_26 , L_6 ) ;
goto V_51;
}
V_25 = F_3 ( V_1 , V_13 , V_3 , sizeof( V_3 ) ) ;
if ( V_25 < 0 ) {
F_24 ( & V_6 -> V_26 , L_7 ) ;
goto V_51;
}
if ( V_3 [ 0 ] & V_17 )
V_1 -> V_21 = 1 ;
else
V_1 -> V_21 = 0 ;
if ( F_14 ( V_6 , & V_23 ) < 0 )
F_25 ( & V_6 -> V_26 , L_8 ) ;
V_1 -> V_52 = F_26 ( V_53 . V_54 . V_55 ,
& V_6 -> V_26 , & V_56 , V_57 ) ;
if ( F_27 ( V_1 -> V_52 ) ) {
V_25 = F_28 ( V_1 -> V_52 ) ;
goto V_51;
}
return 0 ;
V_51:
for ( V_24 = 1 ; V_24 < 8 ; ++ V_24 )
if ( V_1 -> V_6 [ V_24 ] )
F_29 ( V_1 -> V_6 [ V_24 ] ) ;
F_30 ( V_1 ) ;
exit:
return V_25 ;
}
static int F_31 ( struct V_5 * V_6 )
{
unsigned int V_24 ;
struct V_1 * V_1 = F_11 ( V_6 ) ;
for ( V_24 = 1 ; V_24 < 8 ; ++ V_24 )
if ( V_1 -> V_6 [ V_24 ] )
F_29 ( V_1 -> V_6 [ V_24 ] ) ;
F_32 ( V_1 -> V_52 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
