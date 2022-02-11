static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
unsigned int V_5 = V_6 ;
T_1 V_7 [ 2 ] ;
T_1 V_8 ;
T_2 V_9 ;
while ( V_5 -- ) {
V_8 = 0 ;
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_10 ;
V_7 [ 1 ] = 0x00 ;
F_3 ( V_2 -> V_11 , V_7 , 2 ) ;
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_12 ;
V_7 [ 1 ] = 0x00 ;
F_3 ( V_2 -> V_11 , V_7 , 2 ) ;
V_9 = F_4 ( V_2 -> V_11 , V_4 , V_13 + 1 ) ;
if ( V_9 == V_13 + 1 ) {
V_8 = F_5 ( V_4 , V_13 ) ;
if ( ( T_1 ) V_4 [ V_13 ] == V_8 )
return 0 ;
}
}
return - 1 ;
}
static int F_6 ( struct V_1 * V_2 , T_3 * V_14 )
{
unsigned int V_5 = V_6 ;
T_1 V_7 [ V_13 + 1 ] ;
unsigned int V_15 = V_16 ;
unsigned long V_17 ;
int V_18 ;
F_7 ( & V_2 -> V_11 -> V_19 ) ;
while ( V_5 -- ) {
if ( F_2 ( V_2 ) )
continue;
F_8 ( V_2 -> V_11 , V_20 ) ;
F_9 ( & V_2 -> V_11 -> V_19 ) ;
V_17 = F_10 ( V_15 ) ;
if ( V_17 != 0 ) {
V_18 = - 1 ;
goto V_21;
}
if ( F_11 ( & V_2 -> V_11 -> V_19 ) != 0 ) {
V_18 = - 1 ;
goto V_21;
}
break;
}
if ( F_1 ( V_2 , 0 , V_7 ) == 0 ) {
* V_14 = ( ( ( T_3 ) V_7 [ V_22 ] ) << 8 ) | ( ( V_23 ) V_7 [ V_24 ] ) ;
V_18 = 0 ;
} else
V_18 = - 1 ;
F_9 ( & V_2 -> V_11 -> V_19 ) ;
V_21:
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_26 )
{
unsigned int V_5 = V_6 ;
T_1 V_7 [ 3 ] ;
T_1 V_27 ;
int V_28 = 0 ;
while ( V_5 -- ) {
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_10 ;
V_7 [ 1 ] = 0x00 ;
F_3 ( V_2 -> V_11 , V_7 , 2 ) ;
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_12 ;
V_7 [ 1 ] = 0x00 ;
F_3 ( V_2 -> V_11 , V_7 , 2 ) ;
V_27 = F_13 ( V_2 -> V_11 ) ;
if ( V_26 )
V_26 = V_25 ;
if ( ( V_27 & V_25 ) == V_26 )
return 0 ;
else {
V_27 ^= V_25 ;
V_28 = 1 ;
}
break;
}
if ( V_28 ) {
V_5 = V_6 ;
while ( V_5 -- ) {
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_29 ;
V_7 [ 1 ] = 0x00 ;
V_7 [ 2 ] = V_27 ;
F_3 ( V_2 -> V_11 , V_7 , 3 ) ;
if ( F_2 ( V_2 ) )
continue;
V_7 [ 0 ] = V_30 ;
V_7 [ 1 ] = 0x00 ;
F_3 ( V_2 -> V_11 , V_7 , 2 ) ;
return 0 ;
}
}
return - 1 ;
}
static V_23 F_14 ( struct V_1 * V_2 ,
int V_31 , V_23 * V_32 )
{
unsigned int V_5 = V_6 ;
T_1 V_7 [ V_13 + 1 ] ;
unsigned int V_15 = V_16 ;
unsigned long V_17 ;
int V_18 ;
F_7 ( & V_2 -> V_11 -> V_19 ) ;
if ( F_12 ( V_2 , V_33 , V_31 ) ) {
V_18 = - 1 ;
goto V_34;
}
while ( V_5 -- ) {
if ( F_2 ( V_2 ) )
continue;
F_8 ( V_2 -> V_11 , V_35 ) ;
F_9 ( & V_2 -> V_11 -> V_19 ) ;
V_17 = F_10 ( V_15 ) ;
if ( V_17 != 0 ) {
V_18 = - 1 ;
goto V_21;
}
if ( F_11 ( & V_2 -> V_11 -> V_19 ) != 0 ) {
V_18 = - 1 ;
goto V_21;
}
break;
}
if ( F_1 ( V_2 , 0 , V_7 ) == 0 ) {
* V_32 = ( ( ( V_23 ) V_7 [ V_36 ] ) << 8 ) | ( ( V_23 ) V_7 [ V_37 ] ) ;
V_18 = 0 ;
} else
V_18 = - 1 ;
V_34:
F_9 ( & V_2 -> V_11 -> V_19 ) ;
V_21:
return V_18 ;
}
static T_4 F_15 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_4 ,
T_5 V_44 , T_2 V_9 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
int V_18 ;
if ( V_9 != 1 || V_44 != 0 )
return - V_45 ;
F_7 ( & V_2 -> V_11 -> V_19 ) ;
if ( F_12 ( V_2 , V_46 , * V_4 & 0x01 ) == 0 )
V_18 = 1 ;
else
V_18 = - V_47 ;
F_9 ( & V_2 -> V_11 -> V_19 ) ;
return V_18 ;
}
static T_4 F_17 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_4 ,
T_5 V_44 , T_2 V_9 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
int V_18 ;
T_1 V_7 [ V_13 + 1 ] ;
if ( V_44 != 0 )
return 0 ;
if ( ! V_4 )
return - V_48 ;
F_7 ( & V_2 -> V_11 -> V_19 ) ;
if ( F_1 ( V_2 , 0 , V_7 ) == 0 ) {
memcpy ( V_4 , & V_7 , V_13 ) ;
V_18 = V_13 ;
} else
V_18 = - V_47 ;
F_9 ( & V_2 -> V_11 -> V_19 ) ;
return V_18 ;
}
static T_4 F_18 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_4 ,
T_5 V_44 , T_2 V_9 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
int V_18 ;
T_4 V_49 = V_50 ;
T_3 V_51 ;
if ( V_44 != 0 )
return 0 ;
if ( ! V_4 )
return - V_48 ;
if ( F_6 ( V_2 , & V_51 ) == 0 ) {
V_49 -= snprintf ( V_4 + V_50 - V_49 , V_49 , L_1 , V_51 ) ;
V_18 = V_50 - V_49 ;
} else
V_18 = - V_47 ;
return V_18 ;
}
static T_4 F_19 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_4 ,
T_5 V_44 , T_2 V_9 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
int V_18 ;
T_4 V_49 = V_50 ;
V_23 V_32 ;
if ( V_44 != 0 )
return 0 ;
if ( ! V_4 )
return - V_48 ;
if ( F_14 ( V_2 , V_52 , & V_32 ) == 0 ) {
V_49 -= snprintf ( V_4 + V_50 - V_49 , V_49 , L_1 , V_32 ) ;
V_18 = V_50 - V_49 ;
} else
V_18 = - V_47 ;
return V_18 ;
}
static T_4 F_20 ( struct V_38 * V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_4 ,
T_5 V_44 , T_2 V_9 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
int V_18 ;
T_4 V_49 = V_50 ;
V_23 V_32 ;
if ( V_44 != 0 )
return 0 ;
if ( ! V_4 )
return - V_48 ;
if ( F_14 ( V_2 , V_53 , & V_32 ) == 0 ) {
V_49 -= snprintf ( V_4 + V_50 - V_49 , V_49 , L_1 , V_32 ) ;
V_18 = V_50 - V_49 ;
} else
V_18 = - V_47 ;
return V_18 ;
}
