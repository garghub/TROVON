bool F_1 ( struct V_1 V_2 , struct V_1 V_3 )
{
if ( V_2 . type != V_3 . type )
return false ;
switch( V_2 . type ) {
case V_4 :
return F_2 ( V_2 . V_5 , V_3 . V_5 ) ;
case V_6 :
return F_3 ( V_2 . V_7 , V_3 . V_7 ) ;
case V_8 :
return F_4 ( V_2 . V_9 , V_3 . V_9 ) ;
default:
F_5 () ;
}
}
bool F_6 ( struct V_1 V_2 , struct V_1 V_3 )
{
if ( V_2 . type < V_3 . type )
return true ;
if ( V_2 . type > V_3 . type )
return false ;
switch ( V_2 . type ) {
case V_4 :
return F_7 ( V_2 . V_5 , V_3 . V_5 ) ;
case V_6 :
return F_8 ( V_2 . V_7 , V_3 . V_7 ) ;
case V_8 :
return F_9 ( V_2 . V_9 , V_3 . V_9 ) ;
default:
F_5 () ;
}
}
T_1 F_10 ( struct V_10 * V_11 , struct V_1 V_1 )
{
switch ( V_1 . type ) {
case V_4 :
return F_11 ( V_11 , V_1 . V_5 ) ;
case V_6 :
return F_12 ( V_11 , V_1 . V_7 ) ;
case V_8 :
return F_13 ( V_11 , V_1 . V_9 ) ;
default:
F_5 () ;
}
}
T_1 F_14 ( struct V_10 * V_11 , struct V_1 V_1 )
{
switch ( V_1 . type ) {
case V_4 :
return F_15 ( V_11 , V_1 . V_5 ) ;
case V_6 :
return F_16 ( V_11 , V_1 . V_7 ) ;
case V_8 :
return F_17 ( V_11 , V_1 . V_9 ) ;
default:
F_5 () ;
}
}
bool F_18 ( struct V_1 V_12 )
{
switch ( V_12 . type ) {
case V_4 :
return F_19 ( V_12 . V_5 ) ;
case V_6 :
return F_20 ( V_12 . V_7 ) ;
case V_8 :
return F_21 ( V_12 . V_9 ) ;
default:
F_5 () ;
}
}
