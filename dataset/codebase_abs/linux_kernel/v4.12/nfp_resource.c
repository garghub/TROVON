static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char V_5 [ V_6 ] = {} ;
struct V_7 V_8 ;
T_1 V_9 , V_10 ;
int V_11 , V_12 ;
V_9 = F_2 ( V_13 , 3 , 0 ) ;
strncpy ( V_5 , V_4 -> V_14 , sizeof( V_5 ) ) ;
if ( ! memcmp ( V_5 , V_15 L_1 , 8 ) ) {
F_3 ( V_2 , L_2 ) ;
return - V_16 ;
}
V_10 = F_4 ( V_5 , sizeof( V_5 ) ) ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
T_2 V_18 = V_19 +
sizeof( struct V_7 ) * V_12 ;
V_11 = F_5 ( V_2 , V_9 , V_18 , & V_8 , sizeof( V_8 ) ) ;
if ( V_11 != sizeof( V_8 ) )
return - V_20 ;
if ( V_8 . V_21 . V_10 != V_10 )
continue;
V_4 -> V_21 =
F_6 ( V_2 ,
V_13 , V_18 , V_10 ) ;
V_4 -> V_9 = F_2 ( V_8 . V_22 . V_23 ,
V_8 . V_22 . V_24 ,
V_8 . V_22 . V_25 ) ;
V_4 -> V_18 = ( T_2 ) V_8 . V_22 . V_26 << 8 ;
V_4 -> V_27 = ( T_2 ) V_8 . V_22 . V_28 << 8 ;
return 0 ;
}
return - V_29 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_32 ;
if ( F_8 ( V_31 ) )
return - V_33 ;
V_32 = F_1 ( V_2 , V_4 ) ;
if ( V_32 )
goto V_34;
V_32 = F_9 ( V_4 -> V_21 ) ;
if ( V_32 )
goto V_35;
F_10 ( V_31 ) ;
return 0 ;
V_35:
F_11 ( V_4 -> V_21 ) ;
V_34:
F_10 ( V_31 ) ;
return V_32 ;
}
struct V_3 *
F_12 ( struct V_1 * V_2 , const char * V_14 )
{
unsigned long V_36 = V_37 + 15 * V_38 ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_32 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 )
return F_14 ( - V_40 ) ;
strncpy ( V_4 -> V_14 , V_14 , V_6 ) ;
V_31 = F_6 ( V_2 , V_13 ,
V_19 ,
V_41 ) ;
if ( ! V_31 ) {
F_15 ( V_4 ) ;
return F_14 ( - V_40 ) ;
}
for (; ; ) {
V_32 = F_7 ( V_2 , V_4 , V_31 ) ;
if ( ! V_32 )
break;
if ( V_32 != - V_42 )
goto V_43;
V_32 = F_16 ( 1 ) ;
if ( V_32 != 0 ) {
V_32 = - V_44 ;
goto V_43;
}
if ( F_17 ( V_36 ) ) {
V_36 = V_37 + 60 * V_38 ;
F_18 ( V_2 , L_3 ,
V_14 ) ;
}
}
F_11 ( V_31 ) ;
return V_4 ;
V_43:
F_11 ( V_31 ) ;
F_15 ( V_4 ) ;
return F_14 ( V_32 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_21 ) ;
F_11 ( V_4 -> V_21 ) ;
F_15 ( V_4 ) ;
}
T_1 F_20 ( struct V_3 * V_4 )
{
return V_4 -> V_9 ;
}
const char * F_21 ( struct V_3 * V_4 )
{
return V_4 -> V_14 ;
}
T_2 F_22 ( struct V_3 * V_4 )
{
return V_4 -> V_18 ;
}
T_2 F_23 ( struct V_3 * V_4 )
{
return V_4 -> V_27 ;
}
