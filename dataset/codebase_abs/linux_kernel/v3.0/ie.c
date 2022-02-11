struct V_1 * F_1 ( void * * V_2 , T_1 * V_3 )
{
struct V_1 * V_4 ;
T_1 V_5 ;
if ( * V_3 < sizeof( struct V_1 ) )
return NULL ;
V_4 = * V_2 ;
V_5 = sizeof( struct V_1 ) + V_4 -> V_6 ;
if ( * V_3 < V_5 )
return NULL ;
* V_2 += V_5 ;
* V_3 -= V_5 ;
return V_4 ;
}
int F_2 ( const struct V_1 * V_7 , T_1 V_3 ,
char * V_8 , T_1 V_9 )
{
void * V_2 ;
const struct V_1 * V_10 ;
int V_11 = 0 ;
T_2 * V_12 ;
V_2 = ( void * ) V_7 ;
for (; ; ) {
V_10 = F_1 ( & V_2 , & V_3 ) ;
if ( ! V_10 )
break;
V_11 += F_3 ( V_8 + V_11 , V_9 - V_11 , L_1 ,
( unsigned ) V_10 -> V_13 ,
( unsigned ) V_10 -> V_6 ) ;
V_12 = ( V_14 * ) V_10 + sizeof( struct V_1 ) ;
while ( V_12 != V_2 && V_11 < V_9 )
V_11 += F_3 ( V_8 + V_11 , V_9 - V_11 , L_2 , ( unsigned ) * V_12 ++ ) ;
if ( V_11 < V_9 )
V_8 [ V_11 ++ ] = '\n' ;
} ;
return V_11 ;
}
static
T_3 F_4 ( struct V_15 * V_15 , struct V_16 * * V_17 )
{
T_3 V_18 ;
struct V_19 * V_20 = & V_15 -> V_21 . V_20 ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 = NULL ;
struct V_16 * V_26 ;
V_23 = F_5 ( sizeof( * V_23 ) , V_27 ) ;
if ( V_23 == NULL )
return - V_28 ;
V_23 -> V_29 = V_30 ;
V_23 -> V_31 = F_6 ( V_32 ) ;
V_18 = F_7 ( V_15 , L_3 , V_23 , sizeof( * V_23 ) ,
V_30 , V_32 ,
& V_25 ) ;
F_8 ( V_23 ) ;
if ( V_18 < 0 )
return V_18 ;
V_26 = F_9 ( V_25 , struct V_16 , V_33 ) ;
if ( V_18 < sizeof( * V_26 ) ) {
F_10 ( V_20 , L_4
L_5 ,
V_18 , sizeof( * V_26 ) ) ;
return - V_34 ;
} else if ( V_18 < sizeof( * V_26 ) + F_11 ( V_26 -> V_35 ) ) {
F_10 ( V_20 , L_4
L_6 , V_18 ,
sizeof( * V_26 ) + F_11 ( V_26 -> V_35 ) ) ;
return - V_34 ;
}
* V_17 = V_26 ;
return V_18 ;
}
int F_12 ( struct V_15 * V_36 , struct V_37 * V_23 )
{
int V_18 ;
struct V_19 * V_20 = & V_36 -> V_21 . V_20 ;
struct V_38 V_25 ;
V_25 . V_33 . V_39 = V_30 ;
V_25 . V_33 . V_40 = V_41 ;
V_18 = F_13 ( V_36 , L_7 , & V_23 -> V_42 ,
sizeof( * V_23 ) + F_11 ( V_23 -> V_35 ) ,
& V_25 . V_33 , sizeof( V_25 ) ) ;
if ( V_18 < 0 )
goto V_43;
else if ( V_18 != sizeof( V_25 ) ) {
F_10 ( V_20 , L_8
L_9 ,
V_18 , sizeof( V_25 ) ) ;
V_18 = - V_44 ;
} else if ( V_25 . V_45 != V_46 ) {
F_10 ( V_20 , L_10 ,
F_14 ( V_25 . V_45 ) , V_25 . V_45 ) ;
V_18 = - V_44 ;
} else
V_18 = 0 ;
V_43:
return V_18 ;
}
void F_15 ( struct V_15 * V_15 )
{
F_16 ( & V_15 -> V_47 ) ;
}
int F_17 ( struct V_15 * V_15 )
{
struct V_16 * V_48 = NULL ;
int V_49 ;
V_49 = F_4 ( V_15 , & V_48 ) ;
if ( V_49 < 0 )
return V_49 ;
F_18 ( & V_15 -> V_47 ) ;
V_15 -> V_7 = (struct V_37 * ) V_48 ;
V_15 -> V_7 -> V_42 . V_29 = V_30 ;
V_15 -> V_7 -> V_42 . V_31 = F_6 ( V_41 ) ;
V_15 -> V_50 = V_49 ;
F_19 ( & V_15 -> V_47 ) ;
return 0 ;
}
void F_20 ( struct V_15 * V_15 )
{
F_8 ( V_15 -> V_7 ) ;
V_15 -> V_7 = NULL ;
V_15 -> V_50 = 0 ;
}
static int F_21 ( struct V_15 * V_36 , const struct V_1 * V_51 )
{
struct V_37 * V_52 ;
void * V_2 , * V_53 ;
struct V_1 * V_10 ;
T_1 V_6 , V_54 , V_55 , V_9 , V_56 ;
V_6 = F_11 ( V_36 -> V_7 -> V_35 ) ;
V_54 = sizeof( struct V_1 ) + V_51 -> V_6 ;
V_55 = sizeof( struct V_37 ) + V_6 + V_54 ;
if ( V_55 > V_36 -> V_50 ) {
V_52 = F_22 ( V_36 -> V_7 , V_55 , V_27 ) ;
if ( ! V_52 )
return - V_28 ;
V_36 -> V_7 = V_52 ;
}
V_2 = V_36 -> V_7 -> V_57 ;
V_9 = V_6 ;
for (; ; ) {
V_53 = V_2 ;
V_56 = V_9 ;
V_10 = F_1 ( & V_2 , & V_9 ) ;
if ( ! V_10 || V_10 -> V_13 > V_51 -> V_13 )
break;
}
memmove ( V_53 + V_54 , V_53 , V_56 ) ;
memcpy ( V_53 , V_51 , V_54 ) ;
V_36 -> V_7 -> V_35 = F_6 ( V_6 + V_54 ) ;
return 0 ;
}
int F_23 ( struct V_15 * V_15 ,
const struct V_1 * V_7 , T_1 V_9 )
{
int V_18 = 0 ;
void * V_2 ;
const struct V_1 * V_10 ;
F_18 ( & V_15 -> V_47 ) ;
V_2 = ( void * ) V_7 ;
for (; ; ) {
V_10 = F_1 ( & V_2 , & V_9 ) ;
if ( ! V_10 )
break;
V_18 = F_21 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 >= 0 ) {
if ( V_9 == 0 ) {
if ( V_15 -> V_58 != - 1 )
V_18 = F_12 ( V_15 , V_15 -> V_7 ) ;
} else
V_18 = - V_34 ;
}
F_19 ( & V_15 -> V_47 ) ;
return V_18 ;
}
static
void F_24 ( struct V_15 * V_15 , enum V_59 V_60 )
{
struct V_1 * V_10 ;
T_1 V_3 = F_11 ( V_15 -> V_7 -> V_35 ) ;
void * V_2 ;
T_1 V_9 ;
V_2 = V_15 -> V_7 -> V_57 ;
V_9 = V_3 ;
for (; ; ) {
V_10 = F_1 ( & V_2 , & V_9 ) ;
if ( ! V_10 )
break;
if ( V_10 -> V_13 == V_60 ) {
V_3 -= sizeof( struct V_1 ) + V_10 -> V_6 ;
memmove ( V_10 , V_2 , V_9 ) ;
V_2 = V_10 ;
}
}
V_15 -> V_7 -> V_35 = F_6 ( V_3 ) ;
}
int F_25 ( struct V_15 * V_15 , enum V_59 V_13 )
{
int V_18 = 0 ;
F_18 ( & V_15 -> V_47 ) ;
F_24 ( V_15 , V_13 ) ;
if ( V_15 -> V_58 != - 1 )
V_18 = F_12 ( V_15 , V_15 -> V_7 ) ;
F_19 ( & V_15 -> V_47 ) ;
return V_18 ;
}
